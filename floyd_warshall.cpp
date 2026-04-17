#include <iostream>
#include <climits>
using namespace std;

#define INF 99999

int main() {
    int V;
    cout << "Enter number of vertices: ";
    cin >> V;
    int dist[V][V];
    cout << "Enter adjacency matrix (use 99999 for INF):\n";
    for(int i = 0; i < V; i++)
        for(int j = 0; j < V; j++)
            cin >> dist[i][j];
    for(int k = 0; k < V; k++)
        for(int i = 0; i < V; i++)
            for(int j = 0; j < V; j++)
                if(dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
    cout << "Shortest distance matrix:\n";
    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            if(dist[i][j] == INF)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

