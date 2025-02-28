#include<bits/stdc++.h>
using namespace std;
#define white 1
#define gray 2
#define black 3
int node, edge;
int color[100], parent[100], dis[100], graph[100][100];
void bfs(int starting_node);
int main()
{
    cout << "Enter node and edge: ";
    cin >> node >> edge;
    for(int i = 0; i < node; i++)
    {
        for(int j = 0; j < node; j++)
        {
            graph[i][j] = 0;
        }
    }
    cout << "Enter adjacency matrix: ";
    int u, v;
    for(int i = 0; i < edge; i++)
    {
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }
    int starting_node;
    cout << "Enter starting node: ";
    cin >> starting_node;
    bfs(starting_node);
    return 0;
}
void bfs(int starting_node)
{
    for(int i = 0; i < node; i++)
    {
        color[i] = white;
        dis[i] = INT_MIN;
        parent[i] = -1;
    }
    dis[starting_node] = 0;
    parent[starting_node] = -1;
    queue<int> q;
    q.push(starting_node);
    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        color[x] = gray;
        cout << x << ' ';
        for(int i = 0; i < node; i++)
        {
            if(graph[x][i] == 1)
            {
                if(color[i] == white)
                {
                    q.push(i);
                    parent[i] = x;
                    dis[i] = dis[x] + 1;
                }
            }
        }
        color[x] = black;
    }
}