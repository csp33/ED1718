#ifndef PilaMaxVD_H
#define PilaMaxVD_H

/**
    @file PilaMaxVD.h
    @brief Definición del contenedor PilaMaxVD
 */

#include "DatoMax.h"
#include "VectorDinamico.h"
#include <cassert>
using namespace std;

/**
  @brief T.D.A PilaMaxVD.\n
    Una PilaMaxVD es una abstracción en la que se almacena un struct de tipo DatoMax en una pila (estructura en la que los datos se insertan y eliminan
    por un extremo llamado tope. Siguien el protocolo LIFO (Last In First Out). Al usar este tipo de dato, el valor máximo de la PilaMaxVD
    queda siempre actualizado en DatoMax->max. Para este modelo, implementaremos la estructura interna mediante un Vector Dinámico.
  @author Carlos Sánchez Páez
  @author José Baena Cobos
  @date Noviembre 2017
*/
class PilaMaxVD{
  private:
    VectorDinamico< DatoMax > *v;
    void Liberar();
    void Copiar(const PilaMaxVD &otra);
    int CalculaMaximo (const int &nuevo) const ;
    void Crear();

  public:
    /**
      @brief Constructor sin parámetros
    */
    PilaMaxVD();

    /**
      @brief Constructor de copia
      @param &otra : Objeto PilaMaxVD a copiar
    */
    PilaMaxVD(const PilaMaxVD &otra);

    /**
      @brief Destructor
      @post Destruye el objeto
    */
    ~PilaMaxVD();

    /**
      @brief Consultar tamaño de la pila.
      @return Tamaño de la pila
    */
    int GetTamanio() const ;

    /**
      @brief Obtener máximo de pila
      @return Tope de la pila
    */
    int GetMaximo () const ;

    /**
      @brief Saca el tope de la pila.
      @return Último dato introducido en la pila.
      @post Elimina el último dato de la pila.
    */
    int SacarTope() const;

    /**
      @brief Consultar el tope de la pila
      @return Elemento en el tope de la pila
    */
    int MirarTope() const;

    /**
      @brief Vacia la pila
      @post Libera la pila y vuelve a asignarle memoria
    */
    void Vaciar();

    /**
      @brief Comprueba si la pila está vacia
      @return "True" si la pila está vacia
    */
    bool EstaVacia () const;

    /**
      @brief Sobrecarga del operador +=
      @param aniadir : Elemento a añadir a la pila
    */
    void operator+=(const int &aniadir);

    /**
      @brief Sobrecarga del operador =
      @param &otra : Objeto PilaMaxVD a copiar en this
      @return Referencia a objeto this.
    */
    PilaMaxVD &operator= (const PilaMaxVD &otra);

};



#endif
