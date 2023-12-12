#include "RLE.h"
#include <sstream>

std::string RLEMachine::encode(const std::string& input) const {
    std::ostringstream compressed;
    size_t length = input.length();
    for (size_t i = 0; i < length; i++) {
        char currentChar = input[i];
        size_t count = 1;
        while (i + 1 < length && input[i + 1] == currentChar) {
            count++;
            i++;
        }

        compressed << currentChar << count;
    }
    return compressed.str();
}

std::string RLEMachine::decode(const std::string& input) const {
    std::string decompressed;
    size_t length = input.size();
    size_t i = 0;
    while (i < length) {
        char current = input[i++];
        size_t count = 0;

        while (isdigit(input[i])) {
            count = 10 * count + (input[i++] - '0');
        }

        decompressed.append(count, current);
    }
    return decompressed;
}
