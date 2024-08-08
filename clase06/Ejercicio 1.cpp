#include <iostream>
#include <list>
#include <conio.h>

                               
int main() {
 
	std::list<std::string> fellowship = {};	
	//std::list<std::string>::iterator iter;
	//std::list<int>::iterator interator;

	std::string miembro;
	//int counter = 0;


	std::cout << "Nombrar de a uno los integrantes de la comunidad del anillo:\n" << std::endl;

	while (fellowship.size() < 9) {
		std::cin >> miembro;
		fellowship.push_back(miembro);
		//++counter;
		std::cout << "Falta/n " << (9 - fellowship.size()) << " integrante/s" << std::endl;
	}

	std::cout << "\nLos miembros de la comunidad entonces son: \n";
	for (auto iter = fellowship.begin(); iter != fellowship.end(); ++iter) {
		std::cout << *iter << std::endl;
		
	}

	(void)_getch();

	std::cout << "\nEntran a Minas Tirith. Wild Balrog appears.";
	(void)_getch();
	std::cout << "\nGandalf has left the room\n";
	fellowship.remove("Gandalf");
	(void)_getch();
	std::cout << "La aventura continúa. Salen de las minas pero los orcos los persiguen.\n";
	(void)_getch();
	std::cout << "Boromir recibe un crítico, queda en 0hp y lo expulsan de la party.\n";
	fellowship.remove("Boromir");
	(void)_getch();
	std::cout << "Quedan entonces: \n";

	for (auto iter = fellowship.begin(); iter != fellowship.end(); ++iter) {
		std::cout << *iter << std::endl;

	}

	return 0;

}
