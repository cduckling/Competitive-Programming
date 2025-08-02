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
    int n; cin >> n;

    vi a (n + 1); for (int i = 1; i <= n; i++) cin >> a[i];

    vi steps (n + 2, -1); steps[n + 1] = 0; for (int i = n; i >= 1; i--) if (i + a[i] + 1 <= n + 1 && steps[i + a[i] + 1] != -1) steps[i] = steps[i + a[i] + 1] + 1;

    vi f (n, 2); for (int i = 1; i < n; i++) if (steps[i + 1] != -1) {
        if (steps[i + 1] == a[i]) {
            f[i] = 0;
        } else {
            f[i] = 1;
        }
    }

    vi best (n + 1); int done = 0; for (int i = n; i >= 1; i--) {
        best[i] = max(steps[i], max(1 + done, (i + a[i] + 1 <= n + 1 ? 1 + best[i + a[i] + 1] : -1)));

        if (steps[i] != -1) done = max(done, steps[i]);
    }

    for (int i = 1; i < n; i++) if (f[i] == 2 && a[i] <= best[i + 1]) f[i] = 1;

    for (int i = 1; i < n; i++) cout << f[i] << " "; cout << "\n";
}

int main() {
    io
    tc

    return 0;
}