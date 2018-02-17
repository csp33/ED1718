#ifndef VectorDinamico_h
#define VectorDinamico_h
/**
    @file VectorDinamico.h

     @brief Definición del contenedor VectorDinamico
 */

 /**

\mainpage
		T.D.A PilaMax realizado para la asignatura Estructura de Datos\n
		Autores: Carlos Sánchez Páez y José Baena Cobos\n
		Curso 2017-2018\n
		Universidad de Granada

*/

#include <string>
using namespace std;
template <class T>
/**
    @brief T.D.A VectorDinamico.\n
		Un vector es una colección de objetos accesibles mediante un índice. Alojar este tipo de dato en memoria dinámica favorece muchísmo la eficiencia
		de nuestro programa, ya que nos da la libertad de crear o destruir posiciones según las necesitemos o no. Este T.D.A tiene el objetivo de facilitar
		el uso de los vectores dinámicos, evitando confusiones al realizar operaciones con punteros.

		@author Carlos Sánchez Páez
	 	@author José Baena Cobos
		@date Noviembre 2017
  */
class VectorDinamico{

	private:

		T *vector;

		int tam;

		void Liberar();

		void Reservar(const int size);

		void Copiar(const VectorDinamico<T> &otro);

		void Redimensiona(const int size);

		void Swap(const T a,const T b);

	public:
		/**
			@brief Constructor sin parámetros.
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
			@brief Sobrecarga del operador --. Elimina el último elemento del vector.
		*/
		void operator--();
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

		/**
			@brief Función que busca un elemento existe en el vector.
			@return Posición del elemento.
		*/
		int Buscar (const T &elemento) const ;

};

#include "../src/VectorDinamico.tpp"

#endif
