#include <iostream>
using namespace std;

int main()
{
    // Initialize Variables
    int entrada_de_usuario;
    int orden;

    // Menu principal
    cout << "Menu principal" << endl;
    cout << "0: Ver menu" << endl;
    cout << "1: Crear usuario " << endl;
    cout << "2: Crear nueva orden" << endl;
    cout << "3: Ver nueva historial" << endl;
    cout << "4: Crear analiticos" << endl;
    cout << "5. Exit menu" << endl;
    cin >> entrada_de_usuario;
    cout << entrada_de_usuario;

    // Menu
    if (entrada_de_usuario == 0)
    {
        cout << "" << endl;
        cout << "MENU" << endl;
        cout << "Galleta de chocolate $100" << endl;
        cout << "Vainilla $120" << endl;
        cout << "Galleta de azucar $90" << endl;
        cout << "Brownie $200" << endl;
        main();
    }
    // crear usuario
    else if (entrada_de_usuario == 1)
    {
        string usuario, email;

        cout << "\n Introduce tu nombre de usuario: ";
        cin >> usuario;

        cout << "\n introduce tu email: ";
        cin >> email;

        cout << "\n tu usuario es: " << usuario << "\n tu correo es: " << email << endl;
        main();
    }
    // crear nueva orden
    else if (entrada_de_usuario == 2)
    {
        cout << "" << endl;
        cout << "Que quieres ordenar" << endl;
        cin >> orden;
        main();
    }
    // Ver historial
    else if (entrada_de_usuario == 3)
    {
        cout << "" << endl;
        main();
    }
    // crear analiticos
    else if (entrada_de_usuario == 4)
    {
        cout << "" << endl;
        main();
    }
    // Exit menu
    else if (entrada_de_usuario == 5)
    {
        cout << "Thank you for shopping at Duck Cookies. Program Closing" << endl;
        return 0;
    }
    else
    {
        cout << "Error" << endl;
        main();
    }
    return 0;
}