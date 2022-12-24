/*
* this file is the main() function of this project
* 
*/
#include "HuffmanCoder.h"
#include <iostream>
#include <string>
#include <exception>
int main(int argc, char* argv[]) {


	std::string errCmdMsg = "Usage: ./zap [zap | unzap] inputFile outputFile";
	if (argc != 4) {
		std::cerr << errCmdMsg<<std::endl;
		return 1;
	}

	if (std::string(argv[1]) == "zap") {
		HuffmanCoder coder;
		try {
			coder.encoder(argv[2], argv[3]);
		}
		catch (std::runtime_error e) {
			std::cerr << e.what()<<std::endl;
		}
	}
	else if (std::string(argv[1]) == "unzap") {
		HuffmanCoder coder;
		try {
			coder.decoder(argv[2], argv[3]);
		}
		catch (std::runtime_error e) {
			std::cerr << e.what()<<std::endl;
		}
	}
	else {
		std::cerr << errCmdMsg<<std::endl;
		return 1;
	}
	return 0;
}
