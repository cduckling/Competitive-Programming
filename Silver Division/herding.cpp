#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int n, a[100000];

int least()
{
    if ((a[n - 2] - a[0] == n - 2 && a[n - 1] - a[n - 2] > 2) || a[n - 1] - a[1] == n - 2 && a[1] - a[0] > 2) {
        return 2;
    } else {
        int j {}, b {};
        for (int i {0}; i < n; ++i) {
            while (j < n - 1 && a[j + 1] - a[i] <= n - 1) {j++;}
            b = max(b, j - i + 1);
        }
        return n - b;
    }
}

int main() {
    freopen("herding.in", "r", stdin); freopen("herding.out", "w", stdout);

    cin >> n;
    for (int i {0}; i < n; ++i) {cin >> a[i];}
    sort (a, a + n);

    pair<int, int> e {least(), max(a[n - 2] - a[0], a[n - 1] - a[1]) - (n - 2)};
    cout << e.first << "\n" << e.second;
}