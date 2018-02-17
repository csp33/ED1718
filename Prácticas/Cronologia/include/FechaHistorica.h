#ifndef FECHA_HISTORICA_H
#define FECHA_HISTORICA_H
/**
    @file FechaHistorica.h

    * @brief Definición de la clase FechaHistorica
 */

#include <iostream>
#include <string>
#include "VectorDinamico.h"
using namespace std;
/**
  *  @brief T.D.A Fecha Histórica.\n
	 Una fecha histórica es una abstracción formada por una fecha (positiva si es después de Cristo o negativa si es anterior)
	  y uno o varios acontecimientos ocurridos en esa fecha.
		@author Carlos Sánchez Páez
		@date Octubre 2017
  */

class FechaHistorica{

	/**
	@page 	repcConjunto Rep de los TDA
			@section invConjunto Invariante de representación de FechaHistorica
					El invariante de representación es que el año debe ser un valor válido entre el inicio de los tiempos y la actualidad.

			@section faConjunto Función de abstracción de FechaHistorica
				Un objeto válido @e rep de T.D.A FechaHistorica representa una estructura formada por un año y un conjunto de acontecimientos ocurridos en dicho período.

	*/
	private:

		int anio;
		VectorDinamico<string> *acontecimientos;
		void Copiar(const FechaHistorica &otra);
		void Liberar();

	public:
		/**
			@brief Constructor sin parámetros.
			@post Hace que el puntero vector apunte a 0 y el año valga 0.
		*/
		FechaHistorica();
		/**
			@brief Constructor con dos parámetros
			@param anio : Año en el que ocurrió el acontecimiento
			@param unacontecimiento : string que indica lo que ocurrió.
		*/
		FechaHistorica(const int anio,const string unacontecimiento);
		/**
			@brief Constructor con dos parámetros
			@param anio : Año en el que ocurrió el acontecimiento
			@param acontecimientos : Vector de strings con los acontecimientos ocurridos en ese año.
		*/
		FechaHistorica(const int anio,const VectorDinamico<string> vector);
		/**
			@brief Constructor de copia
			@param otra : modelo para la copia.
		*/
		FechaHistorica(const FechaHistorica &otra);

		/**
			@brief Destructor de la clase.
			@post Libera la memoria dinámica usada.
		*/
		~FechaHistorica();

		/**
			@brief Función que devuelve el año de la fecha histórica.
		*/
		int GetAnio()const;
    /**
			@brief Función que comprueba si un acontecimiento ocurrió en la fecha histórica
			@param acontecimiento : string con el acontecimiento. Puede ser una subcadena.
			@return true si ocurrió o false en caso contrario.
		*/
		bool Ocurrio(const string &acontecimiento)const;
		/**
			@brief Función para modificar el año de la fecha histórica.
			@param a : Positivo si es Después de Cristo o negativo si es anterior.
		*/
		void SetAnio(const int a);
		/**
			@brief Función que devuelve el tamaño del vector.
			@return Número de acontecimientos del objeto.
		*/
		int GetTamanio()const;
		/**
			@brief Sobracarga del operador +=
			@param acontecimiento: string a añadir.
			@post Añade el parámetro a la fecha histórica.
		*/

		void operator+=(const string &acontecimiento);
		/**
			@brief Sobrecarga del operador lógico <
			@return true si el año del objeto es menor que el del parámetro.
		*/
		bool operator<(const FechaHistorica &otra);

		/**
			@brief Sobrecarga del operador lógico >=
			@return true si el año del objeto es mayor o igual que el del parámetro.
		*/
		bool operator>=(const FechaHistorica &otra);
		/**
			@brief Sobrecarga del operador lógico >
			@return true si el año del objeto es mayor que el del parámetro.
		*/
		bool operator>(const FechaHistorica &otra);
		/**
			@brief Sobrecarga del operador lógico <=
			@return true si el año del objeto es menor o igual que el del parámetro.
		*/
		bool operator<=(const FechaHistorica &otra);
		/**
			@brief Sobrecarga del operador de asignación.
			@param otro: Fecha Histórica que tomar como modelo.
			@post Hace una copia idéntica del objeto pasado como parámetro.
		*/
		FechaHistorica &operator=(const FechaHistorica &otro);
		/**
					DOCUMENTAR
		*/
		string &operator[](const int indice)const;
};


#endif
