#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Match {
    string team1;
    string team2;
    int score1;
    int score2;
    string date;
};

struct Stadium {
    string name;
    vector<Match> matches;
};

Match simulateMatch(const string& team1, const string& team2) {
    Match match;
    match.team1 = team1;
    match.team2 = team2;
    match.score1 = rand() % 5;
    match.score2 = rand() % 5;
    return match;
}

void simulateMatches() {
    srand(time(0));

    vector<string> equipos = {"Argentina", "Mexico", "Estados Unidos", "Brasil",
                              "Uruguay", "Colombia", "Ecuador", "Perú",
                              "Chile", "Panamá", "Venezuela", "Paraguay",
                              "Canadá", "Costa Rica", "Jamaica", "Bolivia"};

    vector<string> grupoA(equipos.begin(), equipos.begin() + 4);
    vector<string> grupoB(equipos.begin() + 4, equipos.begin() + 8);
    vector<string> grupoC(equipos.begin() + 8, equipos.begin() + 12);
    vector<string> grupoD(equipos.begin() + 12, equipos.end());

    vector<Match> partidosGrupoA;
    vector<Match> partidosGrupoB;
    vector<Match> partidosGrupoC;
    vector<Match> partidosGrupoD;

    for (size_t i = 0; i < 3; ++i) {
        partidosGrupoA.push_back(simulateMatch(grupoA[i], grupoA[i + 1]));
    }

    for (size_t i = 0; i < 3; ++i) {
        partidosGrupoB.push_back(simulateMatch(grupoB[i], grupoB[i + 1]));
    }

    for (size_t i = 0; i < 3; ++i) {
        partidosGrupoC.push_back(simulateMatch(grupoC[i], grupoC[i + 1]));
    }

    for (size_t i = 0; i < 3; ++i) {
        partidosGrupoD.push_back(simulateMatch(grupoD[i], grupoD[i + 1]));
    }
    cout << "\nCopa América" << endl;
    cout << "\nResultados de la fase de grupos (Grupo A):" << endl;
    for (const Match& partido : partidosGrupoA) {
        cout << partido.team1 << " " << partido.score1 << " - " << partido.score2 << " " << partido.team2 << endl;
    }

    cout << "Resultados de la fase de grupos (Grupo B):" << endl;
    for (const Match& partido : partidosGrupoB) {
        cout << partido.team1 << " " << partido.score1 << " - " << partido.score2 << " " << partido.team2 << endl;
    }

    cout << "Resultados de la fase de grupos (Grupo C):" << endl;
    for (const Match& partido : partidosGrupoC) {
        cout << partido.team1 << " " << partido.score1 << " - " << partido.score2 << " " << partido.team2 << endl;
    }

    cout << "Resultados de la fase de grupos (Grupo D):" << endl;
    for (const Match& partido : partidosGrupoD) {
        cout << partido.team1 << " " << partido.score1 << " - " << partido.score2 << " " << partido.team2 << endl;
    }
    
    cout << "\nTabla de posiciones:" << endl;
    cout << "Equipo\t\tPuntos" << endl;
    for (const string& equipo : grupoA) {
        int puntos = 0;
        for (const Match& partido : partidosGrupoA) {
            if (partido.team1 == equipo) {
                if (partido.score1 > partido.score2) puntos += 3;
                else if (partido.score1 == partido.score2) puntos += 1;
            }
            else if (partido.team2 == equipo) {
                if (partido.score2 > partido.score1) puntos += 3;
                else if (partido.score2 == partido.score1) puntos += 1;
            }
        }
        cout << equipo << "\t\t" << puntos << endl;
    }
    
    cout << "\nTabla de posiciones (Grupo B):" << endl;
    cout << "Equipo\t\tPuntos" << endl;
    for (const string& equipo : grupoB) {
        int puntos = 0;
        for (const Match& partido : partidosGrupoB) {
            if (partido.team1 == equipo) {
                if (partido.score1 > partido.score2) puntos += 3;
                else if (partido.score1 == partido.score2) puntos += 1;
            }
            else if (partido.team2 == equipo) {
                if (partido.score2 > partido.score1) puntos += 3;
                else if (partido.score2 == partido.score1) puntos += 1;
            }
        }
        cout << equipo << "\t\t" << puntos << endl;
    }

    cout << "\nTabla de posiciones (Grupo C):" << endl;
    cout << "Equipo\t\tPuntos" << endl;
    for (const string& equipo : grupoC) {
        int puntos = 0;
        for (const Match& partido : partidosGrupoC) {
            if (partido.team1 == equipo) {
                if (partido.score1 > partido.score2) puntos += 3;
                else if (partido.score1 == partido.score2) puntos += 1;
            }
            else if (partido.team2 == equipo) {
                if (partido.score2 > partido.score1) puntos += 3;
                else if (partido.score2 == partido.score1) puntos += 1;
            }
        }
        cout << equipo << "\t\t" << puntos << endl;
    }

    cout << "\nTabla de posiciones (Grupo D):" << endl;
    cout << "Equipo\t\tPuntos" << endl;
    for (const string& equipo : grupoD) {
        int puntos = 0;
        for (const Match& partido : partidosGrupoD) {
            if (partido.team1 == equipo) {
                if (partido.score1 > partido.score2) puntos += 3;
                else if (partido.score1 == partido.score2) puntos += 1;
            }
            else if (partido.team2 == equipo) {
                if (partido.score2 > partido.score1) puntos += 3;
                else if (partido.score2 == partido.score1) puntos += 1;
            }
        }
        cout << equipo << "\t\t" << puntos << endl;
    }
    
    vector<string> equiposClasificados;
    for (const string& equipo : grupoA) {
    int puntos = 0;
        for (const Match& partido : partidosGrupoA) {
            if (partido.team1 == equipo) {
                if (partido.score1 > partido.score2) puntos += 3;
                else if (partido.score1 == partido.score2) puntos += 1;
            }
            else if (partido.team2 == equipo) {
                if (partido.score2 > partido.score1) puntos += 3;
                else if (partido.score2 == partido.score1) puntos += 1;
            }
        }
    if (puntos > 0) {
        equiposClasificados.push_back(equipo);
    }
    }

    for (const string& equipo : grupoB) {
        int puntos = 0;
        for (const Match& partido : partidosGrupoB) {
            if (partido.team1 == equipo) {
                if (partido.score1 > partido.score2) puntos += 3;
                else if (partido.score1 == partido.score2) puntos += 1;
            }
            else if (partido.team2 == equipo) {
                if (partido.score2 > partido.score1) puntos += 3;
                else if (partido.score2 == partido.score1) puntos += 1;
            }
        }
        if (puntos > 0) {
            equiposClasificados.push_back(equipo);
        }
    }
    
    for (const string& equipo : grupoC) {
        int puntos = 0;
        for (const Match& partido : partidosGrupoC) {
            if (partido.team1 == equipo) {
                if (partido.score1 > partido.score2) puntos += 3;
                else if (partido.score1 == partido.score2) puntos += 1;
            }
            else if (partido.team2 == equipo) {
                if (partido.score2 > partido.score1) puntos += 3;
                else if (partido.score2 == partido.score1) puntos += 1;
            }
        }
        if (puntos > 0) {
            equiposClasificados.push_back(equipo);
        }
    }
    
    for (const string& equipo : grupoD) {
        int puntos = 0;
        for (const Match& partido : partidosGrupoD) {
            if (partido.team1 == equipo) {
                if (partido.score1 > partido.score2) puntos += 3;
                else if (partido.score1 == partido.score2) puntos += 1;
            }
            else if (partido.team2 == equipo) {
                if (partido.score2 > partido.score1) puntos += 3;
                else if (partido.score2 == partido.score1) puntos += 1;
            }
        }
        if (puntos > 0) {
            equiposClasificados.push_back(equipo);
        }
    }

    cout << "\nEquipos clasificados para la siguiente ronda:" << endl;
    for (const string& equipo : equiposClasificados) {
        cout << equipo << endl;
    }

    vector<Match> cuartosDeFinal;

    for (size_t i = 0; i < equiposClasificados.size(); i += 2) {
        Match partido;
        partido.team1 = equiposClasificados[i];
        partido.team2 = equiposClasificados[i + 1];
        cuartosDeFinal.push_back(partido);
    }

    for (Match& partido : cuartosDeFinal) {
        partido.score1 = rand() % 5;
        partido.score2 = rand() % 5;
    }

    cout << "\nResultados de cuartos de final:" << endl;
    for (const Match& partido : cuartosDeFinal) {
        cout << partido.team1 << " " << partido.score1 << " - " << partido.score2 << " " << partido.team2 << endl;
    }

    vector<string> equiposSemifinales;

    for (const string& equipo : equiposSemifinales) {
        int puntos = 0;
        for (const Match& partido : cuartosDeFinal) {
            if (partido.team1 == equipo) {
                if (partido.score1 > partido.score2) puntos += 3;
                else if (partido.score1 == partido.score2) puntos += 1;
            }
            else if (partido.team2 == equipo) {
                if (partido.score2 > partido.score1) puntos += 3;
                else if (partido.score2 == partido.score1) puntos += 1;
            }
        }
        cout << equipo << "\t\t" << puntos << endl;
    }

    sort(cuartosDeFinal.begin(), cuartosDeFinal.end(), [](const Match& a, const Match& b) {
        return (a.score1 + a.score2) > (b.score1 + b.score2);
    });

    equiposSemifinales.push_back(cuartosDeFinal[0].team1);
    equiposSemifinales.push_back(cuartosDeFinal[0].team2);
    equiposSemifinales.push_back(cuartosDeFinal[1].team1);
    equiposSemifinales.push_back(cuartosDeFinal[1].team2);

    cout << "\nEquipos clasificados para semifinales:" << endl;
    for (const string& equipo : equiposSemifinales) {
        cout << equipo << endl;
    }

    cout << "\nResultados de semifinales:" << endl;
    Match semifinal1 = simulateMatch(equiposSemifinales[0], equiposSemifinales[1]);
    Match semifinal2 = simulateMatch(equiposSemifinales[2], equiposSemifinales[3]);

    cout << equiposSemifinales[0] << " " << semifinal1.score1 << " - " << semifinal1.score2 << " " << equiposSemifinales[1] << endl;
    cout << equiposSemifinales[2] << " " << semifinal2.score1 << " - " << semifinal2.score2 << " " << equiposSemifinales[3] << endl;

    string equipoFinal1 = (semifinal1.score1 + semifinal1.score2) > (semifinal2.score1 + semifinal2.score2) ? equiposSemifinales[0] : equiposSemifinales[1];
    string equipoFinal2 = (semifinal1.score1 + semifinal1.score2) > (semifinal2.score1 + semifinal2.score2) ? equiposSemifinales[2] : equiposSemifinales[3];

    cout << "\nEquipos clasificados para la final:" << endl;
    cout << equipoFinal1 << " vs. " << equipoFinal2 << endl;

    cout << "\nResultado de la final:" << endl;
    Match final = simulateMatch(equipoFinal1, equipoFinal2);
    cout << equipoFinal1 << " " << final.score1 << " - " << final.score2 << " " << equipoFinal2 << endl;

    string ganador;
    if (final.score1 > final.score2) {
        ganador = equipoFinal1;
    } else if (final.score1 < final.score2) {
        ganador = equipoFinal2;
    } else {
        int penalesEquipo1 = rand() % 6;
        int penalesEquipo2 = rand() % 6;

        cout << "\nTanda de penales:" << endl;
        cout << equipoFinal1 << " " << penalesEquipo1 << " - " << penalesEquipo2 << " " << equipoFinal2 << endl;

        if (penalesEquipo1 > penalesEquipo2) {
            ganador = equipoFinal1;
        } else if (penalesEquipo1 < penalesEquipo2) {
            ganador = equipoFinal2;
        } else {
            while (penalesEquipo1 == penalesEquipo2) {
                penalesEquipo1 = rand() % 6;
                penalesEquipo2 = rand() % 6;
            }
            ganador = (penalesEquipo1 > penalesEquipo2) ? equipoFinal1 : equipoFinal2;
        }
    }

    cout << "\n¡El ganador de la Copa América es: " << ganador << "!" << endl;
}

