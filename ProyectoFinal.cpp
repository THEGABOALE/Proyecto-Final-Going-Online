#include <iostream>
#include <vector>
using namespace std;

struct Producto 
{
    int id;
    string nombre;
    float precio;
};

vector<Producto> inventario;

void agregarProducto() 
{
    Producto nuevoProducto;
    cout << "Ingrese ID del producto: ";
    cin >> nuevoProducto.id;
    cout << "Ingrese nombre del producto: ";
    cin >> nuevoProducto.nombre;
    cout << "Ingrese precio del producto: ";
    cin >> nuevoProducto.precio;
    inventario.push_back(nuevoProducto);
    cout << "Producto agregado.\n";
}

void eliminarProducto() {
    int id;
    cout << "Ingrese ID del producto a eliminar: ";
    cin >> id;
    for (auto it = inventario.begin(); it != inventario.end(); ++it) {
        if (it->id == id) 
        {
            inventario.erase(it);
            cout << "Producto eliminado.\n";
            return;
        }
    }
    cout << "Producto no encontrado.\n";
}

void verProductos() {
    cout << "Lista de productos:\n";
    for (const auto& producto : inventario) {
        cout << "ID: " << producto.id << ", Nombre: " << producto.nombre << ", Precio: " << producto.precio << "\n";
    }
}

void modificarProducto() {
    int id;
    cout << "Ingrese ID del producto a modificar: ";
    cin >> id;
    for (auto& producto : inventario) {
        if (producto.id == id) {
            cout << "Ingrese nuevo nombre del producto: ";
            cin >> producto.nombre;
            cout << "Ingrese nuevo precio del producto: ";
            cin >> producto.precio;
            cout << "Producto modificado.\n";
            return;
        }
    }
    cout << "Producto no encontrado.\n";
}

int main() {
    int opcion;
    do {
        cout << "1- Agregar producto\n";
        cout << "2- Eliminar producto\n";
        cout << "3- Ver productos\n";
        cout << "4- Modificar producto\n";
        cout << "5- Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;
        switch (opcion) {
            case 1: agregarProducto(); break;
            case 2: eliminarProducto(); break;
            case 3: verProductos(); break;
            case 4: modificarProducto(); break;
            case 5: break;
            default: cout << "Opción no válida.\n";
        }
    } while (opcion != 5);
    return 0;
}
