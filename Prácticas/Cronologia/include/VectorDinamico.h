#ifndef VectorDinamico_h
#define VectorDinamico_h
/**
    @file VectorDinamico.h

     @brief Definición del contenedor VectorDinamico
 */

 /**

\mainpage
		T.D.A Cronología realizado para la asignatura Estructura de Datos\n
		Autor: Carlos Sánchez Páez\n
		Curso 2017-2018\n
		Universidad de Granada

*/

#include <string>
using namespace std;
template <class T>
/**
    @brief T.D.A Vector Dinámico.\n
		Un vector es una colección de objetos accesibles mediante un índice. Alojar este tipo de dato en memoria dinámica favorece muchísmo la eficiencia
		de nuestro programa, ya que nos da la libertad de crear o destruir posiciones según las necesitemos o no. Este T.D.A tiene el objetivo de facilitar
		el uso de los vectores dinámicos, evitando confusiones al realizar operaciones con punteros.

		@author Carlos Sánchez Páez
		@date Octubre 2017
  */
class VectorDinamico{
	/**
			@page 	repcConjunto Rep de los TDA
			@section invConjunto Invariante de representación de VectorDinamico
					El invariante de representación es que el tamaño debe ser siempre >=0.

			@section faConjunto Función de abstracción de VectorDinamico
				Un objeto válido @e rep de T.D.A Vector Dinámico representa una colección de objetos almacenados de forma contigua a la que podemos acceder mediante el operador de indexación.

	*/
	private:

		T *vector;

		int tam;

		void Liberar();

		void Reservar(const int size);

		void Copiar(const VectorDinamico<T> &otro);

		void Redimensiona(const int size);

		void Swap(const int a,const int b);

	public:
		/**
			@brief Constructor sin parámetros.
			@post Hace que el puntero vector apunte a 0.
		*/
		VectorDinamico<T>();
		/**
			@brief Constructor de copia.
			@param otro : vector modelo para la copia.
		*/
		VectorDinamico<T>(const VectorDinamico &otro);
		/**
			@brief Destructor
			@post Libera la memoria dinámica reservada por el vector y hace que el puntero apunte a 0.
		*/
		~VectorDinamico<T>();
		/**
			@brief Función que vacía el vector, pero sin borrarlo.
		*/

		void Vaciar();

		/**
			@brief Sobrecarga del operador [].
			@pre índice debe ser menor al tamaño del vector.
			@param indice Posición del elemento a recuperar.
			@return Devuelve el elemento del vector en la posición "indice"
		*/
		T &operator[](const int indice) const;
		/**
			@brief Sobrecarga del operador +=. Inserta un elementos al final del vector.
			@param elemento : elemento a insertar al final del vector.
		*/
		void operator+=(const T &elemento);
		/**
			@brief Sobrecarga del operador =
			@param otro : Vector que tomar como modelo.
		*/
		VectorDinamico<T> &operator=(const VectorDinamico<T> &otro);
		/**
			@brief Función que devuelve el tamaño actual del vector.
			@return Tamaño del vector (int)
		*/
		int GetTamanio() const;

		/**
			@brief Función que ordena las componentes del vector de menor a mayor.
			@pre El vector no debe estar vacío.
		*/

		void Ordenar();

};

#include "../src/VectorDinamico.tpp"

#endif
