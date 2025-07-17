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
#define inf 1e16
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
typedef vector<vector<bool>> vvb;
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
    ll c, n, m; cin >> c >> n >> m;

    vpii mc (n + 2); for (ll i = 1; i <= n; i++) cin >> mc[i].first >> mc[i].second;

    vvpii adj (n + 2); for (ll i = 0; i < m; i++) {
        ll a, b, t; cin >> a >> b >> t;
        adj[a].emplace_back(b, t);
    }

    priority_queue<tiii> pq; pq.emplace(0, -c, 0);

    vvb vis (n + 2, vb (101));
    vvi val (n + 2, vi (101, inf));

    while (!pq.empty()) {
        ll time = -get<0>(pq.top()), bat = -get<1>(pq.top()), to = get<2>(pq.top()); pq.pop();

        if (vis[to][bat]) continue; vis[to][bat] = true;

        for (const auto [pos, wait] : adj[to]) {
            if (bat - wait > 0 && time + wait < val[pos][bat - wait]) {
                val[pos][bat - wait] = time + wait;

                pq.emplace(-val[pos][bat - wait], -(bat - wait), pos);
                pq.emplace(-(val[pos][bat - wait] + mc[pos].first), -(bat - wait + mc[pos].second), pos);
            }
        }
    }

    ll cost = inf; for (const ll i : val[n + 1]) cost = min(cost, i);

    if (cost == inf) {
        cout << -1 << "\n"; return;
    }

    cout << cost << "\n";
}

int main() {
    io

    solve();

    return 0;
}