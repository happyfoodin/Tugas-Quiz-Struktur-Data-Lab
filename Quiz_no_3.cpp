#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
 
class Graph {
    private:
        int numberVertex;
        vector<vector<int>> adjMatrix;
 
        // Mencetak rute dari source sampai vertex v (A -> C -> B)
        void cetakRute(vector<int>& parent, int v) {
            if (parent[v] != -1) {
                cetakRute(parent, parent[v]);
                cout << " -> ";
            }
            cout << char('A' + v);
        }
 
        void dfsUntil(int currentVertex, vector<bool>& visited) {
            visited[currentVertex] = true;
            cout << char('A' + currentVertex) << " ";
 
            for (int i = 0; i < numberVertex; i++) {
                if (adjMatrix[currentVertex][i] != 0 && !visited[i]) {
                    dfsUntil(i, visited);
                }
            }
        }
 
    public:
        Graph (int banyakTitik) {
            numberVertex = banyakTitik;
            adjMatrix.resize(numberVertex, vector<int>(numberVertex, 0));
        }
 
        void addEdge(int i, int j, int weight) {
            if (i >= 0 && i < numberVertex && j >= 0 && j < numberVertex) {
                adjMatrix[i][j] = weight;
                adjMatrix[j][i] = weight;
            } else {
                cout << "Index nonvalid" << endl;
            }
        }
 
        void printAdjMatrix() {
            cout << "  ";
            for (int i = 0; i < numberVertex; i++) {
                cout << char('A' + i) << " ";
            }
            cout << endl;
            for (int i = 0; i < numberVertex; i++) {
                cout << char('A' + i) << " ";
                for (int j = 0; j < numberVertex; j++) {
                    cout << adjMatrix[i][j] << " ";
                }
                cout << endl;
            }
        }
 
        void bfs (int startVertex) {
            vector<bool> visited(numberVertex, false);
            queue<int> titikVisit;
 
            visited[startVertex] = true;
            titikVisit.push(startVertex);
 
            while (!titikVisit.empty()) {
                int currentVertex = titikVisit.front();
                titikVisit.pop();
                cout << char('A' + currentVertex) << " ";
 
                for (int i = 0; i < numberVertex; i++) {
                    if (adjMatrix[currentVertex][i] != 0 && !visited[i]) {
                        visited[i] = true;
                        titikVisit.push(i);
                    }
                }
            }
            cout << endl;
        }
 
        void dfs (int startVertex) {
            vector<bool> visited(numberVertex, false);
            dfsUntil(startVertex, visited);
            cout << endl;
        }
 
        void dijkstra(int source, int tujuan) {
            vector<int> distance(numberVertex, INT_MAX);
            vector<int> parent(numberVertex, -1);
            vector<bool> visited(numberVertex, false);
            distance[source] = 0;
 
            for (int i = 0; i < numberVertex; i++) {
                int u = -1;
 
                for (int j = 0; j < numberVertex; j++) {
                    if (!visited[j] &&
                        (u == -1 || distance[j] < distance[u])) {
                        u = j;
                    }
                }
 
                if (u == -1 || distance[u] == INT_MAX)
                    break;
 
                visited[u] = true;
 
                for (int v = 0; v < numberVertex; v++) {
                    if (adjMatrix[u][v] != 0 && !visited[v]) {
                        int newDistance = distance[u] + adjMatrix[u][v];
 
                        if (newDistance < distance[v]) {
                            distance[v] = newDistance;
                            parent[v] = u; // simpan asal rute
                        }
                    }
                }
            }
 
            cout << "Rute terpendek dari " << char('A' + source) << " ke " << char('A' + tujuan) << " : ";
            if (distance[tujuan] == INT_MAX) {
                cout << "Tidak terjangkau" << endl;
            } else {
                cetakRute(parent, tujuan);
                cout << endl;
                cout << "Total jarak : " << distance[tujuan] << endl;
            }
        }
};
 
int main() {
    system("cls");
    Graph graph(6);
 
    // A=0, B=1, C=2, D=3, E=4, F=5
    graph.addEdge(0, 1, 4); // A-B
    graph.addEdge(0, 2, 2); // A-C
    graph.addEdge(1, 2, 1); // B-C
    graph.addEdge(1, 3, 5); // B-D
    graph.addEdge(1, 4, 3); // B-E
    graph.addEdge(2, 3, 8); // C-D
    graph.addEdge(2, 4, 6); // C-E
    graph.addEdge(3, 4, 2); // D-E
    graph.addEdge(3, 5, 4); // D-F
    graph.addEdge(4, 5, 3); // E-F
 
    cout << "Adjacency Matrix : " << endl;
    graph.printAdjMatrix();
 
    char asal, tujuan;
    cout << "\nMasukkan vertex awal (A-F)   : ";
    cin >> asal;
    cout << "Masukkan vertex tujuan (A-F) : ";
    cin >> tujuan;
 
    int s = toupper(asal) - 'A';
    int t = toupper(tujuan) - 'A';
 
    if (s < 0 || s > 5 || t < 0 || t > 5) {
        cout << "Input tidak valid!" << endl;
        return 0;
    }
 
    cout << "\nUrutan BFS : ";
    graph.bfs(s);
 
    cout << "Urutan DFS : ";
    graph.dfs(s);
 
    cout << endl;
    graph.dijkstra(s, t);
 
    return 0;
}