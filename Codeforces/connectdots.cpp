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

#define tc ll t {}; cin >> t; while (t--) solve();
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pb(i) push_back(i);
#define inf 1e18;

typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;
typedef vector<pair<ll, ll>> vpii;
typedef vector<bool> vb;
typedef set<ll> si;
typedef map<ll, ll> mi;
typedef map<ll, vector<ll>> mvi;
typedef map<ll, pair<ll, ll>> mpii;
typedef map<ll, bool> mb;

class DSU {
public:
    vi pars, sizes;

    DSU(ll n) : pars(n), sizes(n, 1) {
        for (ll i {0}; i < n; i++) { pars[i] = i; sizes[i] = 1; }
    }

    ll root(ll x) {
        return pars[x] == x ? x : (pars[x] = root(pars[x]));
    }

    void unite(ll a, ll b) {
        ll A = root(a), B = root(b);

        if (sizes[A] < sizes[B]) swap(A, B);

        sizes[A] += sizes[B]; pars[B] = A;
    }

    bool connected(ll x, ll y) {
        return root(x) == root(y);
    }
};

void solve() {
    ll n {}, m {}; cin >> n >> m;

    DSU line (n + 1);

    vector seq (11, vector<vector<pii>> (10));

    for (ll i {0}; i < m; ++i) {
        ll a {}, d {}, k {}; cin >> a >> d >> k;

        seq[d][a % d].emplace_back(a, k);
    }

    for (ll i {1}; i <= 10; ++i) for (ll j {0}; j < i; ++j) sort(seq[i][j].begin(), seq[i][j].end());

    for (ll i {1}; i <= 10; ++i) {
        for (ll j {0}; j < i; ++j) {
            if (seq[i][j].empty()) continue;

            vpii block {}; block.emplace_back(seq[i][j][0].first, seq[i][j][0].first + i * seq[i][j][0].second);

            for (ll k {1}; k < seq[i][j].size(); ++k) {
                if (seq[i][j][k].first <= block[block.size() - 1].second) {
                    block[block.size() - 1].second = max(block[block.size() - 1].second, seq[i][j][k].first + i * seq[i][j][k].second);
                } else {
                    block.emplace_back(seq[i][j][k].first, seq[i][j][k].first + i * seq[i][j][k].second);
                }
            }

            for (auto [srt, end] : block) for (ll p = srt; p <= end; p += i) line.unite(srt, p);
        }
    }

    si r {}; for (ll i {1}; i <= n; ++i) r.insert(line.root(i)); cout << r.size() << "\n";
}

int main() {
    io
    tc

    return 0;
}