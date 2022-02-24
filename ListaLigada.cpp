// Marco Uriel Pérez Gutiérrez A01660337
// Fecha de entrega: Lunes 11 de octubre del 2021
// Programa que crea la clase ListaLigada e implementa todos sus metodos
#include <iostream>
#include "Nodo.cpp"
#include <fstream>
#include <sstream>
using namespace std;
template <class T>

class ListaLigada{
    private: 
        Nodo<T> *head;
        Nodo<T> *tail;
        int size;
        
        // Merge es un metodo que nos ayuda en la función y metodo de ordenamiento MergeSort
        Nodo<T>* Merge(Nodo<T>* h1, Nodo<T>* h2){
            Nodo<T> *t1 = NULL;
            Nodo<T> *t2 = NULL;
            Nodo<T> *temp = NULL;
        
            // Revisamos si las listas están vacias
            if(h1 == NULL)
                return h2;
 
            if(h2 == NULL)
                return h1;
        
            t1 = h1;
        
            // Ciclo para revisar la segunda lista y merge los nodos a la lista 1 de forma ordenada
            while (h2 != NULL)
            {
                // Se guarda en t2 el head de la segunda lista
                t2 = h2;
        
                // Movemos al siguiente el head de la segunda lista
                h2 = h2->getSiguiente();
                t2->setSiguiente(NULL) ;
        
                // Si el dato es menor que el head de la primera lista agregamos el nodo al inicio
                if(h1->getDato() > t2->getDato())
                {
                    t2->setSiguiente(h1);
                    h1 = t2;
                    t1 = h1;
                    continue;
                }
        
                // Atravesamos la primer lista
                flag:
                if(t1->getSiguiente() == NULL)
                {
                    t1->setSiguiente(t2) ;
                    t1 = t1->getSiguiente();
                }
                // Atravesamos la primer lista hasta que el dato de t2 sea mayor que el siguiente de t1.
                else if((t1->getSiguiente())->getDato() <= t2->getDato())
                {
                    t1 = t1->getSiguiente();
                    goto flag;
                }
                else
                {
                    temp = t1->getSiguiente();
                    t1->setSiguiente(t2);
                    t2->setSiguiente(temp);
                }
            }
        
            // Regresa el head de la nueva lista ordenada
            return h1;
        }

        // Merge sort es una algoritmo de ordenamiento basado en la frase divide y vencerás
        // Es de complejidad O(nlog n). El algoritmo implementado aqui es recursivo y solo pide el primer 
        // nodo de la lista. Después del algoritmo la lista estará ordenada de menor a mayor.
        void MergeSort(Nodo<T> **head){
            Nodo<T> *first = NULL;
            Nodo<T> *second = NULL;
            Nodo<T> *temp = NULL;
            first = *head;
            temp = *head;
        
            // Regresa si la lista es menor de dos valores
            if(first == NULL || first->getSiguiente() == NULL)
            {
                return;
            }
            else
            {
                // Parte la lista en dos
                while(first->getSiguiente() != NULL)
                {
                    first = first->getSiguiente();
                    if(first->getSiguiente() != NULL)
                    {
                        temp = temp->getSiguiente();
                        first = first->getSiguiente();
                    }
                }
                second = temp->getSiguiente();
                temp->setSiguiente(NULL);
                first = *head;
            }
             
            // Hacemos la filosofía divide y vencerás 
            MergeSort(&first);
            MergeSort(&second);
        
            // Hacemos Merge de las dos listas divididas y ordenamos    
            *head = Merge(first, second);
        }
    
    public:
        ListaLigada(){
            head = NULL;
            tail = NULL;
            size = 0;
        }

        // La función nos regresa el total de valores que hay en la lista
        int getSize(){
            return size;
        }

        // La funcion agregarAlFinal nos permite agregar un valor a nuestra lista ligada después del
        // último valor agregado.Recibe el valor y no regresa nada. La complejidad de la funcion es O(1)
        // La precondición es una lista ligada válida y la postoncidión es una lista con un valor más
        void agregarAlFinal(T dato){
            Nodo<T> *nodo = new Nodo<T>(dato);
            if(tail == NULL){
                head = nodo;
                tail = nodo;
            }else{
                tail->setSiguiente(nodo);
                tail = nodo;
            }
            size++;
        }

        // La funcion agregarEnPos nos permite agregar un valor a nuestra lista ligada en alguna
        // posición especifica. Recibe el valor y la posición; no regresa nada. 
        // La complejidad de la funcion es O(n)
        // La precondición es una lista ligada válida y la postoncidión es una lista con un valor más
        void agregaEnPos(T dato, int pos){
            Nodo<T> *nodo = new Nodo<T>(dato);
            if(head == NULL){
                head = nodo;
                tail = nodo;
            }else{
                Nodo<T> *temp = head;
                for(int i = 0; i < pos-1; i++){
                    temp = temp->getSiguiente();
                }
                Nodo<T> *sigPrev = temp->getSiguiente();
                temp->setSiguiente(nodo);
                nodo->setSiguiente(sigPrev);
                if(pos == size-1){
                    tail = sigPrev;
                }
            }
            size++;            
        }

        // La funcion agregarAlInicio nos permite agregar un valor a nuestra lista ligada en la posición
        // del nodo head. Recibe el valor y no regresa nada. La complejidad de la funcion es O(1).
        // La precondición es una lista ligada válida y la postoncidión es una lista con un valor más
        void agregarAlInicio(T dato){
            Nodo<T> *nodo = new Nodo<T>(dato);
            if(head == NULL){
                head = nodo;
                tail = nodo;
            }else{
                Nodo<T> *temp = head;
                nodo->setSiguiente(temp);
                head = nodo;
            }
            size++;
        }

