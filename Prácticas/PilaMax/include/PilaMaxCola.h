#ifndef PilaMaxCola_H
#define PilaMaxCola_H

#include "DatoMax.h"
#include "Cola.h"
#include <cassert>
#include <iostream>
using namespace std;
/**
    @file PilaMaxCola.h
    @brief Definición del TDA PilaMaxCola.
 */

 /**
   @brief T.D.A PilaMaxCola.\n
     Una PilaMaxCola es una abstracción en la que se almacena un struct de tipo DatoMax en una pila (estructura en la que los datos se insertan y eliminan
     por un extremo llamado tope. Siguen el protocolo LIFO (Last In First Out)). Al usar este tipo de dato, el valor máximo de la PilaMaxCola
     queda siempre actualizado en DatoMax->max. Para este modelo, implementaremos la estructura interna mediante una Cola.
   @author Carlos Sánchez Páez
   @author José Baena Cobos
   @date Noviembre 2017
 */
 class PilaMaxCola{
  private:
    Cola<DatoMax> *c;
    void Liberar();
    void Copiar (const PilaMaxCola &otra);
    void Crear();
  public:
    /**
      @brief Constructor sin parámetros.
    */
    PilaMaxCola();

    /**
      @brief Constructor de copia.
      @param &otra : Objeto PilaMaxCola a copiar.
    */
    PilaMaxCola(const PilaMaxCola &otra);

    /**
      @brief Destructor.
    */
    ~PilaMaxCola();

    /**
      @brief Consultar tamaño de la pila.
      @return Tamaño de la pila.
    */
    int GetTamanio() const ;

    /**
      @brief Obtener máximo de pila.
      @return Tope de la pila.
    */
    int GetMaximo () const ;

    /**
      @brief Saca el tope de la pila.
      @return Último dato introducido en la pila.
      @post Elimina el último dato de la pila.
    */
    int SacarTope();

    /**
      @brief Consultar el tope de la pila.
      @return Elemento en el tope de la pila.
    */
    int MirarTope();

    /**
      @brief Vacia la pila.
      @post Libera la pila y vuelve a asignarle memoria.
    */
    void Vaciar();

    /**
      @brief Comprueba si la pila está vacia.
      @return "True" si la pila está vacia.
    */
    bool EstaVacia () const;

    /**
      @brief Sobrecarga del operador +=.
      @param &aniadir : Elemento a añadir a la pila.
    */
    void operator+=(const int &aniadir);

    /**
      @brief Sobrecarga del operador =.
      @param &otra : Objeto PilaMaxCola a copiar en this.
    */
    PilaMaxCola &operator= (const PilaMaxCola &otra);


 };

#endif
