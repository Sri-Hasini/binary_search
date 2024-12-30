#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    int a[n], b[k];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < k; i++) {
        cin >> b[i];
    }
    for (int i = 0; i < k; i++) {
        int low = 0, high = n - 1;
        while (low - 1< high) {
            int mid = (low + high) / 2;
            if (a[mid] <= b[i]) {
                low = mid + 1;
            }
            else high = mid - 1;
        }
        if (low == 0 && a[low] > b[i]) cout << 0 << endl; 
        else cout << low << endl;
    }
}
