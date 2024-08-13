/*
Un puntero es una variable que almacena la dirección de memoria de otra variable. 
La variable puntero en sí apunta a otra dirección de memoria respecto de la que almacena.
*/


#include <iostream>

void calculoNivel(int* nivelPtr, int* expPtr) {

	int baseLvlExp = 150;
	int lvlUp = (*expPtr) / baseLvlExp;

	if (lvlUp) {
		*nivelPtr += (*expPtr) / baseLvlExp;
	}

	*expPtr = (*expPtr) % baseLvlExp;

	//std::cout << *nivelPtr << std::endl;

}

int main() {
	

	int nivel = 1;
	int earnedExp = 151;

	std::cout << "Nivel inicial: " << nivel << "\nExperiencia ganada: " << earnedExp << std::endl;

	calculoNivel(&nivel, &earnedExp);			//Paso las referencias de las variables como parámetros de la funcíón, porque
												//la función en su definición usa variables dereferenciadas para operarlas.

	std::cout << "Nivel final: " << nivel << "\nExperiencia post lvl up : " << earnedExp << std::endl;

	return 0;
}




//int var = 10;
//int* ptr = &var;  // ptr holds the address of var
//int str = *ptr;

//std::cout << str << std::endl;			//Outputs 10
//std::cout << &str << std::endl;			//0000006D8F2FF7E4

//std::cout << *ptr << std::endl;			//Outputs 10
//std::cout << &*ptr << std::endl;			//0000006D8F2FF7A4
//std::cout << &ptr << std::endl;			//0000006D8F2FF7C8

//std::cout << &var << std::endl;			//0000006D8F2FF7A4
//std::cout << (ptr == &var) << std::endl;	//1
//std::cout << (*ptr == var) << std::endl;	//1
//std::cout << std::endl;
//

//int var = 10;
//int* ptr = &var;  // ptr holds the address of var
//int str = *ptr;

//std::cout << var;