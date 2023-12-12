#include <iostream>
#include <string>
#include "HuffmanTree.h"

using namespace std;

int main(){
    HuffmanTree hTree;
    string text{"Simple text"};
    hTree.buildTree(text);
    hTree.printTree();
}
