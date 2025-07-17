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
#define pb(i) push_back(i);
#define inf 1e18;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vpii;
typedef vector<bool> vb;
typedef set<int> si;
typedef map<int, int> mi;
typedef map<int, vector<int>> mvi;
typedef map<int, pair<int, int>> mpii;
typedef map<int, bool> mb;

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

    const auto rerooter = [](const auto& adj, const auto& base, const auto& merge, const auto& fin) {
        int n = (int)adj.size();
        using inter = decay_t<decltype(base(0))>;
        using val = decay_t<decltype(fin(base(0), 0, 0))>;
        vector<val> root_dp(n), dp(n);
        vector<vector<val>> edge_dp(n), redge_dp(n);

        vector<int> bfs, parent(n);
        bfs.reserve(n);
        bfs.push_back(0);
        for (int i = 0; i < n; ++i) {
            int u = bfs[i];
            for (auto v : adj[u]) {
                if (parent[u] == v) continue;
                parent[v] = u;
                bfs.push_back(v);
            }
        }

        for (int i = n - 1; i >= 0; --i) {
            int u = bfs[i];
            int p_ind = -1;
            inter inter = base(u);
            for (int ind = 0; ind < (int)adj[u].size(); ++ind) {
                int v = adj[u][ind];
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
            edge_dp[u].reserve(adj[u].size());
            for (auto v : adj[u]) edge_dp[u].push_back(dp[v]);
            auto dp_exclusive = exclusive(edge_dp[u], base(u), merge, u);
            redge_dp[u].reserve(adj[u].size());
            for (int i = 0; i < (int)dp_exclusive.size(); ++i) redge_dp[u].push_back(fin(dp_exclusive[i], u, i));
            root_dp[u] = fin(n > 1 ? merge(dp_exclusive[0], edge_dp[u][0], u, 0) : base(u), u, -1);
            for (int i = 0; i < (int)adj[u].size(); ++i) dp[adj[u][i]] = redge_dp[u][i];
        }

        return make_tuple(move(root_dp), move(edge_dp), move(redge_dp));
    };
}

void solve() {
    int n {}; cin >> n;

    vvi adj (n); for (int i {1}; i < n; ++i) {
        int u {}, v {}; cin >> u >> v; --u, --v;
        adj[u].pb(v); adj[v].pb(u);
    }

    using inter = int; using val = int;

    auto base = [](int ver) -> inter {
        return 0;
    };
    auto merge = [](inter par, val child, int ver, int ind) -> inter {
        return max(par, child + 1);
    };
    auto fin = [&](inter par, int ver, int ind) -> val {
        return par;
    };
    auto [res, edge_dp, redge_dp] = reroot::rerooter(adj, base, merge, fin);

    vi dp (n + 1); for (int i {0}; i < n; ++i) dp[i + 1] = res[i]; sort(dp.begin(), dp.end());

    int p {0};

    for (int i {1}; i <= n; ++i) {
        while (p <= n && dp[p] < i) ++p;
        cout << (p - 1) + ((p - 1 == n) ? 0 : 1) << " ";
    }

    cout << "\n";
}

int main() {
    io

    solve();

    return 0;
}