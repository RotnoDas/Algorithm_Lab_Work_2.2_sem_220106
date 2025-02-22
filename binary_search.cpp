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
    int value;
    cout << "Enter value: ";
    cin >> value;
    sort(arr, arr + size);
    int begin_index = 0, end_index = size - 1, mid_index = (begin_index + end_index) / 2;
    bool flag = true, found = false;
    while(flag)
    {
        if (arr[mid_index] == value)
        {
            found = true;
            break;
        }
        else if (arr[mid_index] > value)
        {
            end_index = mid_index - 1;
            mid_index = (begin_index + end_index) / 2;
        }
        else if (arr[mid_index] < value)
        {
            begin_index = mid_index + 1;
            mid_index = (begin_index + end_index) / 2;
        }
        if (begin_index > end_index)
        {
            flag = false;
        }
    }
    if (found)
    {
        cout << "Found\n";
    }
    else
    {
        cout << "Not found\n";
    }
    return 0;
}