#include<iostream>
#include<vector>
#include<queue>
#include<climits>

using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;

public:
    Graph(int V);
    void addEdge(int u, int v);
    void printGraph();
    void printAdjMatrix();
    void shortestPath(int src, int dest);
};

Graph::Graph(int V) {
    this->V = V;
    adj.resize(V, vector<int>(V, 0));
}

void Graph::addEdge(int u, int v) {
    adj[u][v] = 1;
    adj[v][u] = 1;
}

void Graph::printGraph() {
    for(int i=0; i<V; i++) {
        cout << "Nodo " << i << ": ";
        for(int j=0; j<V; j++) {
            if(adj[i][j] == 1)
                cout << j << " ";
        }
        cout << endl;
    }
}

void Graph::printAdjMatrix() {
    for(int i=0; i<V; i++) {
        for(int j=0; j<V; j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
}

void Graph::shortestPath(int src, int dest) {
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, src));
    while(!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        for(int v=0; v<V; v++) {
            if(adj[u][v] && dist[u] + adj[u][v] < dist[v]) {
                dist[v] = dist[u] + adj[u][v];
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    if(dist[dest] != INT_MAX) {
        cout << "El camino más corto desde " << src << " hasta " << dest << " es de una distancia de " << dist[dest] << endl;
    } else {
        cout << "No hay un camino alcanzable desde " << src << " hasta " << dest << endl;
    }
}

int main() {
    int V;
    cout << "Ingrese el número de nodos: ";
    cin >> V;
    Graph g(V);
    int option;
    do {
        cout << "1. Agregar nodo\n2. Ver grafo\n3. Ver matriz de adyacencia\n4. Ver camino más corto\n5. Salir\n";
        cin >> option;
        switch(option) {
            case 1: {
                int u, v;
                cout << "Ingrese los nodos a conectar: ";
                cin >> u >> v;
                if(u >= V || v >= V) {
                    cout << "Nodo inválido. Los nodos deben estar en el rango de 0 a " << V-1 << ".\n";
                } else {
                    g.addEdge(u, v);
                }
                break;
            }
            case 2:
                g.printGraph();
                break;
            case 3:
                g.printAdjMatrix();
                break;
            case 4: {
                int src, dest;
                cout << "Ingrese el nodo de origen: ";
                cin >> src;
                cout << "Ingrese el nodo de destino: ";
                cin >> dest;
                if(src >= V || dest >= V) {
                    cout << "Nodo inválido. Los nodos deben estar en el rango de 0 a " << V-1 << ".\n";
                } else {
                    g.shortestPath(src, dest);
                }
                break;
            }
            case 5:
                cout << "Saliendo del programa.\n";
                break;
            default:
                cout << "Opción inválida.\n";
        }
    } while(option != 5);
    return 0;
}
