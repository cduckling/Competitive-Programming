#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <numeric>
using namespace std;

#define tc ll t; cin >> t; while (t--) solve();
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pb(i) push_back(i);
#define inf 1e18;

typedef long long ll;
typedef pair<ll, ll> pii;
typedef tuple<ll, ll, ll> tiii;
typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;
typedef vector<pair<ll, ll>> vpii;
typedef vector<tuple<ll, ll, ll>> vtiii;
typedef vector<bool> vb;
typedef multiset<ll> msi;
typedef set<ll> si;
typedef map<ll, ll> mi;
typedef map<ll, vector<ll>> mvi;
typedef map<ll, pair<ll, ll>> mpii;
typedef map<ll, bool> mb;

void solve() {
    ll n, q; cin >> n >> q;

    vpii ops (n + 1); vi c {0}; for (ll i = 1; i <= n; i++) {
        ll b, v; cin >> b >> v;

        ops[i] = {b, v};

        if (c.size() < i) continue;

        ll tot = c[i - 1];

        if (b == 1) {
            if (LLONG_MAX == tot) continue;

            tot++;
        } else {
            if (LLONG_MAX / (v + 1) < tot) continue;

            tot *= v + 1;
        }

        c.pb(tot);
    }

    for (ll i = 0; i < q; i++) {
        ll k; cin >> k;

        ll j = lower_bound(c.begin(), c.end(), k) - c.begin();

        while (ops[j].first == 2) {
            k %= c[j - 1]; if (!k) k += c[j - 1];

            j = lower_bound(c.begin(), c.end(), k) - c.begin();
        }

        cout << ops[j].second << " ";
    }

    cout << "\n";
}

int main() {
    io
    tc

    return 0;
}