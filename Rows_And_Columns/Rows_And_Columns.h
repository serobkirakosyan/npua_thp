#ifndef ROWS_N_COLS_H
#define ROWS_N_COLS_H

#include "../RLE/CipherMachine.h"
#include <string>

class RowsAndColsMachine : public CipherMachine {
public:
    RowsAndColsMachine(int);
    int getKey() const;
private:
    int m_key;
    virtual std::string encode(const std::string&) const override;
    virtual std::string decode(const std::string&) const override;
    void algorithm(std::string&, int) const;
};

#endif
