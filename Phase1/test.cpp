/*
* this file is the test file for phaseOne and BinaryIO , HuffmanTreeNode
* this file has a main() function ,so it can be complied and run
*/

#include <iostream>
#include <string>
#include <fstream>
#include <assert.h>
#include "HuffmanTreeNode.h"
#include "BinaryIO.h"
#include "phaseOne.h"
#include <sstream>
void freeTreeMemory(HuffmanTreeNode* root);
void freeTreeMemory(HuffmanTreeNode* root) {
	if (root == NULL)
		return;
	freeTreeMemory(root->get_left());
	freeTreeMemory(root->get_right());
	delete root;
}
void testTreeNode() {
	HuffmanTreeNode node1('a', 32);
	HuffmanTreeNode node2('b', 10);
	HuffmanTreeNode node3('c',20, &node1, &node2);
	assert(node3.get_freq() == 20);
	assert(node3.get_val() == 'c');
	assert(node3.isLeaf() == false);
	assert(node3.get_left()==&node1);
	assert(node3.get_right() == &node2);
	node3.set_right(&node1);
	assert(node3.get_right() == &node1);
	assert(node1.isLeaf() == true);
	std::cout << "testTreeNode pass" << std::endl;
}
void testBinaryWrite() {
	std::string strTree = "IIILaLbILeLfILcLd";
	BinaryIO io;
	std::string bitsString = "10000011010";
	io.writeFile("testBIO", strTree, bitsString);
	std::cout << "testBinaryWrite pass" << std::endl;
}
void testBinaryRead() {
	BinaryIO io;
	std::vector<std::string> ret =io.readFile("testBIO");
	std::string strTree = ret[0];
	std::string bitsString = ret[1];
	assert(strTree == "IIILaLbILeLfILcLd");
	assert(bitsString == "10000011010");
	std::cout << "testBinaryRead pass" << std::endl;
}
void testCountFreqsSStream() {
	std::string testStr = "Banana";
	std::istringstream iss(testStr);
	count_freqs(iss);
	std::cout << "testCountFreqsSStream pass" << std::endl;
}
void testCountFreqsFileStream() {
	std::ifstream infile("testCountFreq.txt");
	if (infile.is_open()) {
		count_freqs(infile);
	}
	std::cout << "testCountFreqsFileStream pass" << std::endl;
}

void testSerializeTree_OneNode() {
	HuffmanTreeNode root('a', 20);
	std::string strTree= serialize_tree(&root);
	assert(strTree == "La");
	std::cout << "testSerializeTree_OneNode pass" << std::endl;
}


void testSerializeTree_MultiNode() {
	std::string expected = "IIILaLbILeLfILcLd";
	//make a fake haffman tree 
	//just to test the Serialize function
	//						root
	//			  node3					node4
	//		node1		node2		nodeC	nodeD
	//	nodeA nodeB	  nodeE	nodeF
	//
	HuffmanTreeNode leafNodeA('a', 20);
	HuffmanTreeNode leafNodeB('b', 20);
	HuffmanTreeNode leafNodeC('c', 20);
	HuffmanTreeNode leafNodeD('d', 20);
	HuffmanTreeNode leafNodeE('e', 20);
	HuffmanTreeNode leafNodeF('f', 20);

	HuffmanTreeNode interNode1(0, 0,&leafNodeA,&leafNodeB);
	HuffmanTreeNode interNode2(0, 0,&leafNodeE,&leafNodeF);
	HuffmanTreeNode interNode3(0, 0,&interNode1,&interNode2);
	HuffmanTreeNode interNode4(0, 0,&leafNodeC,&leafNodeD);
	HuffmanTreeNode root(0, 0,&interNode3,&interNode4);
	std::string strTree = serialize_tree(&root);
	assert(strTree == expected);

	std::cout << "testSerializeTree_MultiNode pass" << std::endl;

}
void testDeserializeTree() {
	std::string expected = "La";
	HuffmanTreeNode* root = deserialize_tree(expected);

	std::string strTree = serialize_tree(root);
	assert(strTree == expected);

	//free the heap memory
	freeTreeMemory(root);
	std::cout << "testDeserializeTree pass" << std::endl;
}
int main() {
	testTreeNode();
	testBinaryWrite();
	testBinaryRead();
	testCountFreqsSStream();
	testCountFreqsFileStream();
	testSerializeTree_OneNode();
	testSerializeTree_MultiNode();
	testDeserializeTree();
}