 #include <iostream>
#include <vector>
#include <string>
#include "tu_archivo_de_funciones.h"

using namespace std;

void simularPartido(Equipo& equipoLocal, Equipo& equipoVisitante) {

    int resultado = rand() % 3;

    switch (resultado) {
        case 0:
            equipoLocal.puntos += 1;
            equipoVisitante.puntos += 1;
            break;
        case 1:
            equipoLocal.puntos += 3;
            break;
        case 2:
            equipoVisitante.puntos += 3;
            break;
    }
}

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

    for (size_t i = 0; i < grupos.size(); ++i) {
        cout << "Grupo " << (i + 1) << ":" << endl;
        vector<Equipo>& grupo = grupos[i];

        for (size_t j = 0; j < grupo.size(); ++j) {
            for (size_t k = j + 1; k < grupo.size(); ++k) {
                simularPartido(grupo[j], grupo[k]);
            }
        }

        sort(grupo.begin(), grupo.end(), [](const Equipo& a, const Equipo& b) {
            return a.puntos > b.puntos;
        });

        for (size_t j = 0; j < grupo.size(); ++j) {
            cout << "Equipo " << (j + 1) << ": " << grupo[j].nombre << " - Puntos: " << grupo[j].puntos << endl;
        }

        cout << endl;
    }

    return 0;
}

