/*******Carlos Sánchez Páez***************/
/*******DNI ------------ *****************/
/********* 2 A (A2) **********************/

#include <iostream>
#include <set>
#include <climits>
#include <ctime>
#include <cstdlib>
using namespace std;

/**
 * @brief Imprime un conjunto de tipo T sobre el flujo de salida
 * @param s: flujo de salida. Es MODIFICADO
 * @param l: el conjunto con los elementos a imprimi
 * */
template <class T>
ostream & operator<<(ostream & s, const set<T> & c) {

	typename set<T>::const_iterator i;

	for (i = c.begin(); i != c.end(); i++)
		s << (*i) << " ";

	return s;
}

/**
 * @brief Inicializar el generador de numero aleatorios
 *        Esta funcion debe ser llamada antes de usar rand
**/

void InicializarSemilla() {
	srand(time(0));
}

/**
 * @brief Genera numero enteros positivos aleatorios en el rango [min,max]
**/

int generaEntero(int min, int max) {
	int tam = max - min + 1;
	return ((rand() % tam) + min);
}

/*****************************************************************************/

/**
	@brief Obtiene la unión de dos conjuntos de enteros.
*/
set<int> obtenerUnion(const set<int> &uno, const set<int> &otro) {
	set<int> resultado;
	set<int>::const_iterator it;
	//Inserto el primer set.
	for (it = uno.begin(); it != uno.end() ; ++it)
		resultado.insert(*it);
	//Inserto el segundo set.
	for (it = otro.begin() ; it != otro.end() ; ++it)
		resultado.insert(*it);
	return resultado;
}

/**
	@brief Obtiene la diferencia simétrica de dos conjuntos de enteros.
*/
set<int> obtenerDiferenciaSimetrica(const set<int> &uno, const set<int> &otro) {
	set<int>::const_iterator it;
	set<int> resultado;
	for (it = uno.begin() ; it != uno.end() ; ++it)
		if (otro.count(*it) == 0)						//Si está sólo en el primero.
			resultado.insert(*it);

	for (it = otro.begin(); it != otro.end() ; ++it)
		if (uno.count(*it) == 0)						//Si está solo en el segundo.
			resultado.insert(*it);

	return resultado;
}

/**
	@brief Función que calcula los n elementos mayores de dos conjuntos.
	@param n Número de máximos a calcular.
	NOTA: si pasamos un n mayor que el tamaño de la unión de los conjuntos, optaré por devolver la propia unión, ya que ésta
		  contiene los ( union.size() ) mayores elementos del conjunto.
		  Podría también terminar el programa mediante un assert( n <= laUnion.size() ), pero me parece una forma un tanto
		  "violenta" de finalizar el programa.
*/
set<int> obtenerMayores (int n, const set<int> &uno, const set<int> &otro) {
	//Calculamos la unión para trabajar sobre un solo conjunto y poder modificarlo.
	set<int> laUnion = obtenerUnion(uno, otro);
	set<int> resultado;
	set<int>::const_iterator it;
	//Si n es mayor o igual que el tamaño de la unión, los máximos coinciden con la unión.
	if (n >= laUnion.size())
		resultado = laUnion;
	else {
		for (int i = 0; i < n; i++) {									//Lo hacemos n veces
			int max = INT_MIN;											//Reseteamos la variable cada vez que obtenemos un máximo.
			for (it = laUnion.begin() ; it != laUnion.end() ; ++it) {	//Bucle que calcula el máximo.
				if (*it > max)
					max = *it;
			}
			resultado.insert(max);										//Insertamos en el resultado.
			laUnion.erase(max);											//Eliminamos de la unión.
		}
	}
	return resultado;
}

/*****************************************************************************/

int main() {
	/*
		set<int> c;

		InicializarSemilla();

		for (int i = 0; i < 10; i++)
			c.insert(generaEntero(1, 100)); //inserta un entero generado aleatoriamente en el rango 1-100
		cout << endl << c;

	*/


	//Genero los conjuntos de ejemplo

	set<int> a, b;
	for (int i = 1; i < 6; i++)
		a.insert(i);
	b.insert(2);
	b.insert(4);
	b.insert(7);
	b.insert(9);

	cout << "Conjunto A: " << a << endl;
	cout << "Conjunto B: " << b << endl;

	set<int> laUnion;
	laUnion = obtenerUnion(a, b);
	cout << "La union de A y B es " << laUnion << endl;

	set<int> laDiferenciaSimetrica;
	laDiferenciaSimetrica = obtenerDiferenciaSimetrica(a, b);
	cout << "La diferencia simétrica de A y B es " << laDiferenciaSimetrica << endl;

	set<int> maximos = obtenerMayores(5, a, b);
	cout << "Para n = 5, el conjunto de máximos de A y B es " << maximos << endl;


}
