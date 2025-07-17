#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

typedef  long long ll;

ll m = 1e9 + 7;

long long modpow(long long base, long long exp) {
    base %= m;
    long long res = 1;
    while (exp > 0) {
        if (exp % 2 == 1) { res = res * base % m; }
        base = base * base % m;
        exp /= 2;
    }
    return res;
}

int main() {
    freopen("help.in", "r", stdin); freopen("help.out", "w", stdout);

    int n {}; cin >> n;

    vector<int> line (2 * n + 2);

    vector<pair<int, int>> segments (n);
    for (int i {0}; i < n; ++i) {
        cin >> segments[i].first >> segments[i].second;

        ++line[segments[i].first]; --line[segments[i].second + 1];
    }

    for (int i {1}; i <= 2 * n + 1; ++i) {
        line[i] += line[i - 1];
    }

    ll complexity {0};
    for (auto segment : segments) {
        complexity += modpow(2, n - line[segment.first]) % m;
        complexity %= m;
    }

    cout << complexity % m;
}