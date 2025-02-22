#include <bits/stdc++.h>
using namespace std;
int main()
{
    int size;
    cout << "Enter size: ";
    cin >> size;
    int arr[size];
    cout << "Enter elements: ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    int max = INT_MIN, min = INT_MAX;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    cout << "Minimum: " << min << '\n';
    cout << "Maximum: " << max << '\n';
    return 0;
}