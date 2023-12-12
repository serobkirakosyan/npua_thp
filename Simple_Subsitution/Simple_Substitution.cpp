#include "SimpleSubstitution.h"
#include <algorithm>

using namespace std;

const std::string SimpleSubstitutionMachine::alphabet{"abcdefghijklmnopqrstuvwxyz"};

SimpleSubstitutionMachine::SimpleSubstitutionMachine(const std::string& word) {
    generateKey(word);
}

const std::string& SimpleSubstitutionMachine::getKey() const {
    return key;
}

const std::string& SimpleSubstitutionMachine::getAlphabet() {
    return alphabet;
}

void SimpleSubstitutionMachine::generateKey(const std::string& word) {
    key.clear();
    for (char c : word) {
        c = tolower(c);
        if (isalpha(c) && key.find(c) == std::string::npos) {
            key.push_back(c);
        }
    }
    if (26 != key.length()) {
        for (char c : alphabet) {
            if (key.find(c) == std::string::npos) {
                key.push_back(c);
            }
        }
    }
}

void SimpleSubstitutionMachine::algorithm(std::string& text, const std::string& letters, const std::string& substitutions) const {
    for (char& c : text) {
        if (isalpha(c)) {
            auto pos = letters.find(c);
            if (pos != std::string::npos) {
                c = substitutions[pos];
            }
        }
    }
}

std::string SimpleSubstitutionMachine::encode(const std::string& plaintext) const {
    std::string text{plaintext};
    algorithm(text, alphabet, key);
    return text;
}

std::string SimpleSubstitutionMachine::decode(const std::string& ciphertext) const {
    std::string text{ciphertext};
    algorithm(text, key, alphabet);
    return text;
}
