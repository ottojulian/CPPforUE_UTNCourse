// Ejercicio_clase3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
//

#include <iostream>
#include <string>
#include <conio.h>
#include <random>
#include <windows.h>
#include <locale.h>
#include <algorithm>

int main() {

    //SetConsoleCP(CP_UTF8);          // entrada
    //SetConsoleOutputCP(CP_UTF8);    // salida


    int numEjercicio;
    bool selecting = true;

    while (selecting) {
        std::cout << "\nSeleccionar ejercicio del 1 al 15 o presioná 0 para salir: ";
        std::cin >> numEjercicio;

        switch (numEjercicio) {
        case 0: {
            selecting = false;
        }
                break;
        case 1: {

            std::cout << "///////////Ejercicio #1///////////\n>> Suma de números naturales\n" << std::endl;

            int numNatural = 0;
            int placeHolder, n;

            std::cout << "Hasta qué número natural sumamos, humano?: ";
            std::cin >> n;

            for (int i = 1; i <= n; ++i) {

                placeHolder = numNatural;
                numNatural += i;
                std::cout << placeHolder << " + " << i << " = " << numNatural << std::endl;

            }
            std::cout << "\nLa suma de los primeros " << n << " números es: " << numNatural << std::endl;
            break;

        }
        case 2: {
            std::cout << "///////////Ejercicio #2///////////\n>> Tablas\n" << std::endl;

            int multiplicador, tablaDel;
            int multiplo = 0;

            std::cout << "Qué número multiplicamos ahora? Que sea entero por favor... ";
            std::cin >> multiplicador;
            std::cout << "Y qué tabla te gustaría conocer del " << multiplicador << "? La tabla del...?: ";
            std::cin >> tablaDel;
            std::cout << "Elegiste " << multiplicador << " como multiplicador. La tabla entonces hasta el " << tablaDel << " es:" << std::endl;

            for (int i = 0; i <= tablaDel; ++i) {
                int multiplo;
                multiplo = multiplicador * i;
                std::cout << multiplicador << " * " << i << " = " << multiplo << std::endl;
            }

        }
            break;
        case 3: {
            std::cout << "///////////Ejercicio #3///////////\n>> Factorial\n" << std::endl;

            int n, placeHolder;
            int factorial = 0;

            std::cout << "Factorial de qué número?:  ";
            std::cin >> n;

            placeHolder = n;
            factorial = n;

            if (n == 0) {
                std::cout << "El factorial de " << placeHolder << " da 1" << std::endl;
            }
            else {
                for (int i = 1; i < n; ++i) {
                    factorial *= i;
                }
                std::cout << "El factorial de " << placeHolder << " da " << factorial;

            }
        }
            break;
        case 4: {
            std::cout << "///////////Ejercicio #4///////////\n>> Racha/Overkill\n" << std::endl;

            for (int i = 1; i <= 25; ++i) {
                if (i < 15) {
                    std::cout << "Racha!" << std::endl;
                } else {
                    std::cout << "Overkill!" << std::endl;
                }
            }

        }
                break;
        case 5: {
            std::cout << "///////////Ejercicio #5///////////\n>> \n" << std::endl;

        }
                break;
        case 6: {
            std::cout << "///////////Ejercicio #6///////////\n>> % de persuación\n" << std::endl;

            std::random_device rd; //creates a random device object which is used to seed the random number generator
            std::mt19937 gen(rd()); //initializes the Mersenne Twister random number generator with the seed obtained from std::random_device.
            std::uniform_int_distribution<> dis(1, 4); // Define the range [1, 4]

            int dice4f;
            std::cout << "Entras a la tienda, ";
            std::cout << "El tendero parece vulnerable...\nUsar persuación?(y/n): \n";

        }
                break;
        case 7: {
            std::cout << "///////////Ejercicio #7///////////\n>>\n" << std::endl;

        }
                break;
        case 8: {
            std::cout << "///////////Ejercicio #8///////////\n>>\n" << std::endl;
            int out = 1 % 1;
            std::cout << out;

        }
                break;
        case 9: {
            std::cout << "///////////Ejercicio #9///////////\n>> Mensaje a los 60segs\n" << std::endl;

            int displayCounter = 60;
            bool onTimer = true;

            while (onTimer) {
                
                std::cin.get();
                std::cout << "Deberías apurarte, quedan sólo " << displayCounter << " segundos..." << std::endl;
                displayCounter -= 10;
                if (displayCounter <= 0) {
                    std::cin.get();
                    std::cout << "Se acabó el tiempo..." << std::endl;
                    std::cin.get();
                    onTimer = false;
                    
                }                
            }
        }
                break;
        case 10: {
            system("cls");
            std::cout << "///////////Ejercicio #10///////////\n>> Números primos\n" << std::endl;

            int userInput;
            bool esPrimo;

            std::cout << "Rápido! El portal se va a cerrar si no ingresamos al menos un número primo! Cuál será...?\n(ingresar un número) ";
            std::cin >> userInput;

            if (userInput <= 1) {
                esPrimo = false; // 0 and 1 are not prime numbers
            }
            if (userInput <= 3) {
                esPrimo = true; // 2 and 3 are prime numbers
            }
            if (userInput % 2 == 0 || userInput % 3 == 0) {
                esPrimo = false; // multiples of 2 and 3 are not prime
            }

            for (int i = 5; i * i <= userInput; i += 6) {
                if (userInput % i == 0 || userInput % (i + 2) == 0) {
                    esPrimo = false; // check divisibility from 5 to sqrt(num)
                }
            }

            if (esPrimo == false) {
                std::cout << "\nEl portal explota con una violenta detonación. Tus tímpanos revientan, y en total silencio ves a tu compañero desintegrarse como una nube de polvo" << std::endl;
            }
            else {
                std::cout << "\nEl portal dibuja el número " << userInput << " grande en su centro y comienza a dejar ver lo que hay del otro lado. Pensás si avanzar es verdaderamente algo positivo..." << std::endl;

            }
        }
                break;
        case 11: {
            std::cout << "///////////Ejercicio #11///////////\n>> Múltiplos de 3\n" << std::endl;

            int counter = 0;
            std::string multiplos;

            for (int i = 1; i < 101; ++i) {
                if (i % 3 == 0) {
                    counter += 1;
                    multiplos += std::to_string(i) + ", ";

                }
            }
            std::cout << "La cantidad de múltiplos es : " << counter << "\n" << multiplos;
        }
                break;
        case 12: {
            std::cout << "///////////Ejercicio #12///////////\n>> Contraseña\n" << std::endl;

            std::string userInput;
            std::string contrasenia = "Password";
            int intentos = 1;
            bool trying = true;

            while (trying) {

                std::cout << "Ingresar contraseña: " << std::endl;
                std::cin >> userInput;

                if (userInput == contrasenia) {
                    trying = false;
                    std::cout << "Contraseña correcta! Acceso otorgado" << std::endl;
                }
                else {
                    intentos += 1;
                    if (intentos > 3) {
                        std::cout << "Máximos intentos rechadazos. Acceso denegado" << std::endl;
                        break;
                    }
                    std::cout << "Contraseña incorrecta. Intento " << intentos << " de 3" << std::endl;
                }
            }

        }
                break;
        case 13: {
            std::cout << "///////////Ejercicio #13///////////\n>> Número reverso\n" << std::endl;

            int numero;

            std::cout << "Ingresar número a revertir: ";
            std::cin >> numero;

            std::string numeroString = std::to_string(numero);
            reverse(numeroString.begin(), numeroString.end());
            std::cout << "\n" << numeroString;
        }
                break;
        case 14: {

        }
                break;
        case 15: {
            std::cout << "///////////Ejercicio #15///////////\n>> Pirámide de asteriscos\n" << std::endl;

            int escalones;
            std::string escalera;

            std::cout << "Has pedido levantar esta pirámide, mortal. Cuántos escalones tendrá?: ";
            std::cin >> escalones;

            for (int i = 0; i < escalones; ++i) {

                int counter = 0;
                while (counter < i) {
                    escalera += "x";
                    ++counter;
                }
                escalera += "x\n"; // suma una 'x' y un enter al string escalera
            }
            std::cout << escalera;
        }
                break;
        default:
            std::cout << "Tiene que ser un número del 1 al 15, o 0 para salir: ";
        }
        
    }
    return 0;
}
