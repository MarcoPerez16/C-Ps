#include "Error.h"
// Implementamos la clase Error.h en Error.cpp
Error::Error(){
    this->mes = "";
    this->tiempo = "";
    this->dia = 0;
    this->ip = "";
    this->parIp1 = 0;
    this->parIp2 = 0;
    this->parIp3 = 0;
    this->parIp4 = 0;
    this->parIp5 = 0;
    this->razon = "";
}

Error::Error(int parIp1, int parIp2, int parIp3, int parIp4, int parIp5){
    this->mes = "";
    this->tiempo = "";
    this->dia = 0;
    this->ip = "";
    this->parIp1 = parIp1;
    this->parIp2 = parIp2;
    this->parIp3 = parIp3;
    this->parIp4 = parIp4;
    this->parIp5 = parIp5;
    this->razon = "";
}

Error::Error(string mes, int dia, string tiempo, string ip, int parIp1, int parIp2, int parIp3, int parIp4, int parIp5 , string razon){
    this->mes = mes;
    this->tiempo = tiempo;
    this->dia = dia;
    this->ip = ip;
    this->parIp1 = parIp1;
    this->parIp2 = parIp2;
    this->parIp3 = parIp3;
    this->parIp4 = parIp4;
    this->parIp5 = parIp5;
    this->razon = razon;
}

string Error::getMes(){
    return mes;
}

string Error::getIp(){
    return ip;
}

string Error::getRazon(){
    return razon;
}

string Error::getTiempo(){
    return tiempo;
}

int Error::getDia(){
    return dia;
}

int Error::getParIp1(){
    return parIp1;
}

int Error::getParIp2(){
    return parIp2;
}

int Error::getParIp3(){
    return parIp3;
}

int Error::getParIp4(){
    return parIp4;
}

int Error::getParIp5(){
    return parIp5;
}

string Error::getError(){
    return  mes + ' ' + to_string(dia) + ' ' + tiempo + ' ' + ip + ' ' + razon; 
}

void Error::setMes(string mes){
    this->mes = mes;
}

void Error::setIp(string ip){
    this->ip = ip;
}

void Error::setRazon(string razon){
    this->razon = razon;
}

void Error::setTiempo(string tiempo){
    this->tiempo = tiempo;
}

void Error::setDia(int dia){
    this->dia = dia;
}

void Error::setParIp1(int parIp1){
    this->parIp1 = parIp1;
}

void Error::setParIp2(int parIp2){
    this->parIp2 = parIp2;
}

void Error::setParIp3(int parIp3){
    this->parIp3 = parIp3;
}

void Error::setParIp4(int parIp4){
    this->parIp4 = parIp4;
}

void Error::setParIp5(int parIp5){
    this->parIp5 = parIp5;
}

