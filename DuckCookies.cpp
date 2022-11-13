// Your First C++ Program

#include <iostream>
using namespace std;
int main() {
    //Menu principal
    int entrada_de_usuario;
    cout<<"Menu principal" << endl;
    cout<<"0: Ver menu" << endl;
    cout<<"1: Crear usuario " <<endl;
    cout<<"2: Crear nueva orden"<<endl;
    cout<<"3: Ver nueva historial"<<endl;
    cout<<"4: Crear analiticos"<<endl;
    cin>> entrada_de_usuario;
    cout<< entrada_de_usuario;
    // Menu
    if (entrada_de_usuario==0 ) 
    cout<<"" << endl;
    cout<<"MENU" << endl;
    cout<<"Galleta de chocolate $100" << endl;
    cout<<"Vainilla $120" << endl;
    cout<<"Oatmeal Raisin $90" << endl;
    cout<<"Brownie $200" << endl;
    return 0;
}