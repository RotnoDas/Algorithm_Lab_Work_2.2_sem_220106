#include <bits/stdc++.h>
using namespace std;
#define MAX 10
int graph[MAX][MAX];
int tsp(int graph[MAX][MAX], int n);
int calculate_cost(int graph[MAX][MAX], int cities[], int n);
int main()
{
    int n;
    cout << "Enter the number of cities: ";
    cin >> n;
    cout << "Enter the cost/adjacency matrix: \n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
        }
    }
    int min_cost = tsp(graph, n);
    cout << "Minimum cost: " << min_cost << '\n';
    return 0;
}
int tsp(int graph[MAX][MAX], int n)
{
    int cities[n];
    for (int i = 0; i < n; i++)
    {
        cities[i] = i;
    }
    int min_cost = INT_MAX;
    int best_path[n];
    do
    {
        int current_cost = calculate_cost(graph, cities, n);
        if (current_cost < min_cost)
        {
            min_cost = current_cost;
            for(int i = 0; i < n; i++)
            {
                best_path[i] = cities[i];
            }
        }
        cout << "Path: ";
        for (int i = 0; i < n; i++)
        {
            cout << cities[i] << " -> ";
        }
        cout << 0 << '\n';
    } while (next_permutation(cities + 1, cities + n));
    cout << "Shortest path: ";
    for (int i = 0; i < n; i++)
    {
        cout << best_path[i] << " -> ";
    }
    cout << 0 << '\n';
    return min_cost;
}
int calculate_cost(int graph[MAX][MAX], int cities[], int n)
{
    int cost = 0;
    for (int i = 0; i < (n - 1); i++)
    {
        cost += graph[cities[i]][cities[i + 1]];
    }
    cost += graph[cities[n - 1]][cities[0]];
    return cost;
}