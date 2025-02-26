#include <bits/stdc++.h>
using namespace std;
void quick_sort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
int main()
{
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int low = 0, high = n - 1;
    quick_sort(arr, low, high);
    cout << "Sorted Array: ";
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << ' ';
    }
    return 0;
}
void quick_sort(int arr[], int low, int high)
{
    if (low >= high)
    {
        return;
    }
    int pI = partition(arr, low, high);
    quick_sort(arr, low, pI - 1);
    quick_sort(arr, pI + 1, high);
}
int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low, j = high;
    while(i < j)
    {
        while(arr[i] <= pivot && i <= (high - 1))
        {
            i++;
        }
        while(arr[j] > pivot && j >= (low - 1))
        {
            j--;
        }
        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low], arr[j]);
    return j;
}