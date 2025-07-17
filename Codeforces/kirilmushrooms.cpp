#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

#define tc ll t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;
typedef pair<ll, ll> pii;

void solve() {
    ll n {}; cin >> n;

    vector<pii> v (n + 1); for (ll i {1}; i <= n; i++) { cin >> v[i].first; v[i].second = i; } sort(v.begin(), v.end());
    vector<ll> p (n + 1); for (ll i {1}; i <= n; i++) cin >> p[i];

    ll c {v[n].first}, m {1}, r {n}; set<ll> e {}, u {}; u.insert(v[n].second);

    for (ll i {2}; i <= n; i++) {
        e.insert(p[i - 1]); ll a {1}; if (u.count(p[i - 1])) { u.erase(p[i - 1]); ++a; }

        while (a > 0 && r > 0) {
            --r;

            if (!e.count(v[r].second)) {
                --a; u.insert(v[r].second);
            }
        }

        if (!r) break;

        if (i * v[r].first > c) {
            c = i * v[r].first; m = i;
        }
    }

    cout << c << " " << m << "\n";
}

int main() {
    io
    tc

    return 0;
}