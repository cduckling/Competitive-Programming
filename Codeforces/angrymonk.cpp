// Codeforces Round 957 (Div. 3)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define tc ll t {}; cin >> t; while (t--) {solve();}

typedef long long ll;

void solve() {
    ll n {}, k {}; cin >> n >> k;

    ll operations {0};

    vector<ll> a (k); for (ll i {0}; i < k; ++i) {
        cin >> a[i];
    } sort(a.begin(), a.end());

    for (ll i {0}; i < k - 1; ++i) {
        operations += a[i] + a[i] - 1;
    }

    cout << operations << "\n";
}

int main() {
    tc
}