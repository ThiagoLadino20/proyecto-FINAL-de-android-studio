#include <iostream>
#include <vector>
#include <string>
#include "tu_archivo_de_funciones.h"

using namespace std;

int main() {
    vector<Equipo> equipos = cargarEquiposDesdeArchivo("eqjug.txt");

    if (equipos.size() < 4) {
        cout << "No hay suficientes equipos para formar grupos." << endl;
        return 1;
    }

    vector<vector<Equipo>> grupos;
    vector<Equipo> grupoActual;

    for (size_t i = 0; i < equipos.size(); ++i) {
        grupoActual.push_back(equipos[i]);

        if (grupoActual.size() == 4) {
            grupos.push_back(grupoActual);
            grupoActual.clear();
        }
    }

    if (!grupoActual.empty()) {
        cout << "Hay equipos adicionales que no se asignaron a un grupo completo." << endl;
    }

    return 0;
}

