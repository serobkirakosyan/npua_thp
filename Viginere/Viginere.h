#ifndef VIGINERE_H
#define VIGINERE_H

#include "../RLE/CipherMachine.h"
#include <string>

class ViginereMachine : public CipherMachine {
public:
    ViginereMachine(const std::string&);
private:
    std::string m_key;
    virtual std::string encode(const std::string&) const override;
    virtual std::string decode(const std::string&) const override;
};

#endif
