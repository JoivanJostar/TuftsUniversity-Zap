/*
* this file is the interface definition of PhaseOne's 3 functions
*/
#ifndef __PHASEONE_H__
#define __PHASEONE_H__
#include "HuffmanTreeNode.h"
#include <iostream>
#include <string>
void count_freqs(std::istream& text);
std::string serialize_tree(HuffmanTreeNode* root);
HuffmanTreeNode* deserialize_tree(std::string serial_tree);
#endif // !__PHASEONE_H__


