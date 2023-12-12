#include "RLE2.h"
#include <sstream>
#include <vector>

std::string RLE2Machine::encode(const std::string& txt) const {
    std::ostringstream res;
    size_t len = txt.size();
    size_t i = 0;
    while (i < len - 1) {
        size_t start = i;
        bool repetitive = false;
        if (txt[i + 1] == txt[start]) {
            repetitive = true;
            while (i < len && txt[i] == txt[start]) {
                ++i;
            }
        } else {
            if (txt[i + 1] != txt[i]) {
                while (i < len - 1 && txt[i] != txt[i + 1]) {
                    ++i;
                }
            }
        }
        size_t count = i - start;
        if (repetitive) {
            count |= 0x80;
            res.put(static_cast<char>(count));
            res.put(txt[start]);
        } else {
            res.put(static_cast<char>(count));
            res.write(&txt[start], count);
        }
    }

    return res.str();
}

std::string RLE2Machine::decode(const std::string& compressed) const {
    std::ostringstream decompressed;
    size_t len = compressed.size();
    size_t i = 0;
    while (i < len) {
        size_t count = static_cast<unsigned char>(compressed[i]);
        char c = compressed[i + 1];
        bool repetitive = count & 0x80;

        if (repetitive) {
            count ^= 0x80;
            decompressed.write(&c, 1);
            decompressed.write(&c, count);
            i += 2;
        } else {
            decompressed.write(&c, count);
            i += count + 1;
        }
    }
    return decompressed.str();
}
