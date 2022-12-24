

* Project 3: Zap
* CS 15
* README
  

# Purpose

This program is the Project3 Zap Phase 1.



# FILES

BinaryIO.h: the class and interface definition of Binary Write and Read

HuffmanTreeNode.h: the class and interface definition of HuffmanTreeNode. it also contains a compare operator() for priority queue.

phaseOne.h :  it has 3 functions interface:

void count_freqs(std::istream& text);
std::string serialize_tree(HuffmanTreeNode* root);
HuffmanTreeNode* deserialize_tree(std::string serial_tree);



phaseOne.cpp: the implementation of  phaseOne.h 

test.cpp: simple main driver, it will test  the functions in above phaseOne.h .

testCountFreq.txt: A TestFile for count_freqs(std::istream& text) where the param text is a filestream



makefile and README

# E.COMPILE &RUN
     - Compile using
            make test
     - run executable with
            ./test 

