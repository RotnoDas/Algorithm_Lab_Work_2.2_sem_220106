#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int A[n];
    for (int i = 0 ; i < n ; i++)
    {
        cin >> A[i];
    }
    int max = INT_MIN, min = INT_MAX;
    for (int i = 0 ; i < n ; i++)
    {
        if (A[i] > max)
        {
            max = A[i];
        }
        if (A[i] < min)
        {
            min = A[i];
        }
    }
    cout << "Minimum: " << min << '\n';
    cout << "Maximum: " << max << '\n';
    return 0;
}