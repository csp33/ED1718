/**
    @file PilaMaxVD.cpp
    @brief Impementación de la clase PilaMaxVD
 */

#include "PilaMaxVD.h"

  void PilaMaxVD::Liberar(){
      if(v != 0)
        delete v;
  }

  void PilaMaxVD::Copiar(const PilaMaxVD &aCopiar){
    PilaMaxVD otra(aCopiar);
      //Desapilamos en orden inverso
    PilaMaxVD pilaAux;
    for(int i=0;i<otra.GetTamanio();i++)
      pilaAux+=otra.SacarTope();
      //Desapilamos y montamos en this para que el orden sea correcto.
    for(int i=0;pilaAux.GetTamanio();i++)
      this->operator+=(pilaAux.SacarTope());
    //Otra forma: this->v=aCopiar.v;
  }

  int PilaMaxVD::CalculaMaximo (const int &nuevo) const {
    assert(!EstaVacia());
    int elMaximo;
    if(nuevo > this->GetMaximo())
      elMaximo = nuevo;
    else
      elMaximo=this->GetMaximo();
    return elMaximo;
  }


  void PilaMaxVD::Crear(){
    v=new VectorDinamico< DatoMax >;
  }


  PilaMaxVD::PilaMaxVD(){
    Crear();
  }



  PilaMaxVD::PilaMaxVD(const PilaMaxVD &otra){
    Liberar();
    Crear();
    Copiar(otra);
  }



  PilaMaxVD::~PilaMaxVD(){
    Liberar();
  }

  int PilaMaxVD::GetTamanio() const {
    return v->GetTamanio();
  }


  int PilaMaxVD::GetMaximo () const {
    return v->operator[](GetTamanio()-1).max;
  }


  int PilaMaxVD::SacarTope() const{
    int aDevolver= MirarTope();
    v->operator--();
    return aDevolver;
  }



  int PilaMaxVD::MirarTope() const{
    return v->operator[](GetTamanio()-1).dato;
  }


  void PilaMaxVD::Vaciar(){
    Liberar();
    Crear();
  }

  bool PilaMaxVD::EstaVacia () const {
    return v->GetTamanio() == 0;  //True si está vacía.
  }

  void PilaMaxVD::operator+=(const int &aniadir){
    DatoMax nuevo;
    nuevo.dato=aniadir;
    nuevo.max = EstaVacia() ? nuevo.dato : CalculaMaximo(aniadir);
    *v+=nuevo;
  }


  PilaMaxVD &PilaMaxVD::operator= (const PilaMaxVD &otra){
    if(this != &otra){
      Liberar();
      Crear();
      Copiar(otra);
    }
    return *this;
  }
