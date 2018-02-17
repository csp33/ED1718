

template <class C>
void Cola<C>::Liberar() {
  //Tengo que ir eliminando desde el comienzo
  Celda <C> *auxiliar;
  while (!Vacia()) { //Mientras haya algún elemento
    auxiliar = primera;
    primera = primera->next;
    delete auxiliar;
  }
  //Primera ya vale 0. Ponemos ultima a 0 para mantener la consistencia
  ultima = 0;

}

template <class C>
void Cola<C>::Copiar (const Cola<C> &otra) {
  if (otra.Vacia()) {
    primera = 0;
    ultima = 0;
  }
  else {
    //Inicializamos la primera
    primera = new Celda <C>;
    primera->dato = otra.primera->dato;
    //Hago esta asignación por si la Cola a copiar tiene un solo elemento.
    ultima = primera;
    Celda<C> *auxiliar = otra.primera;
    while (auxiliar->next != 0) {
      auxiliar = auxiliar->next;
      ultima->next = new Celda<C>;
      ultima = ultima->next;
      ultima->dato = auxiliar->dato;
    }
    ultima->next = 0; //Para marcar el final
  }
}

template <class C>
void Cola<C>::Crear() {
  primera = new Celda<C>;
  ultima = new Celda<C>;
}


template <class C>
Cola<C>::Cola() {
  primera = 0;
  ultima = 0;
}

template <class C>
Cola<C>::Cola (const Cola<C> &otra) {
  Crear();
  Copiar(otra);
}

template <class C>
Cola<C>::~Cola () {
  Liberar();
}

template <class C>
void Cola<C>::operator+=(const C &elemento) {
  Celda <C> * auxiliar = new Celda <C>;
  auxiliar->dato = elemento;
  auxiliar->next = 0;
  if (Vacia()) {
    primera= auxiliar;
    ultima= auxiliar;
  }
  else {
    ultima->next = auxiliar;
    ultima = auxiliar;
  }
}

template <class C>
Cola<C> &Cola<C>::operator=(const Cola<C> &otra) {
  if(this != &otra){
      Liberar();
      Crear();
      Copiar(otra);
  }
  return *this;
}
template <class C>
C Cola<C>::SacarFrente () {
  assert(!Vacia());
  Celda<C> *auxiliar = primera;
  C resultado;
  resultado = primera->dato;
  primera = primera->next;
  delete auxiliar;
  if (Vacia())
    ultima = 0;
  return resultado;
}


template <class C>
C Cola<C>::MirarFrente () const {
  assert(!Vacia());
  return primera->dato;
}

template <class C>
bool Cola<C>::Vacia () const {
  return primera == 0;
}

template <class C>
int Cola<C>::GetTamanio() const {
  int tam = 0;
  if (!Vacia()) {
    tam++;
    Celda<C> *aux = primera;
    while (aux->next != 0){
      tam++;
      aux=aux->next;
    }
  }
  return tam;
}
template <class C>
void Cola<C>::Vaciar () {
  Liberar();
  primera = 0;
  ultima = 0;
}
