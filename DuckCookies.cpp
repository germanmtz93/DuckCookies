#include <iostream>
using namespace std;

struct cookit_user
{
    int user_id;
    std::string name;
    std::string email;
};

struct order_item
{
    std::string cookie_flavor;
    int number_of_cookies;
};

struct cookie_order
{
    int order_id;
    std::string user;
    struct order_item order_item;
};

void print_user(cookit_user user)
{

    std::cout << "\n Tu usuario es: " << user.name << "\n Tu correo es: " << user.email << endl;
}

void print_cookie_order(cookie_order order)
{
    std::cout << "\n * " << order.order_id << " " << order.user << " -- " << order.order_item.cookie_flavor << " x " << order.order_item.number_of_cookies << "\n\n";
}

void cookie_order_function()
{
    string cookie_type;
    int cookie_quantity;
    string reorder_bool;

    cout << "" << endl;
    cout << "Que galletas quieres ordenar (Galleta de chocolate, Galleta de vainilla, Galleta de azucar, Brownie)" << endl;
    cin >> cookie_type;
    cout << "Cuantas Galletas quieres? (1-100)" << endl;
    cin >> cookie_quantity;

    order_item item1;
    item1.cookie_flavor = cookie_type;
    item1.number_of_cookies = cookie_quantity;

    cookie_order order1;
    order1.user = "GuestUser";
    order1.order_item = item1;
    order1.order_id = rand() % 100000;

    print_cookie_order(order1);

    // Reorder Loop
    cout << "Quieres pedir mas galletas? (Y/N)" << endl;
    cin >> reorder_bool;
    if (reorder_bool == "Y")
    {
        cout << "--Siguiente Orden--" << endl;
        cookie_order_function();
    }
}

void crear_usuario_function()
{
    string usuario, email;

    cout << "\n Introduce tu nombre de usuario: ";
    cin >> usuario;

    cout << "\n introduce tu email: ";
    cin >> email;

    cookit_user user1;
    user1.name = usuario;
    user1.email = email;
    user1.user_id = rand() % 100000;

    std::cout << "---- USER CREATED ----- \n";
    print_user(user1);
}

void menu_galletas()
{
    cout << "==================" << endl;
    cout << "\n MENU" << endl;
    cout << "Galleta de chocolate $100" << endl;
    cout << "Vainilla $120" << endl;
    cout << "Galleta de azucar $90" << endl;
    cout << "Brownie $200 \n"
         << endl;
    cout << "==================" << endl;
}

void main_menu_function()
{
    // Initialize Variables
    int entrada_de_usuario;

    // Menu principal
    cout << "\n --Menu principal--" << endl;
    cout << "0: Ver menu" << endl;
    cout << "1: Crear usuario " << endl;
    cout << "2: Crear nueva orden" << endl;
    cout << "3: Ver nueva historial" << endl;
    cout << "4: Crear analiticos" << endl;
    cout << "5. Exit menu" << endl;

    cout << "\n User Input:" << endl;
    cin >> entrada_de_usuario;

    if (entrada_de_usuario == 0)
    {
        menu_galletas();
        main_menu_function();
    }
    // crear usuario
    else if (entrada_de_usuario == 1)
    {
        crear_usuario_function();
        main_menu_function();
    }
    // crear nueva orden
    else if (entrada_de_usuario == 2)
    {
        cookie_order_function();
        main_menu_function();
    }
    // Ver historial
    else if (entrada_de_usuario == 3)
    {
        cout << "" << endl;
        main_menu_function();
    }
    // crear analiticos
    else if (entrada_de_usuario == 4)
    {
        cout << "" << endl;
        main_menu_function();
    }
    // Exit menu
    else if (entrada_de_usuario == 5)
    {
        cout << "Thank you for shopping at Duck Cookies. Program Closing \n"
             << endl;
    }
    else
    {
        cout << "Error! input not valid. (Exiting program) \n"
             << endl;
    }
}

int main()
{
    main_menu_function();
    return 0;
}