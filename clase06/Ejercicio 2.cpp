#include <iostream>
#include <vector>
#include <windows.h>
#include <algorithm>
#include <time.h>
#include <conio.h>

/*b. Realizar un programa que permita la carga de 10 números en una lista o vector.
Una vez cargados, se necesita que el programa determine cuál es el mayor y cuál es el
menor de ellos.*/

int randomizer() {
	
	return rand() % 10;
}



std::vector<int> populador() {
	std::vector<int> tenVector;
	int placeholder = 0;
	bool shuffle = true;

	while (shuffle) {
		int random = randomizer();

		if (random != placeholder) {
			placeholder = random;
			tenVector.push_back(placeholder);
		}

		if (tenVector.size() >= 10) {
			shuffle = false;
		}

	}
	
	return tenVector;
}

void ordenador(std::vector <int>& vectorIn) {

	sort(vectorIn.begin(),vectorIn.end());

}

void vectorPrint(std::vector<int>& vectorIn) {
	for (int i : vectorIn) {
		std::cout << i << " ";
	}

}

int main() {
	SetConsoleCP(CP_UTF8);          // entrada
	SetConsoleOutputCP(CP_UTF8);    // salida

	srand(time(0));
	while (true) {
		
		std::vector <int> vector = populador();
		std::cout << "\n------------------------------------";
		std::cout << "\nVector original: ";
		vectorPrint(vector);
		ordenador(vector);
		std::cout << "\nVector ordenado: ";
		vectorPrint(vector);

		if (_getch() == 27) {
			break;
		}
	}

}
//julian (tm)