void cargarEstadios() {
    vector<Stadium> stadiums = {
        {"Mercedes", {{"Argentina", "Uruguay", 0, 0, "2024-05-01"}, {"Bolivia", "Venezuela", 0, 0, "2024-05-02"}, {"Perú", "Jamaica", 0, 0, "2024-05-03"}}},
        {"Levi", {{"Estados Unidos", "Panamá", 0, 0, "2024-05-04"}, {"Colombia", "Brasil", 0, 0, "2024-05-05"}, {"Chile", "Paraguay", 0, 0, "2024-05-06"}}},
        {"SoFi", {{"Mexico", "Costa Rica", 0, 0, "2024-05-07"}, {"Ecuador", "Canadá", 0, 0, "2024-05-08"}}},
        
    };

    cout << "Lista de estadios y partidos:" << endl;
    for (const Stadium& stadium : stadiums) {
        cout << stadium.name << ":" << endl;
        for (const Match& match : stadium.matches) {
            cout << "  " << match.date << ": " << match.team1 << " vs. " << match.team2 << endl;
        }
    }
}

int main() {
    int opcion;
    cout << "Bienvenido a la Copa América" << endl;
    cout << "Seleccione una opción:" << endl;
    cout << "1. Simular partidos" << endl;
    cout << "2. Cargar lista de estadios" << endl;
    cout << "Opción: ";
    cin >> opcion;

    switch (opcion) {
        case 1:
            simulateMatches();
            break;
        case 2:
            cargarEstadios();
            break;
        default:
            cout << "Opción no válida. Saliendo del programa." << endl;
    }

    return 0;
}
