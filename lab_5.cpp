#include <bits/stdc++.h>
using namespace std;
void iterative(int A[], int n)
{
    int max = INT_MIN, min = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (A[i] > max)
        {
            max = A[i];
        }
        if (A[i] < min)
        {
            min = A[i];
        }
    }
    cout << "Minimum: " << min << '\n';
    cout << "Maximum: " << max << '\n';
}
void d_c(int A[], int l, int h, int &minimum, int &maximum)
{
    int leftmin, rightmin, leftmax, rightmax;
    if (l == h)
    {
        minimum = A[l];
        maximum = A[h];
        return;
    }
    else if (l + 1 == h)
    {
        if (A[l] > A[h])
        {
            maximum = A[l];
            minimum = A[h];
        }
        else
        {
            minimum = A[l];
            maximum = A[h];
        }
        return;
    }
    int mid = (l + h) / 2;
    d_c(A, l, mid, minimum, maximum);
    leftmin = minimum;
    leftmax = maximum;
    d_c(A, mid+1, h, minimum, maximum);
    rightmin = minimum;
    rightmax = maximum;
    minimum = min(leftmin, rightmin);
    maximum = max(leftmax, rightmax);
}
int main()
{
    int n, l, h, minimum = INT_MAX, maximum = INT_MIN;
    cin >> n;
    int A[n];
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    int choice;
    cin >> choice;
    if (choice == 1)
    {
        iterative(A, n);
    }
    else if(choice == 2)
    {
        d_c(A, 0, n-1, minimum, maximum);
    }
    cout << "Minimum: " << minimum << '\n';
    cout << "Maximum: " << maximum << '\n';
    return 0;
}