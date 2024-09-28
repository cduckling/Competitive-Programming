#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

#define tc int t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

int mod = 1e9 + 7;

int fast_pow(int a, int p) {
    int res = 1;
    while (p) {
        if (p % 2 == 0) {
            a = a * 1ll * a % mod;
            p /= 2;
        } else {
            res = res * 1ll * a % mod;
            p--;
        }
    }
    return res;
}

int fact(int n) {
    int res = 1;
    for (int i = 1; i <= n; i++) {
        res = res * 1ll * i % mod;
    }
    return res;
}

int C(int n, int k) {
    return fact(n) * 1ll * fast_pow(fact(k), mod - 2) % mod * 1ll * fast_pow(fact(n - k), mod - 2) % mod;
}


void solve() {
    ll n {}, k {}; cin >> n >> k;

    vector<int> a (n); for (int i {0}; i < n; ++i) {
        int j {}; cin >> j; ++a[j - 1];
    }

    ll c {1};

    for (ll i {n - 1}; i >= 0; --i) {
        if (k == 0) {
            break;
        } else if (k - a[i] >= 0) {
            k -= a[i];
        } else {
            c = C(a[i], k); break;
        }
    }

    cout << c << "\n";
}

int main() {
    io
    tc

    return 0;
}