        // La funcion update nos permite actualizar el valor en nuestra lista lidada en alguna
        // posicion expecifica, recibe el dato y la posición donde actualizará. No regresa nada y
        // la complejidad de la funcion es O(n).
        // La precondición es una lista ligada válida y la postoncidión es una lista modificada
        void update(T dato, int pos){
            Nodo<T> *nodo = new Nodo<T>(dato);
            if(head == NULL){
                head = nodo;
            }else{
                Nodo<T> *temp = head;
                for(int i=0;i<pos-1;i++){
                    temp = temp->getSiguiente();
                }
                Nodo<T> *eliminar = temp->getSiguiente();
                Nodo<T> *sigPrev = eliminar->getSiguiente();
                temp->setSiguiente(nodo);
                nodo->setSiguiente(sigPrev);
                delete eliminar;
            }           
        }

        // La funcion read recibe el  valor que se quiere buscar dentro de la lista ligada y te devuelve
        // el dato si lo encuentra. La complejidad de la funcion es O(n).
        // La precondición es una lista ligada válida y la postoncidión es nada, ya que no la modifica
        T read(T dato){
            Nodo<T> *temp = head;
            while(temp != NULL){
                if(temp->getDato() == dato){
                    return temp->getDato();
                }else{
                    temp = temp->getSiguiente();
                }
            }
            return NULL;
        }

        // La funcion readPos recibe el valor que se quiere buscar dentro de la lista ligada y te devuelve
        // el indice donde se encontró. La complejidad de la funcion es O(n).
        // La precondición es una lista ligada válida y la postoncidión es nada, ya que no la modifica
        int readPos(T dato){
            Nodo<T> *temp = head;
            int i = 0;
            while(temp != NULL){
                if(temp->getDato() == dato){
                    return i;
                }else{
                    i++;
                    temp = temp->getSiguiente();
                }
            }
            return -1;
        }

        // La funcion delete nos permite borra un valor en nuestra lista ligada. Recibe el valor
        // y lo borra si lo encuentra, no devuelve nada. La complejidad de la funcion es O(n).
        // La precondición es una lista ligada válida y la postoncidión es una lista con un valor menos
        void del(T dato){
            Nodo<T> *temp = head;
            Nodo<T> *prev = NULL;
            
            // Si está al inicio lo borra
            if (temp != NULL && temp->getDato() == dato)
            {
                head = temp->getSiguiente(); 
                delete temp;           
                size--;
                return;
            }else{
                // Si no está al inicio lo busca, si lo encuentra lo borra
                while (temp != NULL && temp->getDato() != dato){
                    prev = temp;
                    temp = temp->getSiguiente();
                }
    
                if (temp == NULL)
                    return;
                prev->setSiguiente(temp->getSiguiente());
                size--;
                delete temp;
            }
        }

        // Es una función que no regresa nada, simplemente llama la función MergeSort y ordena
        // nuestra lista ligada, la función es de orden O(nlogn) ya que utiliza el metodo de
        // MergeSort, la precondición es una lista ligada no ordenada y la poscondición es una lista ordenada
        void ordenarLista(){
            MergeSort(&head);
        }

        // Limite es una función con complejidad O(n) ya que recorre nuestra lista ligada hasta encontrar
        // un valor que sea mayor que el dato que recibe la finción como parametro. Esto es para que
        // nos ayude a crear los limites de las IPs y obtener los errores en ese rango. Recibe un
        // dato y regresa la posición donde los valores ya son mayores que ese dato.
        int limite(T dato){
            int i = 0;
            if(head == NULL){
                return -1;
            }else{
                Nodo<T> *temp = head;
                for(i = 0; i < size; i++){
                    if(temp->getDato() > dato){
                        break;
                    }else{
                        temp = temp->getSiguiente();
                    }
                    
                }
                if(i == size){
                    return -1;
                }
                else{
                    return i;
                }
            }
        }

        // La función crear archivo crea el archivo en nuestra compputadora, la direccion 
        // ingresada es la de la computadora de Marco Pérez. Es de orden O(n). No recibe nada, pero crea un
        // archivo de testo con los valores de la lista ligada
        void crearArchivo(){
            Nodo<T> *temp = head;
            ofstream file;
            file.open("C:/Users/mupgu/OneDrive/Documentos/Tec3S/PrograCodigos/Act2.3/Registro.txt");
            for(int j = 0; j < size; j++){
                file << (temp->getDato()).getError() <<"\n"; 
                temp = temp->getSiguiente();
            }
            file.close();
        }

        // La función crear archivo lista recibe la IP inicial y final, nos regresa una nueva lista ligada
        // con los valores entre el rango de esas IPs. Hace llamado a la función limite y utiliza un for 
        // para guardar los valores. Es de complejidad O(n)
        ListaLigada<T> crearArchivoLista(T datoInf, T datoSup){
            int limMenor = limite(datoInf);
            int limMayor = limite(datoSup);
            ListaLigada<T> base;
            Nodo<T> *temp = head;
            for(int i = 0; i < limMenor; i++){
                temp = temp->getSiguiente();
            }
            for(int j = 0; j < limMayor-limMenor; j++){
                base.agregarAlFinal(temp->getDato());
                temp = temp->getSiguiente();
            }
            return base;
        }


        // La función imprimir nos permite desplegar la lista ligada en la pantalla. No recibe nada y no 
        // devuelve nada. Su complejidad es O(n).
        // La precondición es una lista ligada válida y la postoncidión es nada, ya que no la modifica.
        void imprimir(){
            Nodo<T> *temp = head;
            for(int i = 0; i < size; i++){
                cout << temp->getDato() << endl;
                temp = temp->getSiguiente();
            }
        }

        
};