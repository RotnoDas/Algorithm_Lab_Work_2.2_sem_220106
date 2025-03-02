#include<bits/stdc++.h>
using namespace std;
int main()
{
    string x, y;
    cout << "Enter the first string: ";
    cin >> x;
    cout << "Enter the second string: ";
    cin >> y;
    int len1 = x.length();
    int len2 = y.length();
    int dp[len1+1][len2+1];
    for(int i = 0; i <= len1; i++)
    {
        for(int j = 0; j <= len2; j++)
        {
            if(i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if(x[i-1] == y[j-1])
            {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    cout << "Length of LCS: " << dp[len1][len2] << '\n';
    return 0;
}