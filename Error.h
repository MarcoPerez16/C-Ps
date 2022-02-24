#ifndef ERROR_H_DEFINED
#define ERROR_H_DEFINED
#include <iostream>
using namespace std;

// Creamos la clase Error para guardar el error leido del archivo bitacora y asi poder manipular su 
// información de forma más sencilla

class Error{
    private: 
        // Guardamos toda la información del error
        string mes, tiempo, ip, razon;
        int dia, parIp1, parIp2, parIp3, parIp4, parIp5;
    
    public:
        // Creamos 3 constructores necesarios para usar en los metodos y main
        // También creamos getters y setters de todo
        Error();
        Error(int parIp1, int parIp2, int parIp3, int parIp4, int parIp5);
        Error(string mes, int dia, string tiempo, string ip, int parIp1, int parIp2, int parIp3, int parIp4, int parIp5 , string razon);
        string getMes();
        int getDia();
        string getTiempo();
        string getIp();
        int getParIp1();
        int getParIp2();
        int getParIp3();
        int getParIp4();
        int getParIp5();
        string getRazon();
        string getError();
        
        void setMes(string mes);
        void setDia(int dia);
        void setTiempo(string tiempo);
        void setIp(string ip);
        void setParIp1(int parIp1);
        void setParIp2(int parIp2);
        void setParIp3(int parIp3);
        void setParIp4(int parIp4);
        void setParIp5(int parIp5);
        void setRazon(string razon);
        
        // Sobreescribimos 4 operadores que nos ayudarán en los metodos utilizados
        // son <, >, <=, == y <<

        bool operator < (Error error2){
            bool resultado=false;
            if(parIp1 < error2.getParIp1()){
                return true;
            }else if(parIp1 == error2.getParIp1()){
                if(parIp2 < error2.getParIp2()){
                    return true;
                }else if(parIp2 == error2.getParIp2()){
                    if(parIp3 < error2.getParIp3()){
                        return true;
                    }else if(parIp3 == error2.getParIp3()){
                        if(parIp4 < error2.getParIp4()){
                            return true;
                        }else if(parIp4 == error2.getParIp4()){
                            if(parIp5 < error2.getParIp5()){
                                return true;
                            }else {
                                return false;
                            } 
                        } else{
                            return false;
                        }
                    } else{
                        return false;
                    }
                } else{
                    return false;
                }
            } else{
                return false;
            }
            return resultado;
        }

        bool operator <= (Error error2){
            bool resultado=false;
            if(parIp1 < error2.getParIp1()){
                return true;
            }else if(parIp1 == error2.getParIp1()){
                if(parIp2 < error2.getParIp2()){
                    return true;
                }else if(parIp2 == error2.getParIp2()){
                    if(parIp3 < error2.getParIp3()){
                        return true;
                    }else if(parIp3 == error2.getParIp3()){
                        if(parIp4 < error2.getParIp4()){
                            return true;
                        }else if(parIp4 == error2.getParIp4()){
                            if(parIp5 <= error2.getParIp5()){
                                return true;
                            }else {
                                return false;
                            } 
                        } else{
                            return false;
                        }
                    } else{
                        return false;
                    }
                } else{
                    return false;
                }
            } else{
                return false;
            }
            return resultado;
        }

        bool operator > (Error error2){
            bool resultado=false;
            if(parIp1 > error2.getParIp1()){
                return true;
            }else if(parIp1 == error2.getParIp1()){
                if(parIp2 > error2.getParIp2()){
                    return true;
                }else if(parIp2 == error2.getParIp2()){
                    if(parIp3 > error2.getParIp3()){
                        return true;
                    }else if(parIp3 == error2.getParIp3()){
                        if(parIp4 > error2.getParIp4()){
                            return true;
                        }else if(parIp4 == error2.getParIp4()){
                            if(parIp5 > error2.getParIp5()){
                                return true;
                            }else {
                                return false;
                            } 
                        } else{
                            return false;
                        }
                    } else{
                        return false;
                    }
                } else{
                    return false;
                }
            } else{
                return false;
            }
            return resultado;
        }
        
        bool operator == (Error& error2){
            return razon == error2.getRazon();
        }

        friend ostream &operator<<( ostream &output, const Error &error ) { 
            output << error.mes << ' ' << error.dia << ' ' << error.tiempo << ' ' << error.ip << ' ' << error.razon; 
            return output;            
        }
};
#endif