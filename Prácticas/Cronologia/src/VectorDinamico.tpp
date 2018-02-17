/**
    @file VectorDinamico.cpp

    * @brief Implementación de la clase Vector Dinámico
 */
#include <cassert>
template <class T>

/*************Métodos privados***********/

void VectorDinamico<T>::Liberar(){
  if(vector!=0)
    delete []vector;
  vector=0;
}

template <class T>
void VectorDinamico<T>::Reservar(const int size){
  vector=new T[size];
  tam=size;
}

template <class T>
void VectorDinamico<T>::Copiar(const VectorDinamico<T> &otro){
  Reservar(otro.GetTamanio());
  for(int i=0;i<otro.GetTamanio();i++)
    vector[i]=otro[i];
}

template <class T>
void VectorDinamico<T>::Redimensiona(const int size){
  assert(size>tam);
  if(vector!=0){   //Si se ha creado
    T *nuevo= new T [size];
    for(int i=0;i<tam;i++)
      nuevo[i]=vector[i];
    Liberar();
    vector=nuevo;
  }
  else
    vector=new T [size];
  tam=size;
}

template <class T>
void VectorDinamico<T>::Swap(const int a,const int b){
  T temp;
  temp=vector[a];
  vector[a]=vector[b];
  vector[b]=temp;
}

/***********************************************************/


/*******************Métodos públicos************************/

////////////Constructores////////

template <class T>
VectorDinamico<T>::VectorDinamico(){
  vector=0;
  tam=0;
}

template <class T>
VectorDinamico<T>::VectorDinamico(const VectorDinamico<T> &otro){
  Copiar(otro);
}

///////////////////////////////////

/////////Destructor////////////////

template <class T>
VectorDinamico<T>::~VectorDinamico(){
  Liberar();
}

//////////////////////////////////

////////////Consultores/////////////

template <class T>
int VectorDinamico<T>::GetTamanio() const{
  return tam;
}

///////////////////////////////////////////

/////////////Modificadores//////////////

template <class T>
void VectorDinamico<T>::Ordenar(){
  for(int i=0;i<tam;i++)
    for(int j=0;j<tam-i-1;j++)
      if(vector[i]>vector[i+1])
        Swap(i,i+1);
}

template <class T>
void VectorDinamico<T>::Vaciar(){
  tam=0;
}

///////////////////////////////////////////

//////////Sobrecarga de operadores//////////////////

/**********Indexación************/

template <class T>
T& VectorDinamico<T>::operator[](const int indice)const{
  assert(indice<tam);
  return vector[indice];
}

/**********Aritméticos************/

template <class T>
void VectorDinamico<T>::operator+=(const T &elemento){
  Redimensiona(tam+1);
  vector[tam-1]=elemento;
}

template <class T>
VectorDinamico<T>& VectorDinamico<T>::operator=(const VectorDinamico<T> &otro){
  if(this!=&otro){
    Liberar();
    Copiar(otro);
  }
  return *this;
}
