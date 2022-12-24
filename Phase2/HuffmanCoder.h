/*
* this file is the interface definition of class HuffmanCoder
*/
#ifndef __HUFFMANCODER_H__
#define __HUFFMANCODER_H__
#include <string>
#include <map>
#include "HuffmanTreeNode.h"
class HuffmanCoder
{
public:
	void encoder(std::string input_file, std::string output_file);
	void decoder(std::string input_file, std::string output_file);
private:
	void count_freqs(std::istream& text);
	HuffmanTreeNode* buildTree();
	void generateCodeMap(HuffmanTreeNode* root);
	void generateCodeMapHelper(HuffmanTreeNode* root, std::string prefix);
	std::string serialize_tree(HuffmanTreeNode* root);
	HuffmanTreeNode* deserialize_tree(std::string serial_tree);
	HuffmanTreeNode* deserialize_tree_helper(std::string& serial_tree);
	void freeTreeMemory(HuffmanTreeNode* root);
	//a map that records the frequcy of each character
	std::map<char, int> freqsCountsMap;
	//a map that records the 01 bitsString of each character
	//for looking up when encode a character.
	std::map<char, std::string> codeMap;
};

#endif // !__HUFFMANCODER_H__



