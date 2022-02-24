#ifndef NODO_DEFINED
#define NODO_DEFINED

// Marco Uriel Pérez Gutiérrez A01660337
// Fecha de entrega: Lunes 11 de octubre del 2021
// Programa que crea la clase Nodo e implementa todos sus metodos

#include <iostream>
template <class T>
class Nodo{
    private:
        T dato;
        Nodo<T> *siguiente;
    
    public:
        Nodo(T dato){
            this->dato=dato;
            this->siguiente=NULL;
        }

        Nodo(T dato,Nodo<T> *siguiente){
            this->dato=dato;
            this->siguiente=siguiente;
        }
        // La función nos regresa la referencia al siguiente Nodo. Complejidad O(1)
        Nodo<T>* getSiguiente(){
            return siguiente;
        }
        // La función nos permite modificar la referencia al siguiente Nodo. Complejidad O(1)
        void setSiguiente(Nodo<T> *siguiente){
            this->siguiente=siguiente;
        }
        // La función nos regresa el valor del Nodo. Complejidad O(1)
        T getDato(){
            return dato;
        }
        // La función nos permite modificar el valor del Nodo. Complejidad O(1)
        void setDato(T dato){
            this->dato=dato;
        }
};

#endif