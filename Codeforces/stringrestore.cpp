#include <iostream>
#include <vector>
#include <set>
#include <map>
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
#define ceil(a, b) ((a + b - 1) / b)
#define inf (ll) 1e18
#define fail {cout << "NO\n"; return;}

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
typedef map<int, int> mii;
typedef map<int, bool> mib;
typedef map<int, double> mid;
typedef vector<map<int, int>> vmii;
typedef vector<map<int, double>> vmid;
typedef vector<map<int, bool>> vmib;

si in[26], out[26];
bool vis[26]; si val;

bool lin; string res;

void dfs(const int ver) {
    if (out[ver].size() > 1 || vis[ver]) {
        lin = false; return;
    }

    vis[ver] = true; val.insert(ver);

    res += static_cast<char>('a' + ver);

    if (!out[ver].empty()) dfs(*out[ver].begin());
}

void solve() {
    int n; cin >> n;

    vs w (n); for (int i = 0; i < n; i++) cin >> w[i]; sort(all(w));

    si pres; for (int i = 0; i < n; i++) for (const char j : w[i]) pres.insert(j - 'a');

    for (int i = 0; i < n; i++) for (int j = 0; j < w[i].size() - 1; j++) out[w[i][j] - 'a'].insert(w[i][j + 1] - 'a'), in[w[i][j + 1] - 'a'].insert(w[i][j] - 'a');

    vs p;

    for (const int i : pres) {
        if (!in[i].empty()) continue;

        lin = true, res = ""; dfs(i);

        if (!lin) fail
        p.pb(res);
    }

    if (val.size() < pres.size()) fail

    sort(all(p)); for (const string i : p) cout << i; cout << "\n";
}

int main() {
    io

    solve();

    return 0;
}