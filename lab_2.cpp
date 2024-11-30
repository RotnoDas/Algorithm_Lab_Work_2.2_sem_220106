#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n; int arr[n];
    for (int i = 0 ; i < n ; i++) {
        cin >> arr[i];
    }
    int num; cin >> num;
    sort(arr, arr + n);
    int begin_index = 0, end_index = n - 1, mid_index = (begin_index + end_index) / 2;
    bool flag = true;
    while(flag) {
        if (arr[mid_index] == num) {
            cout << "Found" << '\n';
            break;
        }
        else if (arr[mid_index] > num) {
            end_index = mid_index - 1;
            mid_index = (begin_index + end_index) / 2;
        }
        else if (arr[mid_index] < num) {
            begin_index = mid_index + 1;
            mid_index = (begin_index + end_index) / 2;
        }
        if (begin_index > end_index) {
            flag = false;
        }
    }
    if (!flag) {
        cout << "Not found" << '\n';
    }
    return 0;
}