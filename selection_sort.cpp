#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "Enter Size: ";
    cin >> n;
    int A[n];
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    for(int i = 0; i < (n - 1); i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(A[i] > A[j])
            {
                swap(A[i], A[j]);
            }
        }
    }
    cout << "Sorted array is: ";
    for(int i = 0; i < n; i++)
    {
        cout << A[i] << ' ';
    }
    return 0;
}