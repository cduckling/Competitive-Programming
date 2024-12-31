#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

typedef long long ll;

ll DEG[100000], Q[200000];

struct SEGTREE {
    ll N;

    SEGTREE(ll n) {
        N = n;

        for (ll i {0}; i < N; ++i) add(i, i);
    }

    ll query(ll a, ll b) {
        a += N, b += N;

        ll pos = 0;

        while (a <= b) {
            if (a % 2 == 1) {
                if (DEG[Q[a]] < DEG[pos]) pos = Q[a]; ++a;
            }

            if (b % 2 == 0) {
                if (DEG[Q[b]] < DEG[pos]) pos = Q[b]; --b;
            }

            a /= 2; b /= 2;
        }

        return pos;
    }

    void add(ll pos, ll c) {
        pos += N; Q[pos] += c;

        for (pos /= 2; pos >= 1; pos /= 2) {
            Q[pos] = Q[2 * pos];

            if (DEG[Q[2 * pos + 1]] < DEG[Q[pos]]) Q[pos] = Q[2 * pos + 1];
        }
    }
};

ll PARS[100000], SIZES[100000];

class DSU {
public:
    DSU(ll n) {
        for (ll i {0}; i < n; i++) PARS[i] = i, SIZES[i] = 1;
    }

    ll root(ll x) {
        return PARS[x] == x ? x : (PARS[x] = root(PARS[x]));
    }

    void unite(ll a, ll b) {
        if (root(a) == root(b)) return;

        ll A = root(a), B = root(b);

        if (SIZES[A] < SIZES[B]) swap(A, B);

        SIZES[A] += SIZES[B]; PARS[B] = A;
    }

    bool connected(ll x, ll y) {
        return root(x) == root(y);
    }
};

vector<ll> ADJ[100000];

void solve() {
    ll n {}, m {}; cin >> n >> m;

    for (ll i {0}; i < m; ++i) {
        ll u {}, v {}; cin >> u >> v; --u; --v;
        ADJ[u].push_back(v); ADJ[v].push_back(u);
    }

    for (ll i {0}; i < n; ++i) DEG[i] = ADJ[i].size();

    SEGTREE g (n); vector<ll> o {}; for (ll i {0}; i < n; ++i) {
        ll ver = g.query(0, n - 1);

        o.push_back(ver);

        for (ll j : ADJ[ver]) {
            if (DEG[j] != 1e9) --DEG[j];
            g.add(j, 0);
        }

        DEG[ver] = 1e9; g.add(ver, 0);
    } reverse(o.begin(), o.end());

    ll s = 0; DSU c (n); set<ll> p {};

    for (const ll i : o) {
        p.insert(i);

        ll deg = 0; for (ll j : ADJ[i]) if (p.count(j)) { ++deg; c.unite(i, j);}

        s = max(s, deg * SIZES[c.root(i)]);
    }

    cout << s << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    solve();

    return 0;
}