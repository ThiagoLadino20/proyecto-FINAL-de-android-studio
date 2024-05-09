#include <iostream>
#include <fstream>
#include <string>
#include <vector>
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
};

struct Equipo {
    int posicion;
    string nombre;
    int porcentajeExito;
    vector<Jugador> jugadores; 
};

vector<Equipo> cargarEquiposDesdeArchivo(const char* nombreArchivo) {
    vector<Equipo> equipos;
    ifstream archivo(nombreArchivo);

    if (archivo.is_open()) {
        Equipo equipo;
        Jugador jugador;
        string linea;

        while (getline(archivo, linea)) {
            if (linea.empty()) { 
                continue;
            }

            if (linea == "--------------") { 
                equipos.push_back(equipo);
                equipo.jugadores.clear(); 
            } else {
                if (linea.find("//") == string::npos) { 
                    equipo.posicion = atoi(linea.c_str());
                    getline(archivo, equipo.nombre);
                    archivo >> equipo.porcentajeExito;
                    getline(archivo, linea);
                } else { 
                    jugador.numero = atoi(linea.c_str());
                    getline(archivo, jugador.nombre);
                    archivo >> jugador.cartasAmarillas;
                    archivo >> jugador.cartasRojas;
                    archivo >> jugador.porcentajeGol;
                    archivo >> jugador.golesHechos;
                    equipo.jugadores.push_back(jugador); 
                }
            }
        }

        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo " << nombreArchivo << endl;
    }

    return equipos;
}

void simularPartido(const Equipo& equipoLocal, const Equipo& equipoVisitante) {
    int golesEquipoLocal = equipoLocal.porcentajeExito;
    int golesEquipoVisitante = equipoVisitante.porcentajeExito;

    cout << equipoLocal.nombre << " " << golesEquipoLocal << " - " << golesEquipoVisitante << " " << equipoVisitante.nombre << endl;

    for (int i = 0; i < golesEquipoLocal; ++i) {
        int indiceJugador = rand() % equipoLocal.jugadores.size();
        cout << "  " << equipoLocal.jugadores[indiceJugador].nombre << " " << (i + 1) * 10 << endl;
    }

    for (int i = 0; i < golesEquipoVisitante; ++i) {
        int indiceJugador = rand() % equipoVisitante.jugadores.size();
        cout << "  " << equipoVisitante.jugadores[indiceJugador].nombre << " " << (i + 1) * 10 << endl;
    }
}

int main() {
    srand(time(NULL)); 

    vector<Equipo> equipos = cargarEquiposDesdeArchivo("C:\\Users\\salas\\Desktop\\proyecto\\eqjug.txt");


    if (equipos.size() < 2) {
        cout << "Se necesitan al menos dos equipos para simular un partido." << endl;
        return 1;
    }

    int indiceEquipoLocal = rand() % equipos.size();
    int indiceEquipoVisitante = rand() % equipos.size();

    while (indiceEquipoLocal == indiceEquipoVisitante) {
        indiceEquipoVisitante = rand() % equipos.size();
    }

    Equipo equipoLocal = equipos[indiceEquipoLocal];
    Equipo equipoVisitante = equipos[indiceEquipoVisitante];

    cout << "Partido: ";
    simularPartido(equipoLocal, equipoVisitante);

    return 0;
}



