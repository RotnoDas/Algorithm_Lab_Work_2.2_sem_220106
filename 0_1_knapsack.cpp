#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "Enter the numbers of items: ";
    cin >> n;
    int weights[n], values[n];
    cout << "Enter the weights of items: ";
    for(int i = 0; i < n; i++)
    {
        cin >> weights[i];
    }
    cout << "Enter the values of items: ";
    for(int i = 0; i < n; i++)
    {
        cin >> values[i];
    }
    int capacity;
    cout << "Enter capacity: ";
    cin >> capacity;
    int dp[n+1][capacity+1];
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= capacity; j++)
        {
            if(i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if(weights[i-1] <= j)
            {
                dp[i][j] = max(dp[i-1][j], values[i-1] + dp[i-1][j-weights[i-1]]);
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout << "Maximum value: " << dp[n][capacity] << '\n';
    return 0;
}