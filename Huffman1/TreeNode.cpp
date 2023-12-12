#include "TreeNode.h"

TreeNode::TreeNode(char symbol, int frequency) : m_symbol{symbol}, m_frequency{frequency}, m_left{nullptr}, m_right{nullptr} {}

char TreeNode::getSymbol() const {
    return m_symbol;
}

int TreeNode::getFrequency() const {
    return m_frequency;
}
