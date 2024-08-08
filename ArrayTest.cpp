#include <iostream>

/////////// ARRAYS /////////
///* Los arrays necesitan que se establezca su rango en su definición.
//Se pueden cambiar los valores almacenados accediendo a través de su ubicación 
//Si al iterarlos se intenta acceder a una ubicación fuera de su rango, tira un número random */
//
//int main(){
//
//	int arrA[5] = { 1, 2, 3, 4, 5 };	//Defino el array con su rango y los valores internos
//	int arrB[24] = { 1, 2, 3 };			//Puedo definir un array de un rango mayor a la cantidad de elementos declarados
//
//	for (int i = 0; i < 5; ++i) {
//		std::cout << arrA[i] << std::endl;	//En cada iteración, llamo el valor que está almacenado en la ubicación i del array
//	}
//
//	arrA[2] = 19;	//accedo a la ubicación 2 y cambio el valor que almacena
//
//	for (int i = 0; i < 24; ++i) {
//		std::cout << arrB[i] << std::endl;	//Si itero un array y no tiene elementos almacenados en los rangos que accedo, devuelve 0
//	}
//
//
//
//	return 0;
//}
//

/////////// VECTORES /////////
//
//#include <vector>	//Requiere importar la biblioteca de vectores
//
//int main() {
//	std::vector<int> vec;	//se declaran con el método std::, y su tipo se indica entre cocodrilos. Al declararlo, no se indica el rango
//
//	vec.push_back(1);		//a través del método push_back se agregan elementos al final
//	vec.push_back(2);
//	vec.push_back(3);
//	vec.push_back(4);
//	vec.push_back(55);
//	vec.push_back(66);
//
//	std::cout << "el tamaño del vector es " << vec.size() << " y adentro tiene estos elementos: \n";
//
//	for (int i = 0; i < 6; ++i) {			//Más abajo lo cambio y lo explico, pero no es una buena práctica hardcodear el tope de iteración de un vector
//		std::cout << vec[i] << std::endl;	//se puede acceder a los elementos de la misma manera que en los arrays
//											//Si intento acceder a valores fuera del rango tira stack overflow
//	}
//
//	vec.pop_back();								//Con el método pop_back se elimina el último elemento y se reduce el rango en 1
//	std::cout << "Acabo de usar pop_back, asique el tamaño del vector quedó en " << vec.size() << std::endl;
//	vec.erase(vec.begin()+1);					/*Con el método vec.erase se pueden eliminar elementos accediendo a ubicaciones específicas.
//												Es necesario indicar el elemento partiendo de vec.begin() en vez de usar 0 como primer elemento.*/
//	std::cout << "Ahora eliminé el elemento ubicado en la posición 1, entonces el tamaño del vector es de " << vec.size() << std::endl;
//	vec.erase(vec.begin(), vec.begin() + 2);	//Se pueden eliminar rangos separando con una coma las ubicaciones
//									
//	std::cout << "\nDespués de eliminar un rango de posiciones, el tamaño del vector es de " << vec.size() << " y adentro quedaron estos elementos: \n";
//	for (auto i = vec.begin(); i != vec.end(); ++i) {	//Es difícil establecer el tamaño de un vector justamente por la manera de declararlo, 
//		std::cout << *i << std::endl;					//agregar y eliminarle cosas. Por eso, es más práctico iterar de esta manera.
//														/*"auto" hace que c++ "se amolde" al tipo de valor del iterador i, y al trabajar con
//														vec.begin() y vec.end(), la manera de decirle "hasta acá" al for, es diciéndole que
//														"va a iterar mientras veas que no llegás al último elemento del vector. Dentro del for,
//														lo que se printea es el valor dereferenciado de memoria que contiene el iterador en ese momento*/		
//	}
//
//	return 0;
//}

/////////// LISTAS /////////
