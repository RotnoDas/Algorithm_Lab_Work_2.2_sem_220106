#include <bits/stdc++.h>
using namespace std;
void merge_sort(int arr[], int low, int high);
void merge(int arr[], int low, int mid, int high);
int main()
{
    int n;
    cout << "Enter Size: ";
    cin >> n;
    int arr[n];
    cout << "Enter Elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int low = 0, high = n - 1;
    merge_sort(arr, low, high);
    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ' ';
    }
    return 0;
}
void merge_sort(int arr[], int low, int high)
{
    if (low >= high)
    {
        return;
    }
    int mid = (low + high) / 2;
    merge_sort(arr, low, mid);
    merge_sort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}
void merge(int arr[], int low, int mid, int high)
{
    int size1 = mid - low + 1;
    int size2 = high - mid;
    int leftArr[size1], rightArr[size2];
    for (int i = 0; i < size1; i++)
    {
        leftArr[i] = arr[low + i]; 
    }
    for (int i = 0; i < size2; i++)
    {
        rightArr[i] = arr[mid + 1 + i];
    }
    int i = 0, j = 0;
    while(i < size1 && j < size2)
    {
        if (leftArr[i] < rightArr[j])
        {
            arr[low] = leftArr[i];
            i++;
        }
        else
        {
            arr[low] = rightArr[j];
            j++;
        }
        low++;
    }
    while(i < size1)
    {
        arr[low] = leftArr[i];
        i++;
        low++;
    }
    while(j < size2)
    {
        arr[low] = rightArr[j];
        j++;
        low++;
    }
}