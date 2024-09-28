#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

#define tc ll t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;
typedef pair<ll, ll> pll;

void solve() {
    ll n {}; cin >> n;

    vector<ll> a (n); for (ll i {0}; i < n; ++i) cin >> a[i];

    for (ll i {0}; i < n - 1; ++i) {
        if (a[i] != 1 && a[i + 1] == 1) {
            cout << - 1 << "\n"; return;
        }
    }

    ll o {0}, p {0};

    pll m {};

    for (ll i {1}; i < n; ++i) {
        m = {a[i], 0};

        while (a[i] < a[i - 1]) {a[i] = a[i] * a[i]; ++m.second; }

        o += m.second; p = i;

        if (a[i] > static_cast<ll>(1e6)) break;
    }

    for (ll i {p + 1}; i < n; ++i) {
        if (m.first > a[i]) {
            m = {a[i], m.second + ceil(log2(log(m.first) / log(a[i])))};
            o += m.second;
        } else if (m.first == a[i]) {
            m = {a[i], m.second};
            o += m.second;
        } else {
            m = {a[i], m.second - floor(log2(log(a[i]) / log(m.first)))};
            o += m.second;
        }
    }

    cout << o << "\n";
}

int main() {
    io
    tc

    return 0;
}