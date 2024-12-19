#include <bits/stdc++.h>
using namespace std;
// binary search on decimal
// if the question is given like, to find the square root of some given number upto some 6 precisions correct
// then take it as 6 + 1 = 7, because at some time, like we find mid = (low + high)/2
// if low = 1.000001, high = 1.000002 then if we find mid, then it is 1.0000015, which have 7 precisions and hence we wont get accurate results

int main() {
    int n;
    cin >> n;
    double precision = 1e-7;
    double low = 1, high = n;
    double ans = 0;
    while (low <= high) {
        double mid = (low + high) / 2;
        if (mid * mid <= n) {
            ans = max(mid, ans);
            low = mid + precision;
        }
        else {
            high = mid - precision;
        }
    }
    cout << setprecision(6) << fixed << ans;
}
