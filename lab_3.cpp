#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int number, choice;
    cin >> number;
    while (true)
    {
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            bool flag = true;
            for (int i = 0; i < n; i++)
            {
                if (a[i] == number)
                {
                    cout << "Found" << '\n';
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                cout << "Not found" << '\n';
            }
            break;
        }
        case 2:
        {
            sort(a, a + n);
            int begin_index = 0, end_index = n - 1, mid_index = (begin_index + end_index) / 2;
            bool flag = true;
            while (flag)
            {
                if (a[mid_index] == number)
                {
                    cout << "Found" << '\n';
                    break;
                }
                else if (a[mid_index] > number)
                {
                    end_index = mid_index - 1;
                    mid_index = (begin_index + end_index) / 2;
                }
                else if (a[mid_index] < number)
                {
                    begin_index = mid_index + 1;
                    mid_index = (begin_index + end_index) / 2;
                }
                if (begin_index > end_index)
                {
                    flag = false;
                }
            }
            if (!flag)
            {
                cout << "Not found" << '\n';
            }
            break;
        }
        default:
        {
            return 0;
        }
        }
    }
    return 0;
}