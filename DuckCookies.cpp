#include <iostream>
using namespace std;

struct details
{
    std::string name;
    int price;
    int code;
    int qty;
};

struct cookit_user
{
    int user_id;
    std::string name;
    std::string email;
};

struct order_item
{
    int cookie_flavor;
    int number_of_cookies;
};

struct cookie_order
{
    int order_id;
    std::string user;
    struct order_item order_item;
};

void print_inventory(details item[])
{
    int n, i;
    n = 4;

    printf(" ***** INVENTARIO ***** \n");
    printf("---------------------------------- \n");
    printf("S.N.| NOMBRE | CODIGO | CANTIDAD | PRECIO \n");
    printf("------------------------ \n");

    for (i = 0; i < n; i++)
        std::cout << i + 1 << " " << item[i].name << " " << item[i].code << " " << item[i].qty << " " << item[i].price << std::endl;
    printf("---------------------------");
}

void consume_cookie_inventory(details item[], int flavor, int consumed_quatity)
{
    int temp = item[flavor].qty;
    item[0].qty = temp - consumed_quatity;
}

void print_user(cookit_user user)
{

    std::cout << "\n Tu usuario es: " << user.name << "\n Tu correo es: " << user.email << endl;
}

void print_cookie_order(cookie_order order)
{
    std::string flavor_string;
    if (order.order_item.cookie_flavor == 1)
    {
        flavor_string = "Galleta de chocolate";
    }
    else if (order.order_item.cookie_flavor == 2)
    {
        flavor_string = "Vainilla";
    }
     else if (order.order_item.cookie_flavor == 3)
    {
        flavor_string = "Galleta de azucar";
    }
     else if (order.order_item.cookie_flavor == 4)
    {
        flavor_string = "Brownie";
    }
    // TODO
    else 
    {
        flavor_string = "?";
    }
    std::cout << "\n * " << order.order_id << " " << order.user << " -- " << flavor_string << " x " << order.order_item.number_of_cookies << "\n\n";
}

void cookie_order_function()
{
    int cookie_type;
    int cookie_quantity;
    string reorder_bool;

    cout << "" << endl;
    cout << "Que sabor de Galleta quieres ordenar ( 1 = Galleta de chocolate, 2 = Galleta de vainilla, 3 = Galleta de azucar, 4 = Brownie)" << endl;
    cin >> cookie_type;
    cout << "Cuantas Galletas quieres? (1-100)" << endl;
    cin >> cookie_quantity;

    order_item item[500];
    item[1].cookie_flavor = cookie_type;
    item[1].number_of_cookies = cookie_quantity;

    cookie_order order[100];
    order[1].user = "GuestUser";
    order[1].order_item = item[1];
    order[1].order_id = rand() % 100000;

    print_cookie_order(order[1]);

    // consume_cookie_inventory(item, 0, 25);

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

    int i = 0;

    cookit_user user[500];
    user[i].name = usuario;
    user[i].email = email;
    user[i].user_id = rand() % 100000;

    std::cout << "---- USUARIO CREADO ----- \n";
    print_user(user[i]);
}

void menu_galletas()
{
    cout << "==================" << endl;
    cout << "\n MENU" << endl;
    cout << "1. Galleta de chocolate $100" << endl;
    cout << "2. Vainilla $120" << endl;
    cout << "3. Galleta de azucar $90" << endl;
    cout << "4. Brownie $200 \n"
         << endl;
    cout << "==================" << endl;
}

void main_menu_function(details item[])
{
    // Initialize Variables
    int entrada_de_usuario;

    // Menu principal
    cout << "\n --Menu principal--" << endl;
    cout << "0: Ver menu" << endl;
    cout << "1: Crear usuario " << endl;
    cout << "2: Crear nueva orden" << endl;
    cout << "3: Ver historial de ordenes" << endl;
    cout << "4: Crear analiticos" << endl;
    cout << "5: Ver inventario de galletas" << endl;
    cout << "6. Salir del menu" << endl;

    cout << "\n Entrada de usuario:" << endl;
    cin >> entrada_de_usuario;

    if (entrada_de_usuario == 0)
    {
        menu_galletas();
        main_menu_function(item);
    }
    // crear usuario
    else if (entrada_de_usuario == 1)
    {
        crear_usuario_function();
        main_menu_function(item);
    }
    // crear nueva orden
    else if (entrada_de_usuario == 2)
    {
        cookie_order_function();
        main_menu_function(item);
    }
    // Ver historial
    else if (entrada_de_usuario == 3)
    {
        cout << "" << endl;
        main_menu_function(item);
    }
    // crear analiticos
    else if (entrada_de_usuario == 4)
    {
        cout << "" << endl;
        main_menu_function(item);
    }
    // ver inventario de galletas
    else if (entrada_de_usuario == 5)
    {
        print_inventory(item);
        main_menu_function(item);
    }
    // Exit menu
    else if (entrada_de_usuario == 6)
    {
        cout << "Gracias por comprar en Duckcookies. Cerrando programa \n"
             << endl;
    }
    else
    {
        cout << "Error lo ingresado no es valido. (Cerrando programa) \n"
             << endl;
    }
}

int main()
{
    struct details item[4];
    item[0].name = "Galleta de chocolate";
    item[0].price = 100;
    item[0].code = 0001;
    item[0].qty = 100;

    item[1].name = "Vainilla";
    item[1].price = 120;
    item[1].code = 0002;
    item[1].qty = 50;

    item[2].name = "Galleta de azucar ";
    item[2].price = 90;
    item[2].code = 0003;
    item[2].qty = 50;

    item[3].name = "Brownie";
    item[3].price = 200;
    item[3].code = 0004;
    item[3].qty = 15;

    main_menu_function(item);

    return 0;
}
