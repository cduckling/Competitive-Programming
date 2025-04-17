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

#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef set<ll> si;
typedef map<ll, ll> mii;
typedef map<ll, vector<ll>> miv;

class dsu {
private:
    vector<ll> pars;
    vector<ll> sizes;

public:
    dsu(ll size) : pars(size), sizes(size, 1) {
        for (ll i {0}; i < size; i++) pars[i] = i;
    }

    ll find(ll x) {
        return pars[x] == x ? x : (pars[x] = find(pars[x]));
    }

    bool unite(ll a, ll b) {
        ll A = find(a), B = find(b); if (A == B) return false;

        if (sizes[A] < sizes[B]) swap(A, B);

        sizes[A] += sizes[B]; pars[B] = A;

        return true;
    }

    bool connected(ll x, ll y) {
        return find(x) == find(y);
    }
};

void solve() {
    ll n {}, q {}; cin >> n >> q;

    vector<ll> a (n + 1); for (ll i {1}; i <= n; ++i) cin >> a[i];

    miv m {}; for (ll i {1}; i <= n; ++i) m[a[i]].push_back(i);

    dsu DSU (200001); for (ll i {1}; i <= n; ++i) {
        ll r = m[a[i]][m[a[i]].size() - 1];

        for (ll j {i}; j <= r; ++j) {
            DSU.unite(a[i], a[j]);
            r = max(r, m[a[j]][m[a[j]].size() - 1]);
        }

        i = r;
    }

    map<ll, si> s {}; for (ll i {1}; i <= n; ++i) s[DSU.find(a[i])].insert(a[i]);

    ll o {0};

    for (const auto& i : s) {
        ll g {0};

        for (ll j : i.second) {
            o += m[j].size();
            g = max(g, static_cast<ll>(m[j].size()));
        }

        o -= g;
    }

    cout << o << "\n";
}

int main() {
    io

    solve();

    return 0;
}