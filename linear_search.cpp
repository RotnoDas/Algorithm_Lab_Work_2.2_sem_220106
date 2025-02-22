#include <bits/stdc++.h>
using namespace std;
int main()
{
    int size;
    cout << "Enter size: ";
    cin >> size;
    int arr[size];
    cout << "Enter element: ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    int value;
    cout << "Enter value: ";
    cin >> value;
    bool flag = false;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == value)
        {
            flag = true;
        }
    }
    if (flag)
    {
        cout << "Found\n";
    }
    else
    {
        cout << "Not found\n";
    }
    return 0;
}