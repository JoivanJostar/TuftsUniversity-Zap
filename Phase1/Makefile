
CXX      = clang++
CXXFLAGS = -g3 -Wall -Wextra -Wpedantic -Wshadow 
LDFLAGS  = -g3 
test: test.o BinaryIO.o HuffmanTreeNode.o phaseOne.o
	$(CXX) $(CXXFLAGS) -o test $^ 


phaseOne.o: phaseOne.cpp phaseOne.h BinaryIO.h HuffmanTreeNode.h
	$(CXX) $(CXXFLAGS) -c phaseOne.cpp
test.o: test.cpp BinaryIO.h phaseOne.h BinaryIO.h HuffmanTreeNode.h
	$(CXX) $(CXXFLAGS) -c test.cpp



# This rule provides your final submission 
# NOTE: Don't forget to add any additional files you want to submit to this
#		rule! If you do not add them, they will not be submitted.
provide:
	provide comp15 proj3_zap_phase1 test.cpp phaseOne.cpp \
				testCountFreq.txt phaseOne.h Makefile README \
				BinaryIO.h HuffmanTreeNode.h
clean: 
	rm phaseOne.o test.o *~ *.gch a.out 
