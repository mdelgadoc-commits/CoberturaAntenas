#include <iostream>

using namespace std;

// Función para ordenar el arreglo de menor a mayor (Ordenamiento Burbuja)
void ordenarCasas(int casas[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (casas[j] > casas[j + 1]) {
                int aux = casas[j];
                casas[j] = casas[j + 1];
                casas[j + 1] = aux;
            }
        }
    }
}

// Algoritmo Voraz (Version Greedy) para ubicar las antenas
void resolverCobertura(int casas[], int n, int R) {
    ordenarCasas(casas, n);

    int antenas[100]; // Arreglo para guardar las posiciones de las antenas
    int cantidadAntenas = 0;
    int i = 0;

    while (i < n) {
        int casaSinCubrir = casas[i];
        
        // Colocar la antena lo más a la derecha posible respetando el rango R 
        int posicionAntena = casaSinCubrir + R;
        antenas[cantidadAntenas] = posicionAntena;
        cantidadAntenas++;

        int limiteDerecho = posicionAntena + R;

        // Saltar todas las casas cubiertas por esta antena
        while (i < n && casas[i] <= limiteDerecho) {
            i++;
        }
    }

    // Mostrar los resultados exactos pedidos
    cout << "Antenas colocadas aproximadamente en:" << endl;
    for (int k = 0; k < cantidadAntenas; k++) {
        cout << antenas[k] << endl;
    }
    cout << "Cantidad total: " << cantidadAntenas << endl;
}

int main() {
    int cantidadCasas, R;

    cout << "COBERTURA DE ANTENAS (VERSION GREEDY) " << endl;
    cout << "Ingrese la cantidad de casas: ";
    cin >> cantidadCasas;

    int casas[100];
    for (int i = 0; i < cantidadCasas; i++) {
        cout << "Posicion de la casa " << (i + 1) << ": ";
        cin >> casas[i];
    }

    cout << "Ingrese el rango de cobertura (R): ";
    cin >> R;

    cout << endl;
    resolverCobertura(casas, cantidadCasas, R);

    return 0;
}
