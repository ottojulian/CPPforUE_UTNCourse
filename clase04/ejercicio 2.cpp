#include <iostream>



void Saludar (std::string nombre){
	std::cout << "Bonjour " + nombre + "!";
}

int main (){
	std::string nombre;

	std::cout << "(ingresar nombre):";
	std::cin >> nombre;

	Saludar(nombre);

	return 0;
}