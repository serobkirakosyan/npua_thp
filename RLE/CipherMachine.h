#ifndef MACHINE_H
#define MACHINE_H

#include <string>

class CipherMachine {
public:
    enum class Operation : char {
        ENCODE,
        DECODE
    };
    std::string execute(const std::string&, Operation);

protected:
    virtual std::string encode(const std::string&) const = 0;
    virtual std::string decode(const std::string&) const = 0;
};

#endif
