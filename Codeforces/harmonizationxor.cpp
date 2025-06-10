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

int msb(const int n) {
    for (int i = 29; i >= 0; i--) if ((1<<i&n) > 0) return i;
}

void solve() {
    int n, k, v; cin >> n >> k >> v;

    vi bit (30); for (int i = 1; i <= n; i++) for (int j = 0; j < 30; j++) if ((1<<j&i) > 0) bit[j]++, bit[j] %= 2;

    int res = 0; for (int i = 0; i < 30; i++) if (bit[i]) res += 1<<i; if (k % 2 == 0 && res != 0) fail if (k % 2 != 0 && res != v) fail if (msb(v) > msb(n)) fail

    vb tkn (n + 1);

    vvi s;

    for (int i = 1; i <= n; i++) {
        if (tkn[i]) continue;

        if (i == v) {
            s.eb();

            s[s.size() - 1].pb(i);

            tkn[i] = true;
        } else if ((v^i) <= n && !tkn[(v^i)]) {
            s.eb();

            s[s.size() - 1].pb(i), s[s.size() - 1].pb(v^i);

            tkn[i] = true, tkn[(v^i)] = true;
        }
    }

    s.eb(); for (int i = 1; i <= n; i++) if (!tkn[i]) s[s.size() - 1].pb(i); if (s[s.size() - 1].empty()) s.pop_back();

    if (s.size() < k) fail

    for (int i = k; i < s.size(); i++) for (const int j : s[i]) s[k - 1].pb(j);

    int last = 0; for (const int i : s[k - 1]) last ^= i; if (last != v) fail

    cout << "YES\n";

    for (int i = 0; i < k; i++) {
        cout << s[i].size() << " "; for (const int j : s[i]) cout << j << " "; cout << "\n";
    }
}

int main() {
    io
    tc

    return 0;
}