#include <bits/stdc++.h>
using namespace std;
void tower(int n, char from, char aux, char to);
int main()
{
    int n;
    cout << "Enter number of disks: ";
    cin >> n;
    tower(n, 'A', 'B', 'C');
    return 0;
}
void tower(int n, char from, char aux, char to)
{
    if(n == 1)
    {
        cout << "Move disk " << n << " from " << from << " to " << to << endl;
        return;
    }
    tower(n - 1, from, to, aux);
    cout << "Move disk " << n << " from " << from << " to " << to << endl;
    tower(n - 1, aux, from, to); 
}