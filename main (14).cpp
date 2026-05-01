#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Equipo {
    string nombre;
    int partidosJugados;
    int partidosGanados;
    int partidosEmpatados;
    int partidosPerdidos;
    int puntos;
};

const int MAX_EQUIPOS = 20;
int totalEquipos = 16;

// ---------- FUNCIONES ----------

// Reconstruir empates y perdidos
void reconstruirDatos(Equipo equipos[]) {
    for (int i = 0; i < totalEquipos; i++) {
        equipos[i].partidosEmpatados = equipos[i].puntos - (3 * equipos[i].partidosGanados);
        equipos[i].partidosPerdidos = equipos[i].partidosJugados 
                                    - equipos[i].partidosGanados 
                                    - equipos[i].partidosEmpatados;
    }
}

// Mostrar tabla
void mostrarTabla(Equipo equipos[]) {
    cout << "\nNombre\t\tPJ\tPG\tPE\tPP\tPts\n";
    for (int i = 0; i < totalEquipos; i++) {
        cout << equipos[i].nombre << "\t"
             << equipos[i].partidosJugados << "\t"
             << equipos[i].partidosGanados << "\t"
             << equipos[i].partidosEmpatados << "\t"
             << equipos[i].partidosPerdidos << "\t"
             << equipos[i].puntos << endl;
    }
}

// Ordenar mayor a menor
void ordenarMayor(Equipo equipos[]) {
    sort(equipos, equipos + totalEquipos, [](Equipo a, Equipo b) {
        return a.puntos > b.puntos;
    });
}

// Ordenar menor a mayor
void ordenarMenor(Equipo equipos[]) {
    sort(equipos, equipos + totalEquipos, [](Equipo a, Equipo b) {
        return a.puntos < b.puntos;
    });
}

// Equipo con más empates
void masEmpates(Equipo equipos[]) {
    int maxEmpates = -1;
    string nombre;

    for (int i = 0; i < totalEquipos; i++) {
        if (equipos[i].partidosEmpatados > maxEmpates) {
            maxEmpates = equipos[i].partidosEmpatados;
            nombre = equipos[i].nombre;
        }
    }

    cout << "\nEquipo con más empates: " << nombre 
         << " (" << maxEmpates << " empates)\n";
}

// Buscar equipo
void buscarEquipo(Equipo equipos[]) {
    string nombre;
    cout << "\nIngrese nombre del equipo: ";
    cin.ignore();
    getline(cin, nombre);

    for (int i = 0; i < totalEquipos; i++) {
        if (equipos[i].nombre == nombre) {
            cout << "\nEncontrado:\n";
            cout << "PJ: " << equipos[i].partidosJugados << endl;
            cout << "PG: " << equipos[i].partidosGanados << endl;
            cout << "PE: " << equipos[i].partidosEmpatados << endl;
            cout << "PP: " << equipos[i].partidosPerdidos << endl;
            cout << "Puntos: " << equipos[i].puntos << endl;
            return;
        }
    }

    cout << "Equipo no encontrado\n";
}

// Validar datos
bool validarDatos(Equipo e) {
    if (e.puntos != (3 * e.partidosGanados + e.partidosEmpatados))
        return false;

    if (e.partidosJugados != (e.partidosGanados + e.partidosEmpatados + e.partidosPerdidos))
        return false;

    return true;
}

// Agregar equipo
void agregarEquipo(Equipo equipos[]) {
    if (totalEquipos >= MAX_EQUIPOS) {
        cout << "\nNo se pueden agregar más equipos\n";
        return;
    }

    Equipo nuevo;

    cout << "\nNombre: ";
    cin.ignore();
    getline(cin, nuevo.nombre);

    cout << "Partidos jugados: ";
    cin >> nuevo.partidosJugados;

    cout << "Ganados: ";
    cin >> nuevo.partidosGanados;

    cout << "Empatados: ";
    cin >> nuevo.partidosEmpatados;

    cout << "Perdidos: ";
    cin >> nuevo.partidosPerdidos;

    cout << "Puntos: ";
    cin >> nuevo.puntos;

    if (validarDatos(nuevo)) {
        equipos[totalEquipos++] = nuevo;
        cout << "Equipo agregado correctamente\n";
    } else {
        cout << "Error: datos inconsistentes\n";
    }
}

// ---------- MAIN ----------
int main() {

    Equipo equipos[MAX_EQUIPOS] = {
        {"Andrómeda FC",12,4,0,0,13},
        {"Vulcano Academia",11,2,0,0,10},
        {"Orión Confederación",11,4,0,0,14},
        {"Sirio Estrellas",10,6,0,0,20},
        {"Caronte Titanes",11,1,0,0,6},
        {"Quíron Cometas",10,5,0,0,17},
        {"Pegaso Púlsares",11,7,0,0,24},
        {"Osos Cósmicos",11,5,0,0,18},
        {"Vía Láctea Nómadas",11,6,0,0,20},
        {"Leónidas FC",11,5,0,0,16},
        {"Cangrejo Fortaleza",11,4,0,0,16},
        {"Cefeo Cúmulo",11,3,0,0,14},
        {"Atlético Interestelar",11,4,0,0,16},
        {"Deportivo Galáctico",11,2,0,0,8},
        {"Estrella Estelar",11,5,0,0,17},
        {"Inter Galaxia",10,2,0,0,10}
    };

    reconstruirDatos(equipos);

    int opcion;

    do {
        cout << "\nMENU\n";
        cout << "1. Tabla mayor a menor\n";
        cout << "2. Tabla menor a mayor\n";
        cout << "3. Equipo con más empates\n";
        cout << "4. Buscar equipo\n";
        cout << "5. Agregar equipo\n";
        cout << "0. Salir\n";
        cin >> opcion;

        switch (opcion) {
            case 1:
                ordenarMayor(equipos);
                mostrarTabla(equipos);
                break;
            case 2:
                ordenarMenor(equipos);
                mostrarTabla(equipos);
                break;
            case 3:
                masEmpates(equipos);
                break;
            case 4:
                buscarEquipo(equipos);
                break;
            case 5:
                agregarEquipo(equipos);
                break;
        }

    } while (opcion != 0);

    return 0;
}