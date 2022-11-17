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

struct line_item
{
    int cookie_flavor;
    int number_of_cookies;
};

struct cookie_order
{
    int order_id;
    std::string user;
    struct line_item line_item;
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

string flavor_int_2_str(int x)
{
    std::string flavor_string;
    if (x == 1)
    {
        flavor_string = "Galleta de chocolate";
    }
    else if (x == 2)
    {
        flavor_string = "Vainilla";
    }
    else if (x == 3)
    {
        flavor_string = "Galleta de azucar";
    }
    else if (x == 4)
    {
        flavor_string = "Brownie";
    }
    else
    {
        flavor_string = "?";
    }

    return (flavor_string);
}
void print_cookie_order(cookie_order order, details item[])
{

    std::string flavor_string = flavor_int_2_str(order.line_item.cookie_flavor);

    int flavor_int = (order.line_item.cookie_flavor) - 1;
    int total = (item[flavor_int].price) * (order.line_item.number_of_cookies);

    std::cout << "\n * " << order.order_id << " " << order.user << " -- " << flavor_string << " x " << order.line_item.number_of_cookies << "\n\n";
    std::cout << "* $" << item[flavor_int].price << " x " << order.line_item.number_of_cookies << "\n\n";
    std::cout << "*  $" << total << "\n\n";
}

void print_order_history(details item[], cookie_order orders[], int order_count)
{
    int i;

    printf(" ***** ORDER History ***** \n");
    printf("---------------------------------- \n");
    printf(" USER | LINE ITEMS | ORDER_ID \n");
    printf("------------------------ \n");

    for (i = 0; i < order_count; i++)
        std::cout << orders[i].user << " " << flavor_int_2_str(orders[i].line_item.cookie_flavor) << " " << orders[i].order_id << std::endl;
    printf("---------------------------");
}

int cookie_order_function(details item[], cookie_order orders[], int order_count)
{
    int cookie_type;
    int cookie_quantity;
    string reorder_bool;

    cout << "" << endl;
    cout << "Que sabor de Galleta quieres ordenar ( 1 = Galleta de chocolate, 2 = Galleta de vainilla, 3 = Galleta de azucar, 4 = Brownie)" << endl;
    cin >> cookie_type;
    cout << "Cuantas Galletas quieres? (1-100)" << endl;
    cin >> cookie_quantity;

    line_item cookies[500];
    cookies[1].cookie_flavor = cookie_type;
    cookies[1].number_of_cookies = cookie_quantity;

    orders[order_count].user = "GuestUser";
    orders[order_count].line_item = cookies[1];
    orders[order_count].order_id = rand() % 100000;

    print_cookie_order(orders[order_count], item);

    consume_cookie_inventory(item, cookie_type - 1, cookie_quantity);

    // Reorder Loop
    cout << "Quieres pedir mas galletas? (Y/N)" << endl;
    cin >> reorder_bool;

    if (reorder_bool == "Y")
    {
        cout << "--Siguiente Orden--" << endl;
        order_count = cookie_order_function(item, orders, order_count);
    }
    else
    {
        order_count = order_count + 1;
    }
    return order_count;
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

void main_menu_function(details item[], cookie_order orders[], int order_count)
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
        main_menu_function(item, orders, order_count);
    }
    // crear usuario
    else if (entrada_de_usuario == 1)
    {
        crear_usuario_function();
        main_menu_function(item, orders, order_count);
    }
    // crear nueva orden
    else if (entrada_de_usuario == 2)
    {
        order_count = cookie_order_function(item, orders, order_count);
        main_menu_function(item, orders, order_count);
    }
    // Ver historial
    else if (entrada_de_usuario == 3)
    {
        print_order_history(item, orders, order_count);
        main_menu_function(item, orders, order_count);
    }
    // crear analiticos
    else if (entrada_de_usuario == 4)
    {
        cout << "" << endl;
        main_menu_function(item, orders, order_count);
    }
    // ver inventario de galletas
    else if (entrada_de_usuario == 5)
    {
        print_inventory(item);
        main_menu_function(item, orders, order_count);
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
    cookie_order orders[100];
    int order_count = 0;

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

    main_menu_function(item, orders, order_count);

    return 0;
}
