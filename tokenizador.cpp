#include<string>
#include <iostream>
#include<fstream>
#include<vector>
#include<sstream>
#include<string.h>
#include"detector.h"
std::vector<std::string>tokens;
void readin() {
	std::ifstream codigoSinTokenizar("script.txt");
	if (!codigoSinTokenizar.is_open()) {
		std::cout << "ELITA: I am looking for a good way to rust your code";
	}
	else {
		std::string line;
		while (std::getline(codigoSinTokenizar, line)) {
			std::string token;
			std::stringstream ss(line);
			while (ss >> token) {

				tokens.push_back(token);
			}
			firstWall(tokens);
			tokens.clear();

		}
	}
}