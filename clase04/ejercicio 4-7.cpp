#include <iostream>
#include <windows.h>
#include <conio.h>
#include <time.h>

//Esconde el cursor de la consola
void hideCursor() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(hConsole, &cursorInfo);
	cursorInfo.bVisible = FALSE; // Set the cursor visibility
	SetConsoleCursorInfo(hConsole, &cursorInfo);
}


//Imprime en consola el menú
void MenuOptions(int selector) { 

	switch (selector) {
	case 0:
		std::cout << "En qué dirección avanzas?: \n\n > .Norte\n.Sur\n.Este\n.Oeste\n.Acampar";
		break;
	case 1:
		std::cout << "En qué dirección avanzas?: \n\n.Norte\n > .Sur\n.Este\n.Oeste\n.Acampar";
		break;
	case 2:
		std::cout << "En qué dirección avanzas?: \n\n.Norte\n.Sur\n > .Este\n.Oeste\n.Acampar";
		break;
	case 3:
		std::cout << "En qué dirección avanzas?: \n\n.Norte\n.Sur\n.Este\n > .Oeste\n.Acampar";
		break;
	case 4:
		std::cout << "En qué dirección avanzas?: \n\n.Norte\n.Sur\n.Este\n.Oeste\n > .Acampar";
		break;
	}

}



/*
	Imprime en consola el texto después de seleccionar en el menú. 
	*randomSelector está pasado como puntero para poder hacer que el selector no repita el último valor que
	haya salido.
*/
void MenuSelections(int* randomSelector, int* justOnce, int* cansancio) {

	
	bool shuffle = true;
	while (shuffle) {
		int randomChance = rand() % 4;

		if (*randomSelector != randomChance){
			*randomSelector = randomChance;
			shuffle = false;
		}
	}

	
	switch (*randomSelector) {
	case 0:
		*cansancio -= 5;
		system("cls");
		std::cout << "\nNotás entre la arboleda un sendero y te adentrás. Encontrás de camino una botella de agua, \npero esperás a tener mucha sed hasta tomarla.";
		break;
	case 1:
		*cansancio += 15;
		system("cls");
		std::cout << "\nCaminás y no pasa mucho rato hasta que dejás de entender si es sendero nuevo o ya caminaste por ahí.";
		break;
	case 2:
		*cansancio += 30;
		system("cls");
		std::cout << "\nCuando girás para avanzar te parece notar movimiento cerca tuyo. Apurás el paso...";
		break;
	case 3:
		*cansancio += 10;
		system("cls");
		std::cout << "\nLa luz que ves te parece que viene de una fogata. Avanzás con cuidado...";
		break;
	case 4:
		
		break;
	}
	
	*justOnce = 0;

}

void IntroText(int* justOnce) {
	if (*justOnce) {
		std::cout << "Te despertaste en un claro de un bosque. Te parás del susto apenas te das cuenta."
				<< "\nHay sol, luz. Sentís pasto entre los dedos. No tenés calzado. ";
	}
}

int menuUp(int* counter, int* wrappedCounter) {
	--*counter;
	*wrappedCounter = *counter % 5;
	if (*wrappedCounter < 0) {
		*wrappedCounter += 5;

	}
	return *wrappedCounter;
}

int menuDown(int* counter, int* wrappedCounter) {
	++*counter;
	*wrappedCounter = *counter % 5;				//Mapeo el contador entre el valor de la variable dereferenciada y la 
	if (*wrappedCounter < 0) {					// cantidad de opciones para elegir en el menú (5 en este caso).
		*wrappedCounter += 5;					//Para valores negativos de "counter", se le suma 5 al wrapped
												// para hacerlos positivos.
	}
	return *wrappedCounter;
}

void MenuInteractions () {
	srand(time(0));
	int counter = 0;
	int wrappedCounter = 0;
	int justOnce = 1;
	int randomSelector = 0;
	int cansancio = 0;

	IntroText(&justOnce);						//Inicializa el texto intro.
	MenuOptions(wrappedCounter);				//Inicializa el menú.
	std::cout << "\n\n (Cansancio: " << cansancio << "%)" << std::endl;
	(void)_getch();
	
	

	while(true){

		if (GetKeyState(VK_RETURN) & 0x8000){	//Detecta si se presiona tecla ENTER
			if (wrappedCounter == 4) {
				system("cls");
				std::cout << "\n\nAcampás, pero los ruidos te incomodan...\n";
				(void)_getch();
				break;
			}
			
			MenuSelections(&randomSelector, &justOnce, &cansancio);


			(void)_getch();
		}
		if (GetKeyState(VK_UP) & 0x8000){		//Detecta si se presiona tecla ARRIBA
			
			menuUp(&counter, &wrappedCounter);
			(void)_getch();
		}
		if (GetKeyState(VK_DOWN) & 0x8000){		//Detecta si se presiona tecla abajo
			menuDown(&counter, &wrappedCounter);
			(void)_getch();
		}

		system("cls");							//Borra lo que estaba escrito en la consola
		IntroText(&justOnce);					//Sigue imprimiendo la intro si todavía no se seleccionó ninguna opción
		
		if (cansancio >= 100) {
			std::cout << "\nVan varias horas ya que estás dando vueltas y no encontrás la salida. ";
			break;
		}
		
		MenuOptions(wrappedCounter);			//Escribe de nuevo el menú seleccionable
		std::cout << "\n\n (Cansancio: " << cansancio << "%)" << std::endl;
		Sleep(15);
		(void)_getch();
	}


}

int main () {
	SetConsoleCP(CP_UTF8);          // entrada
	SetConsoleOutputCP(CP_UTF8);    // salida

	hideCursor();
	MenuInteractions();
	
	std::cout << "Se acerca la noche...\n";

	return 0;
}