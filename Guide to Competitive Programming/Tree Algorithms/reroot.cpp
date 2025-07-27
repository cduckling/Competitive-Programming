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
typedef vector<char> vc;
typedef vector<vector<char>> vvc;

namespace reroot {
    const auto exclusive = [](const auto& a, const auto& base, const auto& merge, int ver) {
        int n = (int)a.size();
        using inter = decay_t<decltype(base)>;
        vector<inter> b(n, base);
        for (int bit = (int)log2(n); bit >= 0; --bit) {
            for (int i = n - 1; i >= 0; --i) b[i] = b[i >> 1];
            int sz = n - (n & !bit);
            for (int i = 0; i < sz; ++i) {
                int index = (i >> bit) ^ 1;
                b[index] = merge(b[index], a[i], ver, i);
            }
        }
        return b;
    };

    const auto rerooter = [](const auto& g, const auto& base, const auto& merge, const auto& fin) {
        int n = (int)g.size();
        using inter = decay_t<decltype(base(0))>;
        using val = decay_t<decltype(fin(base(0), 0, 0))>;
        vector<val> root_dp(n), dp(n);
        vector<vector<val>> edge_dp(n), redge_dp(n);

        vector<int> bfs, parent(n);
        bfs.reserve(n);
        bfs.push_back(0);
        for (int i = 0; i < n; ++i) {
            int u = bfs[i];
            for (auto v : g[u]) {
                if (parent[u] == v) continue;
                parent[v] = u;
                bfs.push_back(v);
            }
        }

        for (int i = n - 1; i >= 0; --i) {
            int u = bfs[i];
            int p_ind = -1;
            inter inter = base(u);
            for (int ind = 0; ind < (int)g[u].size(); ++ind) {
                int v = g[u][ind];
                if (parent[u] == v) {
                    p_ind = ind;
                    continue;
                }
                inter = merge(inter, dp[v], u, ind);
            }
            dp[u] = fin(inter, u, p_ind);
        }

        for (auto u : bfs) {
            dp[parent[u]] = dp[u];
            edge_dp[u].reserve(g[u].size());
            for (auto v : g[u]) edge_dp[u].push_back(dp[v]);
            auto dp_exclusive = exclusive(edge_dp[u], base(u), merge, u);
            redge_dp[u].reserve(g[u].size());
            for (int i = 0; i < (int)dp_exclusive.size(); ++i) redge_dp[u].push_back(fin(dp_exclusive[i], u, i));
            root_dp[u] = fin(n > 1 ? merge(dp_exclusive[0], edge_dp[u][0], u, 0) : base(u), u, -1);
            for (int i = 0; i < (int)g[u].size(); ++i) dp[g[u][i]] = redge_dp[u][i];
        }

        return make_tuple(move(root_dp), move(edge_dp), move(redge_dp));
    };
}

int main() {
    io

    int n; cin >> n;

    vvi adj (n); for (int i = 2; i <= n; i++) {
        int u, v; cin >> u >> v; u--; v--;
        adj[u].pb(v), adj[v].pb(u);
    }

    using inter = int; using val = int;

    auto base = [](int ver) -> inter {
        return 1;
    };
    auto merge = [](inter par, val child, int ver, int ind) -> inter {
        return max(par, child + 1);
    };
    auto fin = [&](inter par, int ver, int ind) -> val {
        return par;
    };

    auto [res, edge_dp, redge_dp] = reroot::rerooter(adj, base, merge, fin);

    for (int i = 0; i < n; i++) cout << res[i] << " "; cout << "\n";

    return 0;
}
