#include <bits/stdc++.h>
using namespace std;
void divideConquer(int arr[], int low, int high, int *maximum, int *minimum)
{
    int leftMin, leftMax, rightMin, rightMax;
    if (low == high)
    {
        *minimum = arr[low];
        *maximum = arr[high];
        return;
    }
    else if (low + 1 == high)
    {
        if (arr[low] < arr[high])
        {
            *minimum = arr[low];
            *maximum = arr[high];
        }
        else
        {
            *minimum = arr[high];
            *maximum = arr[low];
        }
        return;
    }
    int mid = (low + high) / 2;
    divideConquer(arr, low, mid, maximum, minimum);
    leftMin = *minimum;
    leftMax = *maximum;
    divideConquer(arr, mid + 1, high, maximum, minimum);
    rightMin = *minimum;
    rightMax = *maximum;
    *minimum = min(leftMin, rightMin);
    *maximum = max(leftMax, rightMax);
}
int main()
{
    int size;
    cout << "Enter Size: ";
    cin >> size;
    int arr[size];
    cout << "Enter elements: ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    int maximum = INT_MIN, minimum = INT_MAX;
    divideConquer(arr, 0, size - 1, &maximum, &minimum);
    cout << "Minimum: " << minimum << '\n';
    cout << "Maximum: " << maximum << '\n';
    return 0;
}