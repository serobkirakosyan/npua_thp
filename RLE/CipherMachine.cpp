#include "CipherMachine.h"

std::string CipherMachine::execute(const std::string& text, CipherMachine::Operation op) {
    switch (op) {
        case Operation::ENCODE:
            return encode(text);
        case Operation::DECODE:
            return decode(text);
        default:
            return ""; // Unknown operation
    }
}
