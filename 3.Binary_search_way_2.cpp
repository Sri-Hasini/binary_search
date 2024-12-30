// Binary search in another approach, by performing k number of operations 
#include <bits/stdc++.h>
using namespace std;
int main() {
    int query;
    cin >> query;
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int k = 0;
    for (int b = n / 2; b >= 1; b /= 2) {
        while (k + b < n && a[k + b] <= query) k += b;
    }
    if (a[k] == query) cout << k << endl;
    else cout << -1 << endl;
}
