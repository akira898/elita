// coño.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <iostream>
#include<fstream>
#include<string>
#include<vector>
#include<filesystem>
bool alreadyReading = false;
#ifndef tokenizador_h
#define tokenizador_h
//reading;
void readin();
#endif tokenizador_h
#include"raylib.h"
int WIDTH = MeasureText("JUGAR", 25);
void dialogue(std::string Say) {
	InitWindow(800, 800, "ELITA");
	int dialoguePosition = 18;
	std::vector<std::string>ToSay;
	std::cout << "Tremendas honka badonkas";
	std::string dialogueIn;
	std::ifstream inicialDialague(Say+ ".txt");
	if (ToSay.size() < dialoguePosition) {
		dialoguePosition = ToSay.size();
	}
	while (std::getline(inicialDialague, dialogueIn)) {
		ToSay.push_back(dialogueIn);
		std::cout << ToSay[0];
	}
	while (!WindowShouldClose()) {
		BeginDrawing();
		Vector2 mouse = GetMousePosition();
		Rectangle botonCompile = { 300,250,200,80 };
		Rectangle botonDress = { 250,250,200,80 };
		bool inBoton = CheckCollisionPointRec(mouse, botonCompile);
		if (ToSay.size() <= dialoguePosition) {
			DrawRectangleRec(botonCompile, inBoton ? DARKBLUE : BLUE);
			DrawText("COMPILAR", 100 + (350 - WIDTH) / 2, 250, 30, WHITE);
			DrawText("TRAJES", 100 + (200 - WIDTH) / 2, 250, 30, WHITE);
			DrawRectangleRec(botonDress, inBoton ? DARKBLUE : BLUE);
		}
		if (dialoguePosition <= ToSay.size() - 1 && !alreadyReading) {
			DrawText(ToSay[dialoguePosition].c_str(), 300, 300, 20, WHITE);
		}
		ClearBackground(BLACK);
		// añadire el soporte al resto de botones del raton luego
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && ToSay.size() > dialoguePosition) {
			dialoguePosition++;
		}
		else if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && inBoton) {
			readin();
		}
		EndDrawing();
	}

}
int main()
{
	std::cout << "Puto programa de mierda";
	std::string Elita = "dialogue";
	dialogue(Elita);
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
