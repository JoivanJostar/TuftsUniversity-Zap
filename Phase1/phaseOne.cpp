/*
* this file is the implemation of phaseOne.h
*/
#include "phaseOne.h"
#include <map>
using namespace std;
HuffmanTreeNode* deserialize_tree_helper(std::string& serial_tree);

void count_freqs(std::istream& text) {
	char c;
	map<char, int> counts;
	//count the frequency of each character
	while (!text.fail()) {
		text.get(c);
		if (text.fail())
			continue;
		counts[c]++;
	}

	//print the freq of each character
	for (map<char, int>::iterator it = counts.begin(); it != counts.end(); ++it) {
		c = (*it).first;
		int freq = (*it).second;
		cout << c << ": " << freq << endl;
	}
}
std::string serialize_tree(HuffmanTreeNode* root) {
	//root should not NULL here!
	if (root == NULL) {
		return "";
	}
	//example:  "IIILaLbILeLfILcLd";
	if (root->isLeaf()) {
		string ret = "L";
		ret.append(1,root->get_val());
		//"Lc"
		return ret;
	}
	else {
		HuffmanTreeNode* left = root->get_left();
		HuffmanTreeNode* right = root->get_right();
		return "I" + serialize_tree(left) + serialize_tree(right);
	}
}

HuffmanTreeNode* deserialize_tree_helper(std::string& serial_tree) {
	//example:  "IIILaLbILeLfILcLd";
	if (serial_tree.empty())
		return NULL;
	//get present first char and pop it
	char c = serial_tree[0];
	serial_tree.erase(0,1);

	if (c == 'I') {
		HuffmanTreeNode* p = new HuffmanTreeNode(0, 0, NULL, NULL);
		HuffmanTreeNode* left = deserialize_tree_helper(serial_tree);
		HuffmanTreeNode* right = deserialize_tree_helper(serial_tree);
		p->set_left(left);
		p->set_right(right);
		return p;
	}
	else if (c == 'L') {
		//get the leaf val
		if(serial_tree.empty())
			throw runtime_error("Wrong Haffman String Tree");
		char val = serial_tree[0];
		serial_tree.erase(0,1);
		return new HuffmanTreeNode(val, 0, NULL, NULL);
	}
	else {
		throw runtime_error("Wrong Haffman String Tree");
	}
}

HuffmanTreeNode* deserialize_tree(std::string serial_tree) {
	if (serial_tree.empty())
		return NULL;
	string serial_tree_bak = serial_tree;
	return deserialize_tree_helper(serial_tree_bak);
}

