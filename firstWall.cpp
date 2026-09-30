// ConsoleApplication4.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <iostream>
#include<vector>
#include"dispatcher.h"
#include<string>
#include"Speach.h"
int commandSeem = 0;
//ghtyg
int commandsNotAffected = 0;

void firstWall(std::vector<std::string> token) {
	std::cout << "hello wall";
	std::vector <std::string> command = {"pin","setup","loop","espera","fin","escribir:"};
	for (int i=0; i < command.size();  i++) {
		if (token[0]== command[i]) {
			std::cout <<"" << "is\n" <<token[0];
			commandsNotAffected = 0;
			commandSeem = 0;
			dispatcher(token);
		}
		else if (commandSeem ==command.size()){
			commandSeem = 0;
			std::cout << "whivh commad looks like\n";
			int correct = 0;
			int total = command.size()-1;
			for (int z= 0; z< total && z < token[0].length(); z++) {
				std::cout << "gey\n";
				if (token[0][z]== command[i][z]) {
					std::cout << "hello";
					correct++;
				}
			}

			double porcentaje = (double)correct / total * 100;
			std::cout << porcentaje;
			if (porcentaje >= 60) {
				dialogue("Correcion de escribir");
				std::cout << "Elita:¡Ja!,¡ lo has escrito mal!\n";
				commandsNotAffected = 0;
				return ;
			}
			else {
				commandsNotAffected++;
			}
			if (commandsNotAffected== command.size()) {
				std::cout << "ELITA: loha escrito tan mal que parece que ha escrito otro comando (cual es este comando)\n";
				commandsNotAffected = 0;
				break;
			}
		}
		else {
			std::string tokenn = token[0];
			std::cout << "hey this is the roght command\n" << tokenn;
			commandSeem++;

		}
	}
	token.clear();

}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
