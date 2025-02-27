#include<bits/stdc++.h>
using namespace std;
#define white 1
#define gray 2
#define black 3
void dfs();
void dfsVisit(int x);
int node, edge;
int graph[100][100];
int color[100];
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
    dfs();
}
void dfs()
{
    for(int i = 0; i < node; i++)
    {
        color[i] = white;
    }
    int n;
    cout << "Enter starting node: ";
    cin >> n;
    dfsVisit(n);
    /*for(int i = 0; i < node; i++)
    {
        if(color[i] == white)
        {
            dfsVisit(i);
        }
    }*/
}
void dfsVisit(int x)
{
    color[x] = gray;
    cout << x << ' ';
    for(int i = 0; i < node; i++)
    {
        if(graph[x][i] == 1)
        {
            if(color[i] == white)
            {
                dfsVisit(i);
            }
        }
    }
    color[x] = black;
}