#include <iostream>
#include <climits>
using namespace std;

struct Edge {
    int src, dest, weight;
};

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;
    Edge edges[E];
    for(int i = 0; i < E; i++) {
        cout << "Enter source, destination and weight: ";
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
    }
    int src;
    cout << "Enter source vertex: ";
    cin >> src;
    int dist[V];
    for(int i = 0; i < V; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;

    // Relax edges V-1 times
    for(int i = 1; i <= V - 1; i++) {
        for(int j = 0; j < E; j++) {
            int u = edges[j].src;
            int v = edges[j].dest;
            int w = edges[j].weight;

            if(dist[u] != INT_MAX && dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
        }
    }

    // Check for negative weight cycle
    for(int j = 0; j < E; j++) {
        if(dist[edges[j].src] != INT_MAX &&
           dist[edges[j].src] + edges[j].weight < dist[edges[j].dest]) {
            cout << "Graph contains negative weight cycle";
            return 0;
        }
    }

    cout << "Vertex Distance from Source\n";
    for(int i = 0; i < V; i++)
        cout << i << "\t\t" << dist[i] << endl;
    return 0;
}

