#include <iostream>
#include <climits>
using namespace std;
#define MAX_NODES 1000
int graph[MAX_NODES][MAX_NODES];
int dist[MAX_NODES];
bool visited[MAX_NODES];
int parent[MAX_NODES];
void dijkstra_bruteforce(int source, int n)
{
    for (int i = 0; i < n; i++)
    {
        dist[i] = INT_MAX;
        visited[i] = false;
        parent[i] = -1;
    }
    dist[source] = 0;
    for (int count = 0; count < n - 1; count++)
    {
        int u = -1;
        int minDist = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && dist[i] < minDist)
            {
                minDist = dist[i];
                u = i;
            }
        }
        if (u == -1)
        {
            break;
        }
        visited[u] = true;
        for (int v = 0; v < n; v++)
        {
            if (graph[u][v] != 0 && !visited[v] && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }
    cout << "Vertex\t Distance from Source " << source << "\tPath\n";
    for (int i = 0; i < n; i++)
    {
        cout << i << "\t";
        if (dist[i] == INT_MAX)
        {
            cout << "-1\t No path";
        }
        else
        {
            cout << dist[i] << "\t";
            int path[MAX_NODES];
            int path_length = 0;
            int temp = i;
            while (temp != -1)
            {
                path[path_length++] = temp;
                temp = parent[temp];
            }
            for (int j = path_length - 1; j >= 0; j--)
            {
                cout << path[j];
                if (j > 0)
                {
                    cout << " -> ";
                }
            }
        }
        cout << "\n";
    }
}
int main()
{
    int n, m;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            graph[i][j] = 0;
        }
    }
    cout << "Enter edges :\n";
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
        graph[v][u] = w;
    }
    int source;
    cout << "Enter source vertex: ";
    cin >> source;
    dijkstra_bruteforce(source, n);
    return 0;
}
