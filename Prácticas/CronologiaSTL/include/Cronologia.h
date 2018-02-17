#ifndef CRONOLOGIA_H
#define CRONOLOGIA_H

/**

  \mainpage
      T.D.A Cronología realizado para la asignatura Estructura de Datos\n
      Autores: Carlos Sánchez Páez y José Baena Cobos\n
      Curso 2017-2018\n
      Universidad de Granada

*/

/**
    @file Cronologia.h

     @brief Definición del T.D.A Cronologia
 */

#include <stdlib.h>     /* atoi */
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include "FechaHistorica.h"
using namespace std;

/**
@brief T.D.A Cronología.\n
 Una Cronología es una abstracción formada por una colección de Fechas Históricas.
  @author Carlos Sánchez Páez
  @author José Baena Cobos
  @date Noviembre 2017
*/
class Cronologia {

private:

  map<int, FechaHistorica> mapa;

  void Copiar(const Cronologia &otra);


public:
  /**
   * @brief Alias para llamar iterator al iterador sobre las distintas Fechas Históricas.
   */
  typedef typename map<int, FechaHistorica>::iterator iterator;
  /**
   * @brief Alias para llamar const_iterator al iterador constante sobre las distintas Fechas Históricas.
   */
  typedef typename map<int, FechaHistorica>::const_iterator const_iterator;

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
  */
  ~Cronologia();
  /**
    @brief Método que recibe un archivo y construye el objeto a partir de él.
    @param *nombre : Archivo para extraer los datos.
    @pre El archivo debe contener datos con un formato válido (# para separar años y acontecimientos y salto de línea para una nueva FechaHistórica)
  */
  void Importar(char* nombre);
  /**
   * @brief      Método que exporta el objeto a un archivo.
   *
   * @param      nombre  Nombre del archivo a crear.
   */
  void Exportar(char* nombre) const;
  /**
    @brief Método consultor del tamaño
    @return Tamaño del objeto (número de Fechas Históricas contenidas)
  */
  int GetTamanio() const;
  /**
    @brief Método que obtiene una cronología entre dos años. Si algún año no existe, toma el que está justo después para extraer la subcronología.
    @pre desde debe ser menor que hasta.
    @param desde : Año de comienzo.
    @param hasta : Año final.
    @return Cronología en el intervalo indicado. Si no existe el año exacto, la hace tomando los límites más cercanos a los indicados.

  */

  Cronologia GetSubcronologia(int desde, int hasta);
  /**
    @brief Método que devuelve una Cronología a través de una key (palabra clave)
    @param filtro : palabra clave a buscar
  */
  Cronologia GetSubcronologiaPalabraClave(string filtro);
  /**
   * @brief      Método que muestra el total de acontecimientos, el máximo y el promedio.
   */
  void MuestraEstadisticas() const;
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

  /*********Iteradores*********/
  /**
   * @brief      Iterador a la primera Fecha Histórica.
   */
  iterator begin();
  /**
   * @brief      Iterador a la última Fecha Histórica.
   */
  iterator end();
  /**
   * @brief      Iterador constante a la primera Fecha Histórica.
   */
  const_iterator begin() const;
  /**
   * @brief      Iterador constante a la última Fecha Histórica.
   */
  const_iterator end() const;
};

///////////////////Operador de flujo/////////////////////////

ostream &operator<<(ostream &flujo, const Cronologia &crono);



#endif
