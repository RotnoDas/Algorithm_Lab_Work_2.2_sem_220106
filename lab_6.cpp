#include <bits/stdc++.h>
using namespace std;
void merge(int A[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int leftArray[n1], rightArray[n2];
    for (int i = 0; i < n1; i++)
    {
        leftArray[i] = A[left + i];
    }
    for (int j = 0; j < n2; j++)
    {
        rightArray[j] = A[mid + 1 + j];
    }
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (leftArray[i] <= rightArray[j])
        {
            A[k] = leftArray[i];
            i++;
        }
        else
        {
            A[k] = rightArray[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        A[k] = leftArray[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        A[k] = rightArray[j];
        j++;
        k++;
    }
}
void mergeSort(int A[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(A, left, mid);
        mergeSort(A, mid + 1, right);
        merge(A, left, mid, right);
    }
}
void printArray(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << ' ';
    }
    cout << '\n';
}
int main()
{
    int n;
    cin >> n;
    int A[n];
    for (int i = 0 ; i < n ; i++)
    {
        cin >> A[i];
    }
    cout << "Original array: ";
    printArray(A, n);
    mergeSort(A, 0, n - 1);
    cout << "Sorted array: ";
    printArray(A, n);
    return 0;
}