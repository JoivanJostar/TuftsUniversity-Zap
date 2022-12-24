
CXX      = clang++
CXXFLAGS = -g3 -Wall -Wextra -Wpedantic -Wshadow 
LDFLAGS  = -g3 
zap: main.o BinaryIO.o HuffmanCoder.o HuffmanTreeNode.o 
	$(CXX) $(CXXFLAGS) -o zap $^ 


HuffmanCoder.o: HuffmanCoder.cpp HuffmanCoder.h BinaryIO.h HuffmanTreeNode.h
	$(CXX) $(CXXFLAGS) -c HuffmanCoder.cpp
main.o: main.cpp HuffmanCoder.h
	$(CXX) $(CXXFLAGS) -c main.cpp

unit_test: unit_test_driver.o BinaryIO.o HuffmanCoder.o HuffmanTreeNode.o 
	$(CXX) $(CXXFLAGS) $^



# This rule provides your final submission 
# NOTE: Don't forget to add any additional files you want to submit to this
#		rule! If you do not add them, they will not be submitted.
provide:
	provide comp15 proj3_zap HuffmanCoder.h HuffmanCoder.cpp \
				unit_tests.h main.cpp BinaryIO.h \
				HuffmanTreeNode.h Makefile README \
				test1.txt testCppSourceCode.txt \
				testRootIsLeaf.txt testEmptyFile.txt
clean: 
	rm HuffmanCoder.o main.o *~ *.gch a.out 
