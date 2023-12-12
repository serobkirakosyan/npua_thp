#include "HuffmanTree.h"
#include <string>
#include <queue>
#include <iostream>
#include <iomanip>

HuffmanTree::frequencyTable HuffmanTree::createTable(const std::string& txt) const{
    HuffmanTree::frequencyTable table;
    for(char c : txt){
        table[c] += 1;
    }

    return table;
}


void HuffmanTree::buildTree(const std::string& txt){
    HuffmanTree::frequencyTable fTable = createTable(txt);
    std::priority_queue<TreeNode*, std::vector<TreeNode*>, HuffmanTree::greaterFrequency> pq;
    for(auto pair : fTable){
        TreeNode* newNode = new TreeNode(pair.first, pair.second);
        pq.push(newNode);
    }

    while(pq.size() > 1){
        TreeNode* left{pq.top()};
        pq.pop();
        TreeNode* right{pq.top()};
        pq.pop();
        TreeNode* newNode = new TreeNode('#', left->getFrequency() + right->getFrequency());
        newNode->m_left = left;
        newNode->m_right = right;
        pq.push(newNode);
    }

    m_root = pq.top();
}

void HuffmanTree::printTree() const{
    helpPrint(m_root, 0);
}

void HuffmanTree::helpPrint(TreeNode* root, int spaces) const{
    if(root == nullptr) return;
    spaces += 10;

    helpPrint(root->m_right, spaces);

    std::cout <<'\n';
    
    std::cout <<std::setw(spaces)<<std::right<<root->getSymbol() <<':'<<root->getFrequency()<<'\n';

    helpPrint(root->m_left, spaces);
}

HuffmanTree::~HuffmanTree(){
    helpDestruct(m_root);
}

void HuffmanTree::helpDestruct(TreeNode* root){
    if(root != nullptr){
        helpDestruct(root->m_left);
        helpDestruct(root->m_right);
        delete root;
    }
}
