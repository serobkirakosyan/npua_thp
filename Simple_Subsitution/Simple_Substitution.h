#ifndef SIMPLESUB_H
#define SIMPLESUB_H

#include "../RLE/CipherMachine.h"
#include <string>

class SimpleSubstitutionMachine : public CipherMachine {
public:
    SimpleSubstitutionMachine(const std::string&);
    const std::string& getKey() const;
    static const std::string& getAlphabet();

private:
    static const std::string alphabet;
    std::string key;
    void generateKey(const std::string&);
    virtual std::string encode(const std::string&) const override;
    virtual std::string decode(const std::string&) const override;
    void algorithm(std::string&, const std::string&, const std::string&) const;
};

#endif
