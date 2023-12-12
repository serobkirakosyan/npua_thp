#ifndef RLE_H
#define RLE_H

#include "CipherMachine.h"
#include <string>

class RLEMachine : public CipherMachine {
public:
    virtual std::string encode(const std::string&) const override;
    virtual std::string decode(const std::string&) const override;
};

#endif
