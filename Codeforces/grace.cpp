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

#define tc int t; cin >> t; while (t--) solve();
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(a) (a).begin(), (a).end()
#define pb(i) push_back(i)
#define eb(i) emplace_back(i)
#define inf (ll) 1e18
#define f first
#define s second

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

#define fail {cout << -1 << "\n"; return;}

pii inv(const pii& a) {
    return {a.s, a.f};
}

void solve() {
    int n; cin >> n;

    vi a (n + 1), b (n + 1); for (int i = 1; i <= n; i++) cin >> a[i]; for (int i = 1; i <= n; i++) cin >> b[i];

    vpii g (n + 1); for (int i = 1; i <= n; i++) g[i] = {a[i], b[i]};

    map<pii, int> pos; for (int i = 1; i <= n; i++) pos[g[i]] = i;

    for (int i = 1; i <= n; i++) if (pos[{b[i], a[i]}] == 0) fail

    int cnt = 0; for (int i = 1; i <= n; i++) if (a[i] == b[i]) cnt++; if ((cnt > 0 && n % 2 == 0) || (cnt != 1 && n % 2 != 0)) fail

    vpii ops;

    if (n % 2 != 0) {
        for (int i = 1; i <= n; i++) if (a[i] == b[i]) {
            if (i == (n + 1) / 2) break;

            ops.emplace_back((n + 1) / 2, i);
            swap(g[(n + 1) / 2], g[i]);
            pos[g[i]] = i, pos[g[(n + 1) / 2]] = (n + 1) / 2;

            break;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (n % 2 != 0 && (n + 1) / 2 == i) continue;

        int old = pos[inv(g[i])];

        if (n - i + 1 == old) continue;

        ops.emplace_back(n - i + 1, old);
        swap(g[n - i + 1], g[old]);
        pos[g[old]] = old, pos[g[n - i + 1]] = n - i + 1;
    }

    cout << ops.size() << "\n";

    for (const pii i : ops) cout << i.f << " " << i.s << "\n";
}

int main() {
    io
    tc

    return 0;
}