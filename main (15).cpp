
#include <iostream>
#include <vector>
using namespace std;

// Estructura del producto
struct Producto {
    string codigo;
    string nombre;
    int cantidad;
};

// ---------------- FUNCIONES DE AYUDA ----------------

// Buscar producto por código
int buscarProducto(const vector<Producto>& inventario, string codigo) {
    for (int i = 0; i < inventario.size(); i++) {
        if (inventario[i].codigo == codigo) {
            return i;
        }
    }
    return -1;
}

// ---------------- FUNCIONES PRINCIPALES ----------------

// Mostrar menú
void mostrarMenu() {
    cout << "\n===== SISTEMA DE INVENTARIO =====\n";
    cout << "1. Agregar producto\n";
    cout << "2. Listar productos\n";
    cout << "3. Actualizar cantidad\n";
    cout << "4. Reporte de bajo inventario\n";
    cout << "5. Salir\n";
    cout << "Seleccione una opcion: ";
}

// Agregar producto
void agregarProducto(vector<Producto>& inventario) {
    Producto nuevo;

    cout << "Ingrese codigo del producto: ";
    cin >> nuevo.codigo;

    // Verificar si ya existe
    if (buscarProducto(inventario, nuevo.codigo) != -1) {
        cout << "Error: el producto ya existe.\n";
        return;
    }

    cout << "Ingrese nombre del producto: ";
    cin >> nuevo.nombre;

    cout << "Ingrese cantidad: ";
    cin >> nuevo.cantidad;

    inventario.push_back(nuevo);

    cout << "Producto agregado correctamente.\n";
}

// Listar productos
void listarProductos(const vector<Producto>& inventario) {
    if (inventario.empty()) {
        cout << "No hay productos en el inventario.\n";
        return;
    }

    cout << "\n===== INVENTARIO =====\n";

    for (const auto& producto : inventario) {
        cout << "Codigo: " << producto.codigo << endl;
        cout << "Nombre: " << producto.nombre << endl;
        cout << "Cantidad: " << producto.cantidad << endl;
        cout << "----------------------\n";
    }
}

// Actualizar cantidad
void actualizarCantidad(vector<Producto>& inventario) {
    string codigo;
    int nuevaCantidad;

    cout << "Ingrese codigo del producto: ";
    cin >> codigo;

    int posicion = buscarProducto(inventario, codigo);

    if (posicion == -1) {
        cout << "Producto no encontrado.\n";
        return;
    }

    cout << "Ingrese nueva cantidad: ";
    cin >> nuevaCantidad;

    inventario[posicion].cantidad = nuevaCantidad;

    cout << "Cantidad actualizada correctamente.\n";
}

// Reporte de bajo inventario
void reporteBajoInventario(const vector<Producto>& inventario) {
    int limite;

    cout << "Ingrese limite minimo: ";
    cin >> limite;

    cout << "\n===== PRODUCTOS CON BAJO INVENTARIO =====\n";

    bool encontrado = false;

    for (const auto& producto : inventario) {
        if (producto.cantidad < limite) {
            cout << producto.nombre
                 << " - Cantidad: "
                 << producto.cantidad << endl;

            encontrado = true;
        }
    }

    if (!encontrado) {
        cout << "No hay productos con bajo inventario.\n";
    }
}

// ---------------- MAIN ----------------

int main() {
    vector<Producto> inventario;
    int opcion;

    do {
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
            case 1:
                agregarProducto(inventario);
                break;

            case 2:
                listarProductos(inventario);
                break;

            case 3:
                actualizarCantidad(inventario);
                break;

            case 4:
                reporteBajoInventario(inventario);
                break;

            case 5:
                cout << "Saliendo del programa...\n";
                break;

            default:
                cout << "Opcion invalida.\n";
        }

    } while (opcion != 5);

    return 0;
}