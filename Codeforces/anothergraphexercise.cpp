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
#define eb(a, b) emplace_back(a, b)
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

bool check(const int n, const int a, const int b, const int k, const int mid, const vvpii& adj) {
    vvpii ADJ (n + 1); for (int i = 1; i <= n; i++) for (const pii j : adj[i]) ADJ[i].eb(j.fir, (j.sec > mid));

    vi dist (n + 1, n); dist[a] = 0;

    deque<int> dq; dq.push_back(a);

    while (!dq.empty()) {
        const int ver = dq.front(); dq.pop_front();

        for (const pii i : ADJ[ver]) if (dist[ver] + i.sec < dist[i.fir]) {
            dist[i.fir] = dist[ver] + i.sec;

            if (i.sec) {
                dq.push_back(i.fir);
            } else {
                dq.push_front(i.fir);
            }
        }
    }

    return dist[b] < k;
}

void solve() {
    int n, m, q; cin >> n >> m >> q;

    vvpii adj (n + 1); for (int i = 1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].eb(v, w), adj[v].eb(u, w);
    }

    for (int i = 1; i <= q; i++) {
        int a, b, k; cin >> a >> b >> k;

        pii r = {1, 1e9};

        while (r.fir != r.sec) {
            const int mid = (r.fir + r.sec) / 2;

            if (check(n, a, b, k, mid, adj)) {
                r.sec = mid;
            } else {
                r.fir = mid + 1;
            }
        }

        cout << r.fir << " ";
    }

    cout << "\n";
}

int main() {
    io
    tc

    return 0;
}