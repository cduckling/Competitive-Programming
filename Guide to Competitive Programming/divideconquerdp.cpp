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

#define square(a) ((a) * (a))

int cost(const int l, const int r, const vi& pref) {
    return square(pref[r] - pref[l - 1]);
}

void calc(const int j, pii solve, pii pos, const vi& a, const vi& pref, vvi& dp) {
    if (solve.fir > solve.sec) return;

    const int mid = (solve.fir + solve.sec) / 2;

    int res = pos.fir; for (int i = pos.fir; i <= min(pos.sec, mid - 1); i++) if (dp[j - 1][i] + cost(i + 1, mid, pref) < dp[j - 1][res] + cost(res + 1, mid, pref)) res = i;

    dp[j][mid] = dp[j - 1][res] + cost(res + 1, mid, pref);

    if (solve.fir == solve.sec) return;

    calc(j, {solve.fir, mid - 1}, {pos.fir, res}, a, pref, dp);
    calc(j, {mid + 1, solve.sec}, {res, pos.sec}, a, pref, dp);
}

int main() {
    io

    int n, k; cin >> n >> k;

    vi a (n + 1); for (int i = 1; i <= n; i++) cin >> a[i];

    vi pref (n + 1); for (int i = 1; i <= n; i++) pref[i] = pref[i - 1] + a[i];

    vvi dp (k + 1, vi (n + 1)); for (int i = 1; i <= n; i++) dp[1][i] = square(pref[i]);

    for (int i = 2; i <= k; i++) calc(i, {1, n}, {1, n}, a, pref, dp);

    cout << dp[k][n] << "\n";

    return 0;
}