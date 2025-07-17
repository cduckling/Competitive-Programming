#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
using namespace std;

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")

#define tc int t; cin >> t; while (t--) solve();
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(a) (a).begin(), (a).end()
#define pb(i) push_back(i)
#define eb(i) emplace_back(i)
#define inf (ll) 1e18
#define fir first
#define sec second

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
typedef vector<double> vd;
typedef vector<vector<double>> vvd;
typedef vector<vector<vector<double>>> vvvd;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef vector<vector<vector<bool>>> vvvb;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vpii;
typedef vector<vector<pair<int, int>>> vvpii;
typedef vector<vector<vector<pair<int, int>>>> vvvpii;
typedef tuple<int, int, int> tiii;
typedef vector<tuple<int, int, int>> vtiii;
typedef vector<vector<tuple<int, int, int>>> vvtiii;
typedef vector<vector<vector<tuple<int, int, int>>>> vvvtiii;
typedef vector<string> vs;
typedef vector<vector<string>> vvs;
typedef set<int> si;
typedef vector<set<int>> vsi;
typedef vector<vector<set<int>>> vvsi;
typedef set<pair<int, int>> spii;
typedef vector<set<pair<int, int>>> vspii;
typedef map<int, int> mii;
typedef map<int, bool> mib;
typedef map<int, double> mid;
typedef vector<map<int, int>> vmii;
typedef vector<map<int, double>> vmid;
typedef vector<map<int, bool>> vmib;

#define fail {cout << "NO\n"; return;}

void dfs(const int ver, vi& p, map<int, set<pii>>& adj) {
    while (!adj[ver].empty()) {
        const int nxt = adj[ver].begin()->first, id = adj[ver].begin()->second;

        adj[ver].erase({nxt, id}), adj[nxt].erase({ver, id});

        dfs(nxt, p, adj); p.pb(id);
    }
}

void solve() {
    int n; cin >> n;

    map<int, set<pii>> adj; for (int i = 1; i <= n; i++) {
        int v, p; cin >> v >> p; v *= -1;
        adj[v].emplace(p, i), adj[p].emplace(v, i);
    }

    int cnt = 0, ver = adj.begin()->first; for (const auto& i : adj) if (adj[i.first].size() % 2) ver = i.first, cnt++; if (cnt != 0 && cnt != 2) fail

    vi p; dfs(ver, p, adj);

    if (p.size() != n) fail cout << "YES\n"; reverse(all(p)); for (const int i : p) cout << i << " "; cout << "\n";
}

int main() {
    io
    tc

    return 0;
}