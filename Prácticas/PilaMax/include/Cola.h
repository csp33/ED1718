#ifndef COLA_H
#define COLA_H

#include <cassert>
#include <iostream>
using namespace std;

/**
  @brief T.D.A Celda.\n
    Una Celda es un dato compuesto (struct) formado por un valor (dato) y un puntero a la celda siguiente (next). Esta implementación permite desplazarse por una lista de
    valores mediante el uso de punteros. Será el pilar principal para el TDA Cola.
  @author Carlos Sánchez Páez
  @author José Baena Cobos
  @date Noviembre 2017
*/
template <class C>
struct Celda{
  /**
    @brief Dato a almacenar por la celda actual.
  */
  C dato;
  /**
    @brief Puntero a la siguiente celda. 0 si es el último elemento de la lista.
  */
  Celda *next;
};
/**
    @file Cola.h
    @brief Definición del TDA Cola.
 */

/**
  @brief T.D.A Cola.\n
    Una Cola es una abstracción en la que se almacenan una serie de datos siguiendo ciertas normas:
      -> Los elementos se insertan por un extremo (fondo)
      -> Los elementos se extráen por el otro extremo (frente).
    Ésto conlleva que sea una estructura FIFO (First In First Out). . Para este modelo, implementaremos la estructura interna mediante una lista enlazada.
  @author Carlos Sánchez Páez
  @author José Baena Cobos
  @date Noviembre 2017
*/
template <class C>
class Cola{
  private:

    Celda<C> *primera;
    Celda<C> *ultima;
    void Liberar();
    void Copiar (const Cola<C> &otra);
    void Crear();

  public:
    /**
        @brief Constructor sin parámetros.
    */
    Cola<C> ();

    /**
        @brief Constructor de copia.
        @param otra : Objeto Cola a copiar en this
    */
    Cola (const Cola<C> &otra);

    /**
        @brief Destructor.
    */
    ~Cola<C> ();

    /**
        @brief Sobrecarga del operador +=.
        @param elemento : Elemento a añadir a la cola.
    */
    void operator+=(const C &elemento);

    /**
        @brief Sobrecarga del operador =.
        @param otra : Objeto Cola a copiar en this.
        @return Referencia a this (útil para concatenar igualaciones)
    */
    Cola &operator=(const Cola<C> &otra);

    /**
        @brief Saca primer elemento (frente) de la cola.
        @post El tamaño de la cola disminuye una unidad.
        @return Objeto al frente de la cola.
    */
    C SacarFrente () ;

    /**
        @brief Consulta primer elemento de la cola.
        @return Objeto al frente de la cola.
    */
    C MirarFrente () const;
    /**
        @brief Consulta si this tiene algún elemento.
        @reuturn "True" si la cola está vacia. "False" en caso contrario.
    */
    bool Vacia () const;

    /**
        @brief Consulta el tamaño de la cola.
        @return Tamaño de la cola.
    */
    int GetTamanio() const;

    /**
        @brief Vacia la cola.
        @post La cola queda sin elementos.
    */
    void Vaciar ();
};



#include "../src/Cola.tpp"

#endif
