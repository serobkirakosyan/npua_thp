#include <iostream>
#include <string>
#include <cstdint>
#include <vector>

uint32_t roundFunction(uint32_t right, uint64_t key) {
    return right ^ static_cast<uint32_t>(key);
}

uint64_t feistelEncryption(uint64_t block, uint64_t key) {
    uint32_t left = block >> 32;
    uint32_t right = static_cast<uint32_t>(block);
    const int rounds{16};
    for (int round = 0; round < rounds; ++round) {
        uint32_t temp = left;
        left = right;
        right = temp ^ roundFunction(right, key);
    }
    block = (static_cast<uint64_t>(right) << 32) | left;
    return block;
}

uint64_t feistelDecryption(uint64_t block, uint64_t key) {
    uint32_t left = block >> 32;
    uint32_t right = static_cast<uint32_t>(block);
    const int rounds{16};
    for (int round = 0; round < rounds; ++round) {
        uint32_t temp = left;
        left = right;
        right = temp ^ roundFunction(right, key);
    }
    block = (static_cast<uint64_t>(right) << 32) | left;
    return block;
}

std::vector<uint64_t> textToBlocks(const std::string& txt) {
    std::string paddedText = txt;
    while (paddedText.size() % 8 != 0) {
        paddedText.push_back('\0');
    }
    std::vector<uint64_t> blocks;
    for (size_t i = 0; i < paddedText.size(); i += 8) {
        uint64_t block = 0;
        for (int j = 0; j < 8; ++j) {
            block |= static_cast<uint64_t>(paddedText[i + j]) << (8 * j);
        }
        blocks.push_back(block);
    }
    return blocks;
}

std::string blocksToText(const std::vector<uint64_t>& blocks) {
    std::string text;
    for (uint64_t block : blocks) {
        for (int j = 0; j < 8; ++j) {
            text.push_back(static_cast<char>(block >> (8 * j)));
        }
    }
    return text;
}

int main() {
    std::string plaintext{"The quick brown fox jumps over the lazy dog."};
    uint64_t key{0xaff0f0f0faf0f0fd};
    auto blocks = textToBlocks(plaintext);
    for (auto& block : blocks) {
        block = feistelEncryption(block, key);
    }
    std::string encryptedText = blocksToText(blocks);
    for (auto& block : blocks) {
        block = feistelDecryption(block, key);
    }
    std::string decryptedText = blocksToText(blocks);
    std::cout << "Original Text:       " << plaintext << "\n"
              << "Encrypted Text:      " << encryptedText << "\n"
              << "Decrypted Text:      " << decryptedText << "\n";
    return 0;
}
