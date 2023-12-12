#include "RowsAndColumns.h"
#include <vector>
#include <cmath>

using namespace std;

RowsAndColsMachine::RowsAndColsMachine(int key) : m_key{key} {}

int RowsAndColsMachine::getKey() const {
    return m_key;
}

string RowsAndColsMachine::encode(const string& plaintext) const {
    string txt{plaintext};
    algorithm(txt, m_key);
    return txt;
}

string RowsAndColsMachine::decode(const string& ciphertext) const {
    string txt{ciphertext};
    algorithm(txt, static_cast<int>(ceil(static_cast<double>(ciphertext.length()) / m_key)));
    return txt;
}

void RowsAndColsMachine::algorithm(string& plaintext, int key) const {
    int len = plaintext.length();
    int rows = key;
    int cols = static_cast<int>(ceil(static_cast<double>(len) / rows));
    vector<vector<char>> matrix(rows, vector<char>(cols, ' '));
    int c = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (c < len) {
                matrix[i][j] = plaintext[c];
                ++c;
            }
        }
    }
    c = 0;
    for (int i = 0; i < cols; ++i) {
        for (int j = 0; j < rows; ++j) {
            if (c < len) {
                plaintext[c] = matrix[j][i];
                ++c;
            }
        }
    }
}
