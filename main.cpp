#include <iostream>
#include <cstdio>

using namespace std;

const int MAX_PRODUCTOS = 100;
const float IVA = 0.21f;

struct Producto {
    int codigo;
    float precio;
    int cantidad;
};

int main() {
    Producto productos[MAX_PRODUCTOS];
    int cantidadProductos = 0;

    cout << "=== Punto de Venta (POS) ===" << endl;

    // Ingreso de productos
    while (cantidadProductos < MAX_PRODUCTOS) {
        int codigo;
        float precio;
        int cantidad;

        cout << "\nIngrese el código del producto (0 para finalizar): ";
        cin >> codigo;
        if (codigo == 0) break;

        cout << "Ingrese el precio del producto: ";
        cin >> precio;

        cout << "Ingrese la cantidad: ";
        cin >> cantidad;

        productos[cantidadProductos] = {codigo, precio, cantidad};
        cantidadProductos++;
    }

    // Impresión de ticket
    cout << "\n=== TICKET DE COMPRA ===\n";
    printf("Codigo\tPrecio\tCantidad\tSubtotal\n");

    float total = 0;
    for (int i = 0; i < cantidadProductos; ++i) {
        float subtotal = productos[i].precio * productos[i].cantidad;
        total += subtotal;

        printf("%d\t%.2f\t%d\t\t%.2f\n", 
               productos[i].codigo, 
               productos[i].precio, 
               productos[i].cantidad, 
               subtotal);
    }

    float iva = total * IVA;
    float totalConIva = total + iva;

    printf("\nSubtotal: %.2f\n", total);
    printf("IVA 21%% : %.2f\n", iva);
    printf("TOTAL   : %.2f\n", totalConIva);

    return 0;
}
