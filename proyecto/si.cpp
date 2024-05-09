#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;


struct Jugador {
    int numero;
    string nombre;
    int cartasAmarillas;
    int cartasRojas;
    int porcentajeGol;
    int golesHechos;
    bool aptoParaJugar; 
};

struct Equipo {
    int posicion;
    string nombre;
    int porcentajeExito;
    vector<Jugador> jugadores;
    int puntos;
    int partidosJugados;
    int golesFavor;
    int golesContra;
};
vector<Equipo> cargarEquiposDesdeArchivo(const string& nombreArchivo) {
}

void simularPartido(Equipo& equipoLocal, Equipo& equipoVisitante) {
    equipoLocal.puntos += 3;
    equipoLocal.partidosJugados++;
    equipoLocal.golesFavor += 2;
    equipoLocal.golesContra += 0;

    equipoVisitante.partidosJugados++;
    equipoVisitante.golesFavor += 0;
    equipoVisitante.golesContra += 2;
}

int main() {
    vector<Equipo> equipos = cargarEquiposDesdeArchivo("eqjug.txt");

    if (equipos.size() < 4) {
        cout << "No hay suficientes equipos para formar grupos." << endl;
        return 1;
    }

    vector<vector<Equipo> > grupos;
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
        cout << "Grupo " << i+1 << endl;
        for (size_t j = 0; j < grupos[i].size(); ++j) {
            for (size_t k = j+1; k < grupos[i].size(); ++k) {
                simularPartido(grupos[i][j], grupos[i][k]);
            }
        }
    }

    for (size_t i = 0; i < grupos.size(); ++i) {
        cout << "Ganador del Grupo " << i+1 << ": ";
        Equipo ganador = grupos[i][0];
        for (size_t j = 1; j < grupos[i].size(); ++j) {
            if (grupos[i][j].puntos > ganador.puntos) {
                ganador = grupos[i][j];
            }
        }
        cout << ganador.nombre << " (" << ganador.puntos << " puntos)" << endl;
    }

    return 0;
}


