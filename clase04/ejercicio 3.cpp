#include <iostream>
//#include <stdlib.h> 

void TurnToCelsius (float gradosF){
	float gradosC = (gradosF - 32) * (5.0 / 9.0);
	std::cout << gradosC << std::endl;
}

int main(){
	while (true) {
		float celsius;

		std::cout << "Grados Fahrenheit?: ";
		std::cin >> celsius;
		TurnToCelsius(celsius);

		//system("cls");

	}
}