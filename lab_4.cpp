#include <bits/stdc++.h>
using namespace std;
int b_s(int A[], int low, int high, int num)
{
    if (low > high)
    {
        return -1;
    }
    int mid = low + (high - low) / 2;
    if (A[mid] == num)
    {
        return mid;
    }
    else if (A[mid] > num)
    {
        return b_s(A, low, mid - 1, num);
    }
    else if (A[mid] < num)
    {
        return b_s(A, mid + 1, high, num);
    }
}
int main()
{
    int n;
    cin >> n;
    int A[n];
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    sort(A, A + n);
    int num;
    cin >> num;
    int binary_search = b_s(A, 0, n - 1, num);
    if (binary_search == -1)
    {
        cout << "Not found" << '\n';
    }
    else
    {
        cout << "Found" << '\n';
    }
    return 0;
}