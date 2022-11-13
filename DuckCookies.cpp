#include <iostream>
using namespace std;
template<typename T, size_t n>
void print_array(T const(& arr)[n])
{
    for (size_t i = 0; i < n; i++) {
        std::cout << arr[i] << ' ';
    }
}

int main()
{
    // Menu principal
    int entrada_de_usuario;
    int orden;
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
     string usuario_local[2] = {usuario, email};
    print_array(usuario_local);
    }
    // crear nueva orden
    else if (entrada_de_usuario == 2)
    {
        cout << "" << endl;
        cout << "Que quieres ordenar" << endl;
        cin >> orden;
    }
    // Ver historial
    else if (entrada_de_usuario == 3)
    {
        cout << "" << endl;

    }
    // crear analiticos
    else if (entrada_de_usuario == 4)
    {
        cout << "" << endl;
    }
    // Exit menu
    else if (entrada_de_usuario == 5)
    {
        cout << "" << endl;
    }
    else
    {
        cout << "Error" << endl;
    }
    return 0;
}