#include<bits/stdc++.h>
using namespace std;
void printHeap(int heap[], int n);
void heapsort(int heap[], int n);
void heapify(int heap[], int n);
int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int heap[n];
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++)
    {
        cin >> heap[i];
    }
    cout << "Original: ";
    printHeap(heap, n);
    heapsort(heap, n);
    cout << "Sorted: ";
    printHeap(heap, n);
    return 0;
}
void heapify(int heap[], int n, int i)
{
    int largest_index = i;
    int left_index = 2*i + 1;
    int right_index = 2*i + 2;
    if(left_index < n && heap[left_index] > heap[largest_index])
    {
        largest_index = left_index;
    }
    if(right_index < n && heap[right_index] > heap[largest_index])
    {
        largest_index = right_index;
    }
    if(largest_index != i)
    {
        swap(heap[i], heap[largest_index]);
        heapify(heap, n, largest_index);
    }
}
void heapsort(int heap[], int n)
{
    for(int i = n/2 - 1; i >= 0; i--)
    {
        heapify(heap, n, i);
    }
    for(int i = n - 1; i > 0; i--)
    {
        swap(heap[0], heap[i]);
        heapify(heap, i, 0);
    }
}
void printHeap(int heap[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << heap[i] << ' ';
    }
    cout << '\n';
}