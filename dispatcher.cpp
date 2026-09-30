#include<vector>
#include<string>
#include <iostream>
#include<fstream>
#include"print.h"
std::ofstream codigo("Arduino.ino");
extern std::vector<std::string>tokens;
bool  SetMonitor = true;
std::vector<std::string> voids;
std::vector<std::string> pins;
void dispatcher(std::vector<std::string> tokens) {
	std::cout << "hello\n";
	if (!tokens.empty() && tokens[0] == "setup") {
		std::cout << "setup detected\n";
		codigo << "void setup(){\n";
		codigo << "  Serial.begin(9600);\n";
		voids.push_back(tokens[0]);
		codigo.flush();
	}
	if (!tokens.empty() && tokens[0] == "loop") {
		codigo << "void loop(){\n";
		voids.push_back(tokens[0]);
		codigo.flush();
	}
	if (!voids.empty() && voids[0] == "setup" && !tokens[0].empty() && tokens.size() >= 3 && tokens[0] == "pin") {
		if (tokens[2] == "salida") {
			codigo << "  pinMode(" << tokens[1] << ",OUTPUT);\n";
			pins.push_back(tokens[1]);
		}
		else if (tokens[2] == "entrada") {
			codigo << "  pinMode(" << tokens[1] << ",INPUT);\n";
			pins.push_back(tokens[1]);
		}
	}
	if (!voids.empty() && !tokens[0].empty() && tokens.size() >= 3 && tokens[0] == "pin") {
			if (std::find(pins.begin(), pins.end(), tokens[1]) != pins.end()) {
				if (tokens[2] == "encendido") {
					codigo << "  digitalWrite(" << tokens[1] << ",HIGH);\n";
				}
				else if (tokens[2] == "apagado") {
					codigo << "  digitalWrite(" << tokens[1] << ",LOW);\n";
				}
			}
	}
	if (!tokens.empty() && tokens[0] == "escribir:" && tokens.size() >= 2 && !voids.empty()){
		std::cout << "escribir dtected\n";
		codigo << "  Serial.println(" << tokens[1] << ");\n";
	}
	else if (voids.empty() && !voids.empty()) {
		std::cout << "Elita:... you are gonna need a void, stupid";
	}
	if (!tokens.empty() && tokens[0] == "fin") {
		codigo << "}\n";
		codigo.flush();
	}
	if (!tokens.empty() && tokens[0] == "espera" && tokens.size()==2) {
		codigo << "  delay(" << tokens[1] << ");\n";
	}
}