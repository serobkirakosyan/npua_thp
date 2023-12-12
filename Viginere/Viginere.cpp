#include "Viginere.h"

ViginereMachine::ViginereMachine(const std::string& key) : m_key(key) {}

std::string ViginereMachine::encode(const std::string& plaintext) const {
    const size_t sizeOfAlphabet = 255;
    const size_t lenOfText = plaintext.size();
    const size_t lenOfKey = m_key.size();
    std::string encoded;
    for (size_t i = 0; i < lenOfText; ++i) {
        char character = plaintext[i];
        char key_char = m_key[i % lenOfKey];
        char encrypted_char = (character + key_char) % sizeOfAlphabet;
        encoded += encrypted_char;
    }
    return encoded;
}

std::string ViginereMachine::decode(const std::string& ciphertext) const {
    const size_t sizeOfAlphabet = 255;
    const size_t lenOfText = ciphertext.size();
    const size_t lenOfKey = m_key.size();
    std::string decoded;
    for (size_t i = 0; i < lenOfText; ++i) {
        char character = ciphertext[i];
        char key_char = m_key[i % lenOfKey];
        char decrypted_char = (character - key_char + sizeOfAlphabet) % sizeOfAlphabet;
        decoded += decrypted_char;
    }
    return decoded;
}
