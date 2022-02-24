// Marco Uriel Pérez Gutiérrez A01660337
// Mauricio Juárez Sánchez A01660336
// Fecha : Lunes 11 de octubre del 2021
// Programa donde leemos un archivo que contiene errores registrados , los guardamos en una lista
// ligada con objetos de la clase Error , el usuario ingresa de que IP incial a final quiere los errores, 
// después los imprimimos y por último, los guardamos en un archivo nuevo llamado Registro.txt

// ADVERTENCIA: Para correr este programa es necesario ir al archivo ListaLigada.cpp y la función
// crearArchivo() y poner la dirección donde se quiera crear el archivo con los errores.

using namespace std;
#include <iostream>
#include <fstream>
#include <sstream>
#include "Error.h"
#include "ListaLigada.cpp"

int main(){
    // Primero leemos archivo.txt y con ayuda de ifstream e istringstream leemos todo el archivo
    // Con la clase Error creada, guardaremos cada error en un objeto de la clase Error
    // Todos estos objetos los guardaremos en una lista ligada llamada datos

    ifstream archivo("bitacora.txt");
    string mes, dia, tiempo, ip, parIp1, parIp2, parIp3, parIp4, parIp5, razon;
    ListaLigada<Error> datos;
    string linea;

    while(getline(archivo, linea)){
        istringstream  parser(linea);

        getline(parser, mes, ' ');
        getline(parser, dia, ' ');
        getline(parser, tiempo, ' ');
        getline(parser, ip, ' ');
        getline(parser, razon);

        istringstream  ss(ip);
        getline(ss, parIp1, '.');
        getline(ss, parIp2, '.');
        getline(ss, parIp3, '.');
        getline(ss, parIp4, ':');
        getline(ss, parIp5);

        Error error = Error(mes, stoi(dia), tiempo, ip, stoi(parIp1),  stoi(parIp2), stoi(parIp3), stoi(parIp4), stoi(parIp5) , razon);
        datos.agregarAlFinal(error);
    }

    // Ordenanamos nuestro vector con todos los errores leidos del archivo
    // Utilizamos el algoritmo Merge Sort ya que es muy eficiente
    datos.ordenarLista();
    datos.crearArchivo();
    
    // Pedimos al usuario las IPs inicial y final para obtener el conjunto de errores que él desee
    // Los errores se guardaran en otra lista ligada llamada registro
    string IP1, IP2;
    cout << "Ingresa las IPS completas :)" << endl;
    cout << "Dame IP inicial: " ;
    cin >> IP1;
    istringstream ip1(IP1);
    getline(ip1, parIp1, '.');
    getline(ip1, parIp2, '.');
    getline(ip1, parIp3, '.');
    getline(ip1, parIp4, ':');
    getline(ip1, parIp5);
    Error eip1 = Error(stoi(parIp1), stoi(parIp2), stoi(parIp3), stoi(parIp4), stoi(parIp5));

    cout << "Dame IP final: " ;
    cin >> IP2;
    istringstream ip2(IP2);
    getline(ip2, parIp1, '.');
    getline(ip2, parIp2, '.');
    getline(ip2, parIp3, '.');
    getline(ip2, parIp4, ':');
    getline(ip2, parIp5);
    Error eip2 = Error(stoi(parIp1), stoi(parIp2), stoi(parIp3), stoi(parIp4), stoi(parIp5));
   
    ListaLigada<Error> registro = datos.crearArchivoLista(eip1, eip2);

    // Imprimimos el conjunto de errores en el rando de las IPs ingresadas
    registro.imprimir();

    // Creamos el archivo nuevo llamado Registro.txt dodnde guardaremos los errores buscados por el usuario
    // El archivo que viene en esta carpeta es un ejemplo donde dimos una IP inicial y final
    registro.crearArchivo();
    
    return 0;
}