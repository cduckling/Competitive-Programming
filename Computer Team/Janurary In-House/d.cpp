#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
using namespace std;

#define tc ll t; cin >> t; while (t--) solve();
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(a) (a).begin(), (a).end()
#define pb(i) push_back(i)
#define eb(a, b) emplace_back(a, b)
#define ceil(a, b) ((a + b - 1) / b)
#define inf 1e18
#define fail cout << -1 << "\n"; return;

typedef long long ll;
typedef pair<ll, ll> pii;
typedef tuple<ll, ll, ll> tiii;
typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;
typedef vector<set<ll>> vsi;
typedef vector<pair<ll, ll>> vpii;
typedef vector<vector<pair<ll, ll>>> vvpii;
typedef vector<tuple<ll, ll, ll>> vtiii;
typedef vector<bool> vb;
typedef multiset<ll> msi;
typedef set<ll> si;
typedef set<pair<ll, ll>> spii;
typedef set<tuple<ll, ll, ll>> stiii;
typedef map<ll, ll> mii;
typedef map<ll, vector<ll>> mivi;
typedef map<ll, pair<ll, ll>> mipii;
typedef map<ll, set<ll>> misi;
typedef map<ll, bool> mib;

void solve() {
    ll n, m; cin >> n >> m;

    vvpii adj (n); for (ll i = 0; i < m; i++) {
        ll u, v, w; cin >> u >> v >> w; u--, v--;
        adj[u].eb(v, w), adj[v].eb(u, w);
    }

    vi dist (n, inf), lag (n, inf); vb vis (n);

    priority_queue<tiii> pq; pq.emplace(0, 0, 0);

    while (!pq.empty()) {
        tiii cur = pq.top(); pq.pop();

        const ll t = -get<0>(cur), l = -get<1>(cur), s = get<2>(cur);

        if (vis[s]) continue; vis[s] = true;

        for (const auto [sev, del] : adj[s]) {
            const ll T = t + del, L = max(l, del);

            if (T < dist[sev]) {
                dist[sev] = T, lag[sev] = L;
                pq.emplace(-T, -L, sev);
            } else if (T == dist[sev] && L < lag[sev]) {
                lag[sev] = L;
                pq.emplace(-T, -L, sev);
            }
        }
    }

    cout << dist[n - 1] + lag[n - 1] << "\n";
}

int main() {
    io

    solve();

    return 0;
}