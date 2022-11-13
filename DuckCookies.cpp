#include <iostream>
using namespace std;
int main() {
    //Menu principal
    int entrada_de_usuario;
    int correo_electronico;
    int nombre_de_usuario;
    int orden;
    cout<<"Menu principal" << endl;
    cout<<"0: Ver menu" << endl;
    cout<<"1: Crear usuario " <<endl;
    cout<<"2: Crear nueva orden"<<endl;
    cout<<"3: Ver nueva historial"<<endl;
    cout<<"4: Crear analiticos"<<endl;
    cin>> entrada_de_usuario;
    cout<< entrada_de_usuario;
    // Menu
    if (entrada_de_usuario==0 ) {
    cout<<"" << endl;
    cout<<"MENU" << endl;
    cout<<"Galleta de chocolate $100" << endl;
    cout<<"Vainilla $120" << endl;
    cout<<"Galleta de azucar $90" << endl;
    cout<<"Brownie $200" << endl;
    //crear usuario
    } else if (entrada_de_usuario==1 ) {
    cout<<"" << endl;
    cout<<"Dame el nombre de usuario" << endl;
    cin>> nombre_de_usuario;
    cout<<"Escribe tu email" << endl;
    cin>> correo_electronico;
    //crear nueva orden 
    } else if (entrada_de_usuario==2 ) {
    cout<<"" << endl;
    cout<<"Que quieres ordenar" << endl;
    cin>> orden;
    //Ver historial
    } else if(entrada_de_usuario==3 ) {
    cout<<"" << endl;

    //crear analiticos
    } else if(entrada_de_usuario==4 ) {
    cout<<"" << endl; 

    } else {
     cout<<"Error" << endl;
    }
    return 0;
}