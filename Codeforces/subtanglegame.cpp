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
#define pb(a) push_back(a)
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
typedef vector<char> vc;
typedef vector<vector<char>> vvc;

void solve() {
    int s, n, m; cin >> s >> n >> m;

    vi a (s + 1); for (int i = 1; i <= s; i++) cin >> a[i];

    vvi b (n + 1, vi (m + 1)); for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cin >> b[i][j];

    vvb cur (n + 2, vb (m + 2)), prev (n + 2, vb (m + 2)); for (int i = n; i >= 1; i--) for (int j = m; j >= 1; j--) cur[i][j] = a[s] == b[i][j] || cur[i + 1][j] || cur[i][j + 1];

    for (int k = s - 1; k >= 1; k--) {
        swap(cur, prev); for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cur[i][j] = false;

        for (int i = n; i >= 1; i--) for (int j = m; j >= 1; j--) cur[i][j] = (a[k] == b[i][j] && !prev[i + 1][j + 1]) || cur[i + 1][j] || cur[i][j + 1];
    }

    cout << (cur[1][1] ? "T" : "N") << "\n";
}

int main() {
    io
    tc

    return 0;
}