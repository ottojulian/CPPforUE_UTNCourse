#include <iostream>
#include <locale.h>
#include <windows.h>
#include <math.h>
#include <string>
#define PI 3.1415926536



int main(){
	SetConsoleCP(CP_UTF8);          // entrada
    SetConsoleOutputCP(CP_UTF8);    // salida

    int numeroEjercicio;

    std::cout << "Elegir número de ejercicio (1-25) o 0 para terminar: ";
    std::cin >> numeroEjercicio;

    switch (numeroEjercicio) {
    case 1: {
    	std::cout << "\n////////// Ejercicio 1 ////////// \n" << std::endl;
    	double number1, number2;
		
		std::cout << "Suma" << std::endl;
		std::cout << "Ingrese un número: ";
		std::cin >> number1;

		std::cout << "Ingrese otro número: ";
		std::cin >> number2;

		double suma = number1 + number2;
		std::cout << "La suma de los números que ingresaste son: " << suma << std::endl;
		}
		break;
	case 2: {
    	std::cout << "\n////////// Ejercicio 2 ////////// \n" << std::endl;

		double number1, number2;
		
		std::cout << "Multiplicación" << std::endl;
		std::cout << "Ingrese un número: ";
		std::cin >> number1;

		std::cout << "Ingrese otro número: ";
		std::cin >> number2;
		double producto = number1*number2;
		std::cout << "El producto de los números que ingresaste es: " << producto << std::endl;
		}
		break;
	case 3: {
    	std::cout << "\n////////// Ejercicio 3 ////////// \n" << std::endl;
		double number1, number2;
		
		std::cout << "Cociente" << std::endl;
		std::cout << "Ingrese un número: ";
		std::cin >> number1;

		std::cout << "Ingrese otro número: ";
		std::cin >> number2;
		double cociente = number1/number2;
		std::cout << "El cociente entre los números que ingresaste es: " << cociente << std::endl;

		}
		break;
	case 4: {
		std::cout << "\n////////// Ejercicio 4 ////////// \n" << std::endl;
		double number1, number2;
		
		std::cout << "Diferencia" << std::endl;
		std::cout << "Ingrese un número: ";
		std::cin >> number1;

		std::cout << "Ingrese otro número: ";
		std::cin >> number2;
		
		double diferencia = number1 - number2;
		std::cout << "La diferencia entre los números que ingresaste es: " << diferencia << std::endl;
		}
		break;
	case 5: {
		std::cout << "\n////////// Ejercicio 5 ////////// \n" << std::endl;
		double number1, number2;
		
		std::cout << "Cocientes" << std::endl;
		std::cout << "Ingrese un número: ";
		std::cin >> number1;

		std::cout << "Ingrese otro número: ";
		std::cin >> number2;
		double cociente1 = number1 / number2;
		double cociente2 = number2 / number1;
		std::cout << "Los dos posibles cocientes entre los números que ingresaste son: " << cociente1 << " y " << cociente2 << std::endl;
		}
		break;
	case 6: {
		std::cout << "\n////////// Ejercicio 6 ////////// \n" << std::endl;
		double number1, number2;
		
		std::cout << "Resto" << std::endl;
		std::cout << "Ingrese un número: ";
		std::cin >> number1;

		std::cout << "Ingrese otro número: ";
		std::cin >> number2;
		double resto = fmod(number1,number2);
		std::cout << "El resto de la división entre los números que ingresaste es: " << resto << std::endl;

		}
		break;
	case 7: {
		std::cout << "////////// Ejercicio 7 ////////// \n" << std::endl;
		std::cout << "N múltiplos" << std::endl;
		int n;

		std::cout << "Ingrese un número" << std::endl;
		std::cin >> n;
		int multiplos;
		int contador = 0;

		printf("%d es múltiplo de: \n", n);
		for (int i = 1; i <= 4; ++i) {

			multiplos = i*n;
			printf("n = %d: %d \n", i, multiplos);
			contador += 1;
		}

		}
		break;
	case 8: {
		std::cout << "////////// Ejercicio 8 ////////// \n" << std::endl;
		double primerNumero, segundoNumero, tercerNumero;

		std::cout << "Cocientes entre tres números" << std::endl;

		std::cout << "Ingresar tres números. Vamos con el 1ero: ";
		std::cin >> primerNumero;
		std::cout << "Ahora el segundo: ";
		std::cin >> segundoNumero;
		std::cout << "y el último: ";
		std::cin >> tercerNumero;

		double cocienteA = primerNumero / segundoNumero;
		double cocienteB = primerNumero / tercerNumero;

		double cocienteC = segundoNumero / primerNumero;
		double cocienteD = segundoNumero / tercerNumero;

		double cocienteE = tercerNumero / primerNumero;
		double cocienteF = tercerNumero / segundoNumero;

		std::cout << "Los seis posibles cocientes entre esos números son: \n" << cocienteA << std::endl << cocienteB << std::endl << cocienteC << std::endl << cocienteD << std::endl << cocienteE << std::endl << cocienteF << std::endl;

		}
		break;
	case 9: {
		std::cout << "////////// Ejercicio 9 ////////// \n" << std::endl;
		std::cout << "Superficie de un rectángulo" << std::endl;
		double base, altura;

		std::cout << "ingresar la base del rectángulo: ";
		std::cin >> base;

		std::cout << "ingresar la altura del rectángulo: ";
		std::cin >> altura;	

		double superficie = base*altura;
		std::cout << "la superficie del rectángulo es " << superficie << std::endl;
		}
		break;
	case 10: {
		std::cout << "////////// Ejercicio 10 ////////// \n" << std::endl;
		std::cout << "Superficie de un cuadrado" << std::endl;

	    double lado;
	    std::cout << "indicar el lado de un cuadrado: ";
	    std::cin >> lado;

	    double superficieCuadrado = lado * lado;
	    double perimetroCuadrado = lado*4;
	    std::cout << "la superficie del cuadrado es " << superficieCuadrado << std::endl;

		}
		break;
	case 11: {
		std::cout << "////////// Ejercicio 11 ////////// \n" << std::endl;
		std::cout << "Perimetro de un cuadrado" << std::endl;

	    double lado;
	    std::cout << "indicar el lado de un cuadrado: ";
	    std::cin >> lado;

	    double superficieCuadrado = lado * lado;
	    double perimetroCuadrado = lado*4;
	    std::cout << "El perímetro del cuadrado es " << perimetroCuadrado << std::endl;

		}
		break;
	case 12: {
		std::cout << "////////// Ejercicio 12 ////////// \n" << std::endl;
		std::cout << "potencia 2" << std::endl;

	    unsigned int numero;

	    std::cout << "Ingresar un número";
	    std::cin >> numero;

	    int cuadrado = numero * numero;
	    int cubo = cuadrado * numero;
	    std::cout << "El cuadrado del número " << numero << " es " << cuadrado << std::endl;

		}
		break;
	case 13: {
		std::cout << "////////// Ejercicio 13 ////////// \n" << std::endl;
		std::cout << "potencia 3" << std::endl;

	    unsigned int numero;

	    std::cout << "Ingresar un número";
	    std::cin >> numero;

	    int cuadrado = numero * numero;
	    int cubo = cuadrado * numero;
	    std::cout << numero << " al cubo es " << cubo << std::endl;

		}
		break;
	case 14: {

		std::cout << "////////// Ejercicio 14 ////////// \n" << std::endl;
		std::cout << "Lados y ángulos de un triángulo" << std::endl;

	    float hipotenusa, angulo;

	    std::cout << "Ingresar hipotenusa y ángulo ";
	    std::cin >> hipotenusa;
	    std::cin >> angulo;

	    float rad = angulo * PI / 180;
	    float opuesto = sin(rad) * hipotenusa;
	    float adyacente = cos(rad) * hipotenusa;
	    float anguloRestante = 180 - (90 + angulo);

	    std::cout << "Los ángulos del triángulo son " << anguloRestante << "°, " << angulo << "° y 90°. Y si la hipotenusa es de " << hipotenusa << " el opuesto mide " << opuesto << " y el adyacente " << adyacente << std::endl;
		
		}
		break;
	case 15: {
		std::cout << "////////// Ejercicio 15 ////////// \n" << std::endl;
		std::cout << "Superficie y lados de un triángulo" << std::endl;

		float base;
		float altura;

	   std::cout << "Ingresar la base y la altura de un triángulo: ";
	    std::cin >> base;
	    std::cin >> altura;

	    float superficie = (base * altura) / 2;
	    float hipotenusa = sqrt(pow(base, 2) + pow(altura, 2));

	    std::cout << "la superficie mide " << superficie << std::endl;
	    std::cout << "la hipotenusa mide " << hipotenusa << std::endl;

		}
		break;
	case 16: {
		std::cout << "Woops!";
		}
		break;
	case 17: {

		std::cout << "////////// Ejercicio 17 ////////// \n" << std::endl;
		std::cout << "Superficie de un círculo" << std::endl;

	    float radio;

	    std::cout << "ingresar el radio de un círculo: ";
	    std::cin >> radio;

	    float superficieCirculo = PI*pow(radio, 2);

	    std::cout << "la superficie del círculo es de " << superficieCirculo << std::endl;

		}
		break;
	case 18: {

		std::cout << "////////// Ejercicio 18 ////////// \n" << std::endl;
		std::cout << "Radio de un círculo" << std::endl;

		float perimetroCirculo;
		std::cout << "Indicar el perímetro de un círculo: ";

		std::cin >> perimetroCirculo;

		float radio = perimetroCirculo / (2 * PI);
		std::cout << "el radio de la circunferencia es " << radio << std::endl;

		}
		break;
	case 19: {

		std::cout << "////////// Ejercicio 19 ////////// \n" << std::endl;
		std::cout << "Diagonal" << std::endl;

		float coordX, coordY;

		std::cout << "Indicar coordenadas X e Y: ";
		std::cin >> coordX;
		std::cin >> coordY;

		float diagonal = sqrt(pow(coordX, 2) + pow(coordY, 2));
		std::cout << "la diagonal resultante mide " << diagonal << "m." << std::endl;


		}
		break;
	case 20: {
		std::cout << "woopsie!";
		}
		break;
	case 21: {

		std::cout << "////////// Ejercicio 21 ////////// \n" << std::endl;
		std::cout << "El mural de Miguel angel" << std::endl;

		float alto, ancho, litros;
		const float mCuadrados = 3.6;

		std::cout << "Miguel Angel miró la pared, lo miró a su discípulo, y le dijo:" << std::endl << "'Mirá, para mi de alto la pared tiene algo así como... " << std::endl;
		std::cin >> alto;
		std::cout << "unos " << alto << " metros... Y de ancho, para mi que anda por los... " << std::endl;
		std::cin >> ancho;

		litros = (alto * ancho) / mCuadrados;
		std::cout << ancho << " metros, masssssomenos. Asique andá acá a la vuelta y conseguime exactamente " << litros << " litros de pintura. Después te digo cómo es la cuenta.'";


		}
		break;
	case 22: {

		std::cout << "////////// Ejercicio 22 ////////// \n" << std::endl;
		std::cout << "Vueltas por kilómetro" << std::endl;

		float vueltasRueda, perimetroRueda;

		perimetroRueda = PI*pow(0.50,2);
		vueltasRueda = 1000 / perimetroRueda;

		std::cout << "Las ruedas de Horacio tienen 50cm de diámetro. Por cada vuelta de la rueda, avanza " << perimetroRueda << " metros. Asique en un kilómetro las ruedas van a dar exactamente " << vueltasRueda << " vueltas." << std::endl;

		}
		break;
	case 23: {
		std::cout << "////////// Ejercicio 23 ////////// \n" << std::endl;
		std::cout << "Velocidad del NPC" << std::endl;


		float distancia, tiempo, velocidad;

		std::cout << "Para calcular la velocidad del NPC, hace falta primero conocer la distancia que va a recorrer, que es... ";
		std::cin >> distancia;
		std::cout <<" y también en cuánto tiempo va a tener que recorrer esa distancia. El tiempo en segundos para la distancia ingresada va a ser de...? ";
		std::cin >> tiempo;

		velocidad = distancia / tiempo;

		std::cout << "Entonces la velocidad del NPC es de " << velocidad << "m/seg" << std::endl;

		}
		break;
	case 24: {

		std::cout << "////////// Ejercicio 24 ////////// \n" << std::endl;
		std::cout << "tienda de pociones" << std::endl;

		bool indexing = true;

		std::string articleList;
		int totalItemAmt;
		float totalTicket = 0;


		std::cout << "La tienda cerró hace rato, último ticket y cierro la caja también\n 'A ver... qué compró el último?...'" << std::endl;

		while (indexing) {

			std::string articulo = "";
			int cantidad;
			float precioUnit, precioSubTotal;
			int auxilio;

			std::cout << "(ingresar nombre del artículo o letra 'q' para salir):" << std::endl;
			std::cin >> articulo;

			if (articulo == "q") {
				break;
			} else {

				std::cout << "(ingresar cantidad):" << std::endl;
				std::cin >> cantidad;
				std::cout << "(ingresar precio por unidad)" << std::endl;
				std::cin >> precioUnit;
				precioSubTotal = precioUnit * cantidad;

				articleList += std::to_string(cantidad) + "u de " + articulo + "___$" + std::to_string(precioSubTotal) + "\n";
				totalTicket += precioSubTotal;
			}
		}

		std::cout << "Bueno, la cuenta del último ticket entonces quedó en: \n"<< articleList << std::endl;
		std::cout << "			TOTAL: $" << totalTicket;
		}

		break;
	case 25: {

		std::cout << "////////// Ejercicio 25 ////////// \n" << std::endl;
		std::cout << "Cantidad de $$ y de litros de nafta gastados" << std::endl;

		float kmRecorridos, priceOfGas, kmPerLiter, litsBurned, cashSpent;

		std::cout << "Ingresar Km recorridos: ";
		std::cin >> kmRecorridos;
		std::cout << "Ingresar precio del combustible (x Litro): ";
		std::cin >> priceOfGas;
		std::cout << "Ingresar Km recorridos por litro: ";
		std::cin >> kmPerLiter;

		litsBurned = kmRecorridos / kmPerLiter;
		cashSpent = litsBurned * priceOfGas;

		std::cout << "La cantidad de nafta consumida es de " << litsBurned << " litros, y el dinero gastado suma " << cashSpent << std::endl;
		}
		break;
	}

	


	return 0;
}