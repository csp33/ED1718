#include "Cronologia.h"
#include <string>
#include <fstream>

/**
  @file Cronologia.cpp
  @brief Implementación de la clase Cronología.
*/

/**********Métodos privados*****************/

void Cronologia::Liberar(){
  if(vector!=0)
    delete vector;
  vector=0;
}

void Cronologia::Copiar(const Cronologia &otra){
  for(int i=0;i<otra.GetTamanio();i++)
    vector->operator+=(otra[i]);
}

int Cronologia::DevuelvePosicion(int anio)const{
  int pos=-1;
  for(int i=0;i<vector->GetTamanio() && pos==-1;i++){
    if(vector->operator[](i).GetAnio()==anio) //Si justo ese año existe
      pos=i;
    else if (vector->operator[](i).GetAnio()>anio)  //Si no existe, cogemos el más cercano
      pos=i-1;
    }
   return pos;
}

void Cronologia::Ordena(){
    vector->Ordenar();
}

/**********Métodos públicos*****************/

//////////////Constructores/////////////

Cronologia::Cronologia(){
  vector = new VectorDinamico<FechaHistorica>;
}
Cronologia::Cronologia(char *archivo){
  vector=new VectorDinamico<FechaHistorica>;
  Importar(archivo);
}

Cronologia::Cronologia(const Cronologia &otra){
  vector=new VectorDinamico<FechaHistorica>;
  Copiar(otra);
}

//////////////////////////////////////////////

///////////////////Destructor/////////////////

Cronologia::~Cronologia(){
  Liberar();
}

/////////////////////////////////////////////

//////////////////Consultores////////////////

Cronologia  Cronologia::GetSubcronologia(int desde, int hasta){
  Cronologia aDevolver;
  int posicion_inicial=DevuelvePosicion(desde);
  assert(posicion_inicial!=-1);
  int posicion_final=DevuelvePosicion(hasta);
  assert(posicion_final!=-1);

  for(int i=posicion_inicial;i<posicion_final+1;i++)  //+1 para que incluya el último año.
    aDevolver+=vector->operator[](i);
  return aDevolver;
}

Cronologia Cronologia::GetSubcronologiaPalabraClave(string palabra){
  Cronologia aDevolver;
  for(int i=0;i<vector->GetTamanio();i++){
    if(vector->operator[](i).Ocurrio(palabra)){
      aDevolver+=vector->operator[](i);
    }
  }
  return aDevolver;
}

int Cronologia::GetTamanio()const{
  return vector->GetTamanio();
}

//////////////////Modificadores////////////////////


void Cronologia::Importar(char* nombre){
  ifstream buffer(nombre);
  if (buffer){
    vector->Vaciar();
    while (!buffer.eof()){
      FechaHistorica fechatemp;
      string lineaentera;
      string acontemp="";
      string aniotemp;
      ///////Cojo el año y lo ajusto///////

      getline(buffer, aniotemp, '#');
      int anio = atoi(aniotemp.c_str());
      fechatemp.SetAnio(anio);

      getline(buffer,lineaentera);
      for (unsigned int i=0; i< lineaentera.length();i++){
        ////Si estoy al final de un acontecimiento o una linea
        if(lineaentera[i]!='#' && i!=lineaentera.length()-1){
          acontemp.push_back(lineaentera[i]);
        }

        else{
          fechatemp+=acontemp;
          acontemp.erase();
        }//else
      }//for

      vector->operator+=(fechatemp);  //Añado la fecha a la Cronologia
    }// while
  }
 else
     cerr<<"Fallo al abrir el archivo";
 buffer.close();
}

////////////////Sobrecarga de operadores/////////////

/*******Indexación**************/

FechaHistorica& Cronologia::operator[](const int indice)const{
  assert(indice<vector->GetTamanio());
  return vector->operator[](indice);
}
/*****************************/

/*********Aritméticos**************/

void Cronologia::operator+=(const FechaHistorica &fecha){
  vector->operator+=(fecha);
}

Cronologia& Cronologia::operator=(const Cronologia &otra){
  if(this!=&otra){
    Liberar();
    vector=new VectorDinamico<FechaHistorica>;
    Copiar(otra);
  }
  return *this;
}

Cronologia Cronologia::operator+(const Cronologia &otra){
  Cronologia aDevolver=*this;
  for(int i=0;i<vector->GetTamanio();i++)
    aDevolver+=otra[i];  //Inserto la otra cronología al final
  aDevolver.Ordena();
  return aDevolver;
}
/*****************************/
