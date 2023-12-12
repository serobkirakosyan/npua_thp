#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

#include "TreeNode.h"
#include <string>
#include <unordered_map>

class HuffmanTree{
public:
using frequencyTable = std::unordered_map<char, int>;
    ~HuffmanTree();

    void buildTree(const std::string&);
    void printTree() const;
private:
    TreeNode* m_root{nullptr};
    frequencyTable createTable(const std::string&) const;
    void helpDestruct(TreeNode*);
    void helpPrint(TreeNode* root, int spaces) const;
    struct greaterFrequency{
        bool operator()(TreeNode* lhs, TreeNode* rhs) const{
            return ((lhs->getFrequency()) > (rhs->getFrequency()));
        }
    };
};
#endif
