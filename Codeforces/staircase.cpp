#include <iostream>
#include <vector>
using namespace std;

#define tc ll t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

void solve() {
    ll n {}; cin >> n;

    vector<ll> a (n); for (ll i {0}; i < n; ++i) cin >> a[i];

    vector<vector<ll>> b {}; if (a[0] != 0) {b.emplace_back(); b[b.size() - 1].push_back(a[0]);} for (ll i {1}; i < n; ++i) {
        if (a[i] == 0) continue;

        if (a[i - 1] == 0) b.emplace_back();
        b[b.size() - 1].push_back(a[i]);
    }

    ll c {0};

    for (const auto& b_ : b) {
        ll s {0}, m {0};

        for (int i {0}; i < b_.size(); ++i) {
            s += b_[i];

            if (i % 2 == 0) m = max(m, b_[i]);
        }

        c += 2 * s;

        if (b_.size() % 2 != 0) c -= m;
    }

    cout << c << "\n";
}

int main() {
    io
    tc

    return 0;
}