# A

* Project 3: Zap
* CS 15
* README
  

# B.Purpose

This program is the Project3 Zap Phase 2.
This is a Compression program using Huffman encode.

# C.Acknowledgements

the priority queue used when building the Huffman Tree is C++ STL priority_queue .

the characters frequencies and 01 bitsStrings are stored into 2 C++ STL map.

In source code HuffmanCoder.cpp , they are 	

​	std::map<char, int> freqsCountsMap;
​	std::map<char, std::string> codeMap;




# D.FILES

BinaryIO.h: the class and interface definition of Binary Write and Read

HuffmanTreeNode.h: the class and interface definition of HuffmanTreeNode. it also contains a compare operator() for priority queue.

HuffmanCoder.h : the class and interface definition  of  HuffmanCoder. it has 2 public function : encoder() and decoder() . and some private helper functions.

HuffmanCoder.cpp: the implementation of Class HuffmanCoder.

main.cpp: simple main driver, it check the command line arguments first, and then create a HuffmanCoder and call the encoder()  or decoder() method.

unit_tests.h: the unit test file.



TestFiles:

test1.txt : a simple test file with 6 bytes

testCppSourceCode.txt : more complex test file with 5.69KB

testRootIsLeaf.txt : the content of this file is "aaa"

testEmptyFile.txt : an empty file 



makefile and README

# E.COMPILE &RUN
     - Compile using
            make zap
     - run executable with
            ./zap [zap | unzap] inputFile outputFile
# F.Data Structures and Algorithm

1.A Binary Tree Structure was used to represent the HuffmanTree. Further it is a full binary tree: a binary tree in which every node has either 0 or 2 children .

2.A map structure was used to store the frequencies and bitsStrings of each character. we can quickly query the value corresponding to the key provided by us from  a Map structure.

3.While generating the bitsString of each character after building the HuffmanTree, a recursive  pre-order traversal algorithm was used. 

4.Also when serializing a tree and deserializing from a string , a recursive  algorithm was used to implement  these functions.



Huffman encode is one of the famous compression algorithms, it is a var-length binary encode method.

Most of the lossless data compression algorithms commonly used today are another well-known algorithm:LZ77 algorithm,  which is a very fast, efficient algorithm. (See the papaer "A Universal Algorithm for Sequential Data Compression" by Lempel and Ziv.1977.)

# G.Test

The test code is in the unit_tests.h 

In Phase1, I have tested the Binary Write and Read function of BinaryIO.h and other functions , they are

#count_freqs(std::istream& text);

#std::string serialize_tree(HuffmanTreeNode* root);

#HuffmanTreeNode* deserialize_tree(std::string serial_tree);

In this Phase, I add these 3 functions into class HuffmanCoder to help implement it.



As I implemented it, I tested the individual functions in detail:



1.test the count_freqs(std::istream& text), and then check if the freqs are stored properly in this->

freqsCountsMap;

2.test the buildTree() , and then check if a proper HuffmanTreeNode ( root ) was returned.

3.and then call the generateCodeMap(HuffmanTreeNode* root) to generate the bitsString of each character.

4.After all of the helper functions was tested, I build a HuffmanTree by hand, and compute the result of encode, then run the function encoder() to check if this function's result is the same as the one that I compute  by hand.

Here I create some test files to test the encoder and decoder:

1.test1.txt  is a simple file which is only 16 Bytes ,  I pass it to the encoder to generate the compressed file "test1.zap" , and then decode this file to "test1_unzap.txt" .Finally I use diff to check if "test1.txt" and "test1_unzap.txt" are the same.

This test file was easily passing the encoder and decoder test.

2.testCppSourceCode.txt is the source code file of HuffmanCoder.cpp. I use it to test a more complex situation. The test method is the same as above. It also passed the test easily.



3.testRootIsLeaf.txt . This is an Edge test, the content of this file was "aaa". That means there is only 1 kind character 'a' whose frequency is 3. so the HuffmanTree only has 1 node , that means "root is a leaf".

I took this scenario into account and handled it .



4.testEmptyFile.txt. This is an Edge test, this file has nothing , (That means the root of HuffmanTree is NULL) but the program should compress and decompress  it properly.