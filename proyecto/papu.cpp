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
};

Match simulateMatch(const string& team1, const string& team2) {
    Match match;
    match.team1 = team1;
    match.team2 = team2;
    match.score1 = rand() % 5;
    match.score2 = rand() % 5;
    return match;
}

bool compareMatches(const Match& a, const Match& b) {
    return (a.score1 + a.score2) > (b.score1 + b.score2);
}

int main() {
    srand(time(0));

    vector<string> equipos;
    equipos.push_back("Equipo A1");
    equipos.push_back("Equipo A2");
    equipos.push_back("Equipo A3");
    equipos.push_back("Equipo A4");
    equipos.push_back("Equipo B1");
    equipos.push_back("Equipo B2");
    equipos.push_back("Equipo B3");
    equipos.push_back("Equipo B4");
    equipos.push_back("Equipo C1");
    equipos.push_back("Equipo C2");
    equipos.push_back("Equipo C3");
    equipos.push_back("Equipo C4");
    equipos.push_back("Equipo D1");
    equipos.push_back("Equipo D2");
    equipos.push_back("Equipo D3");
    equipos.push_back("Equipo D4");

    vector<Match> partidosGrupoA;
    vector<Match> partidosGrupoB;
    vector<Match> partidosGrupoC;
    vector<Match> partidosGrupoD;

    for (size_t i = 0; i < 3; ++i) {
        partidosGrupoA.push_back(simulateMatch(equipos[i], equipos[i + 1]));
    }

    for (size_t i = 0; i < 3; ++i) {
        partidosGrupoB.push_back(simulateMatch(equipos[i + 4], equipos[i + 5]));
    }

    for (size_t i = 0; i < 3; ++i) {
        partidosGrupoC.push_back(simulateMatch(equipos[i + 8], equipos[i + 9]));
    }

    for (size_t i = 0; i < 3; ++i) {
        partidosGrupoD.push_back(simulateMatch(equipos[i + 12], equipos[i + 13]));
    }
    cout << "\nCopa America 2024" << endl;
    cout << "\nResultados de la fase de grupos (Grupo A):" << endl;
    for (vector<Match>::const_iterator it = partidosGrupoA.begin(); it != partidosGrupoA.end(); ++it) {
        const Match& partido = *it;
        cout << partido.team1 << " " << partido.score1 << " - " << partido.score2 << " " << partido.team2 << endl;
    }

    cout << "Resultados de la fase de grupos (Grupo B):" << endl;
    for (vector<Match>::const_iterator it = partidosGrupoB.begin(); it != partidosGrupoB.end(); ++it) {
        const Match& partido = *it;
        cout << partido.team1 << " " << partido.score1 << " - " << partido.score2 << " " << partido.team2 << endl;
    }

    cout << "Resultados de la fase de grupos (Grupo C):" << endl;
    for (vector<Match>::const_iterator it = partidosGrupoC.begin(); it != partidosGrupoC.end(); ++it) {
        const Match& partido = *it;
        cout << partido.team1 << " " << partido.score1 << " - " << partido.score2 << " " << partido.team2 << endl;
    }

    cout << "Resultados de la fase de grupos (Grupo D):" << endl;
    for (vector<Match>::const_iterator it = partidosGrupoD.begin(); it != partidosGrupoD.end(); ++it) {
        const Match& partido = *it;
        cout << partido.team1 << " " << partido.score1 << " - " << partido.score2 << " " << partido.team2 << endl;
    }
    
    cout << "\nTabla de posiciones:" << endl;
    cout << "Equipo\t\tPuntos" << endl;
    for (vector<string>::const_iterator it = equipos.begin(); it != equipos.end(); ++it) {
        const string& equipo = *it;
        int puntos = 0;
        for (vector<Match>::const_iterator it = partidosGrupoA.begin(); it != partidosGrupoA.end(); ++it) {
            const Match& partido = *it;
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
    for (vector<string>::const_iterator it = equipos.begin() + 4; it != equipos.begin() + 8; ++it) {
        const string& equipo = *it;
        int puntos = 0;
        for (vector<Match>::const_iterator it = partidosGrupoB.begin(); it != partidosGrupoB.end(); ++it) {
            const Match& partido = *it;
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
    for (vector<string>::const_iterator it = equipos.begin() + 8; it != equipos.begin() + 12; ++it) {
        const string& equipo = *it;
        int puntos = 0;
        for (vector<Match>::const_iterator it = partidosGrupoC.begin(); it != partidosGrupoC.end(); ++it) {
            const Match& partido = *it;
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
    for (vector<string>::const_iterator it = equipos.begin() + 12; it != equipos.end(); ++it) {
        const string& equipo = *it;
        int puntos = 0;
        for (vector<Match>::const_iterator it = partidosGrupoD.begin(); it != partidosGrupoD.end(); ++it) {
            const Match& partido = *it;
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
    for (vector<string>::const_iterator it = equipos.begin(); it != equipos.end(); ++it) {
        const string& equipo = *it;
        int puntos = 0;
        for (vector<Match>::const_iterator it = partidosGrupoA.begin(); it != partidosGrupoA.end(); ++it) {
            const Match& partido = *it;
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

    for (vector<string>::const_iterator it = equipos.begin() + 4; it != equipos.begin() + 8; ++it) {
        const string& equipo = *it;
        int puntos = 0;
        for (vector<Match>::const_iterator it = partidosGrupoB.begin(); it != partidosGrupoB.end(); ++it) {
            const Match& partido = *it;
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
    
    for (vector<string>::const_iterator it = equipos.begin() + 8; it != equipos.begin() + 12; ++it) {
        const string& equipo = *it;
        int puntos = 0;
        for (vector<Match>::const_iterator it = partidosGrupoC.begin(); it != partidosGrupoC.end(); ++it) {
            const Match& partido = *it;
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
    
    for (vector<string>::const_iterator it = equipos.begin() + 12; it != equipos.end(); ++it) {
        const string& equipo = *it;
        int puntos = 0;
        for (vector<Match>::const_iterator it = partidosGrupoD.begin(); it != partidosGrupoD.end(); ++it) {
            const Match& partido = *it;
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
    for (vector<string>::const_iterator it = equiposClasificados.begin(); it != equiposClasificados.end(); ++it) {
        const string& equipo = *it;
        cout << equipo << endl;
    }

    vector<Match> cuartosDeFinal;

    for (size_t i = 0; i < equiposClasificados.size(); i += 2) {
        Match partido;
        partido.team1 = equiposClasificados[i];
        partido.team2 = equiposClasificados[i + 1];
        cuartosDeFinal.push_back(partido);
    }

    for (vector<Match>::iterator it = cuartosDeFinal.begin(); it != cuartosDeFinal.end(); ++it) {
        Match& partido = *it;
        partido.score1 = rand() % 5;
        partido.score2 = rand() % 5;
    }

    cout << "\nResultados de cuartos de final:" << endl;
    for (vector<Match>::const_iterator it = cuartosDeFinal.begin(); it != cuartosDeFinal.end(); ++it) {
        const Match& partido = *it;
        cout << partido.team1 << " " << partido.score1 << " - " << partido.score2 << " " << partido.team2 << endl;
    }

    vector<string> equiposSemifinales;

    for (vector<Match>::const_iterator it = cuartosDeFinal.begin(); it != cuartosDeFinal.end(); ++it) {
        const Match& partido = *it;
        int puntos = 0;
        for (vector<Match>::const_iterator it_inner = cuartosDeFinal.begin(); it_inner != cuartosDeFinal.end(); ++it_inner) {
            const Match& partido_inner = *it_inner;
            if (partido.team1 == partido_inner.team1 || partido.team1 == partido_inner.team2) {
                puntos += (partido.score1 > partido.score2) ? 1 : 0;
            }
            if (partido.team2 == partido_inner.team1 || partido.team2 == partido_inner.team2) {
                puntos += (partido.score2 > partido.score1) ? 1 : 0;
            }
        }
        if (puntos >= 2) {
            equiposSemifinales.push_back(partido.team1);
        } else {
            equiposSemifinales.push_back(partido.team2);
        }
    }

    vector<Match> semifinales;

    for (size_t i = 0; i < equiposSemifinales.size(); i += 2) {
        Match partido;
        partido.team1 = equiposSemifinales[i];
        partido.team2 = equiposSemifinales[i + 1];
        semifinales.push_back(partido);
    }

    for (vector<Match>::iterator it = semifinales.begin(); it != semifinales.end(); ++it) {
        Match& partido = *it;
        partido.score1 = rand() % 5;
        partido.score2 = rand() % 5;
    }

    cout << "\nResultados de semifinales:" << endl;
    for (vector<Match>::const_iterator it = semifinales.begin(); it != semifinales.end(); ++it) {
        const Match& partido = *it;
        cout << partido.team1 << " " << partido.score1 << " - " << partido.score2 << " " << partido.team2 << endl;
    }

    vector<string> equiposFinalistas;

    for (vector<Match>::const_iterator it = semifinales.begin(); it != semifinales.end(); ++it) {
        const Match& partido = *it;
        int puntos = 0;
        for (vector<Match>::const_iterator it_inner = semifinales.begin(); it_inner != semifinales.end(); ++it_inner) {
            const Match& partido_inner = *it_inner;
            if (partido.team1 == partido_inner.team1 || partido.team1 == partido_inner.team2) {
                puntos += (partido.score1 > partido.score2) ? 1 : 0;
            }
            if (partido.team2 == partido_inner.team1 || partido.team2 == partido_inner.team2) {
                puntos += (partido.score2 > partido.score1) ? 1 : 0;
            }
        }
        if (puntos >= 2) {
            equiposFinalistas.push_back(partido.team1);
        } else {
            equiposFinalistas.push_back(partido.team2);
        }
    }

    Match final;
    final.team1 = equiposFinalistas[0];
    final.team2 = equiposFinalistas[1];
    final.score1 = rand() % 5;
    final.score2 = rand() % 5;

    cout << "\nResultados de la final:" << endl;
    cout << final.team1 << " " << final.score1 << " - " << final.score2 << " " << final.team2 << endl;

    cout << "\n¡El equipo ganador de la Copa America 2024 es: " << ((final.score1 > final.score2) ? final.team1 : final.team2) << "!" << endl;

    return 0;
}

