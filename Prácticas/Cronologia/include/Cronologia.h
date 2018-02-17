#ifndef CRONOLOGIA_H
#define CRONOLOGIA_H

/**
    @file Cronologia.h

     @brief Definición del T.D.A Cronologia
 */

#include <stdlib.h>     /* atoi */
#include <iostream>
#include <string>
#include <fstream>
#include "FechaHistorica.h"
using namespace std;
  /**
    @brief T.D.A Cronología.\n
  	 Una Cronología es una abstracción formada por una colección de Fechas Históricas.
  		@author Carlos Sánchez Páez
  		@date Octubre 2017
    */
class Cronologia{
  /**
  @page 	repcConjunto Rep de los TDA
      @section invConjunto Invariante de representación de Cronología
          El invariante de representación es que la Cronología debe tener al menos un elemento.

      @section faConjunto Función de abstracción de Cronología
        Un objeto válido @e rep de T.D.A Vector Dinámico representa una colección de Fechas Históricas ordenadas de menor a mayor.

  */
  private:

    VectorDinamico<FechaHistorica> *vector;

    void Liberar();

    void Copiar(const Cronologia &otra);

    int DevuelvePosicion(int anio)const;

    void Ordena();


  public:

    /**
        @brief Constructor sin parámetros. No crea nada.
    */
    Cronologia();

    /**
        @brief Constructor con un parámetro.
        @param *archivo : Archivo para extraer los datos.
        @post Importa los datos del archivo al objeto.
    */
    Cronologia(char *archivo);

    /**
      @brief Constructor de copia.
      @post Crea una copia idéntica al objeto pasado como parámetros
      @param otra Modelo a tomar para la copia.
    */
    Cronologia(const Cronologia &otra);
    /**
      @brief Destructor
      @post Si hay elementos, los elimina y deja el vector a 0.
    */
    ~Cronologia();
    /**
      @brief Método que recibe un archivo y construye el objeto a partir de él.
      @param *nombre : Archivo para extraer los datos.
      @pre El archivo debe contener datos con un formato válido (# para separar años y acontecimientos y salto de línea para una nueva FechaHistórica)
    */
    void Importar(char* nombre);
    /**
      @brief Método consultor del tamaño
      @return Tamaño del objeto (número de Fechas Históricas contenidas)
    */
    int GetTamanio() const;
    /**
      @brief Sobrecarga del operador de indexación
      @return Fecha Histórica de la posición indicada.
      @param indice Posición a devolver.
    */
    FechaHistorica &operator[](const int indice)const;
    /**
      @brief Método que obtiene una cronología entre dos años.
      @pre desde debe ser menor que hasta.
      @return Cronología en el intervalo indicado. Si no existe el año exacto, la hace tomando los límites más cercanos a los indicados.
      @param desde : Año de comienzo.
      @param hasta : Año final.
    */

    Cronologia GetSubcronologia(int desde, int hasta);
    /**
      @brief Método que devuelve una Cronología a través de una key (palabra clave)
      @param filtro : palabra clave a buscar
    */
    Cronologia GetSubcronologiaPalabraClave(string filtro);
    /**
      @brief Sobrecarga del operador +=
      @param fecha : Fecha Histórica a añadir al objeto.
      @post Añade el parámetro a la Cronología.
    */
    void operator+=(const FechaHistorica &fecha);
    /**
      @brief Sobrecarga del operador de asignación
      @post Crea una copia exacta del parámetro.
      @param otra : Objeto a usar como modelo.
    */
    Cronologia &operator=(const Cronologia &otra);
    /**
      @brief Sobrecarga del operador +
      @param otra : Cronología a añadir.
      @return Cronología unión ordenada de this y el parámetro.
    */
    Cronologia operator+(const Cronologia &otra);

};



#endif
