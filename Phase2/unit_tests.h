/*
* this file is the unit test functions for HuffmanCoder
*/
#include "HuffmanTreeNode.h"
#include "BinaryIO.h"
#include <iostream>
#include <string>
#include <sstream>
#include <assert.h>
#include "HuffmanCoder.h"
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
//---------------test HuffmanCorder------------
// these tests need all of the member and function of HuffmanCorder
//to be public . So these tests are commented out here.
//void testCountFreqs() {
//	HuffmanCoder corder;
//	std::string s = "aaabbbb,\n\tff";
//	std::istringstream iss(s);
//	corder.count_freqs(iss);
//	assert(corder.freqsCountsMap['a'] == 3);
//	assert(corder.freqsCountsMap['b'] == 4);
//	assert(corder.freqsCountsMap[','] == 1);
//	assert(corder.freqsCountsMap['\n'] == 1);
//	assert(corder.freqsCountsMap['\t'] == 1);
//	assert(corder.freqsCountsMap['f'] == 2);
//}
//
//void testBuildTree() {
//	HuffmanCoder corder;
//	std::string s = "aaabbbb,\n\tff";
//	std::istringstream iss(s);
//	corder.count_freqs(iss);
//	HuffmanTreeNode * root= corder.buildTree();
//	corder.freeTreeMemory(root);
//}
//
//void testGenerateCodeMap() {
//	HuffmanCoder corder;
//	std::string s = "aaabbbb,\n\tff";
//	std::istringstream iss(s);
//	corder.count_freqs(iss);
//	HuffmanTreeNode* root = corder.buildTree();
//	corder.generateCodeMap(root);
//	corder.freeTreeMemory(root);
//}
void testEncoder() {
	HuffmanCoder coder;
	try {
		coder.encoder("test1.txt", "test1.zap");
		//expected bits size=43 bits
	}
	catch (std::runtime_error e) {
		std::cout << e.what() << std::endl;
	}
}

void testDecoder() {
	
	HuffmanCoder coder;
	try {
		coder.decoder("test1.zap", "test1_unzap.txt");

		//you can diff test1.txt test1_unzap.txt
		//to see if they are same
	}
	catch (std::runtime_error e) {
		std::cout << e.what() << std::endl;
	}
}

void testEncoderUnopenableFile() {
	HuffmanCoder coder;
	try {
		coder.encoder("unopenableFile.file", "outfile");
		assert(false);
	}
	catch (std::runtime_error e) {
		assert(true);
	}
	std::cout << "testEncoderUnopenableFile pass" << std::endl;
}
void testDecoderUnopenableFIle() {
	HuffmanCoder coder;
	try {
		coder.decoder("unopenableFile.file", "outfile");
		assert(false);
	}
	catch (std::runtime_error e) {
		assert(true);
	}
	//this should throw a runtime error

	std::cout << "testDecoderUnopenableFIle pass" << std::endl;
}
void testRootIsLeaf() {
	HuffmanCoder coder;
	try {
		coder.encoder("testRootIsLeaf.txt", "testRootIsleaf.zap");
		coder.decoder("testRootIsleaf.zap", "testRootIsleaf_unzap.txt");

		//then you can diff  
		//to check if the 2 files are the same
	}
	catch (std::runtime_error e) {
		std::cout << e.what() << std::endl;
	}
}
void testCppSourceCode() {
	HuffmanCoder coder;
	try {
		coder.encoder("testCppSourceCode.txt", "testCppSourceCode.zap");
		coder.decoder("testCppSourceCode.zap", "testCppSourceCode_unzap.txt");

	}
	catch (std::runtime_error e) {
		std::cout << e.what() << std::endl;
	}
}
void testEmptyFile() {
	HuffmanCoder coder;
	try {
		coder.encoder("testEmptyFile.txt", "testEmptyFile.zap");
		coder.decoder("testEmptyFile.zap", "testEmptyFile_unzap.txt");

	}
	catch (std::runtime_error e) {
		std::cout << e.what() << std::endl;
	}
}