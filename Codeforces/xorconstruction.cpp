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

void solve() {
    int n; cin >> n;

    vi a (n); for (int i = 1; i < n; ++i) cin >> a[i];

    vi pref (n); for (int i = 1; i < n; i++) pref[i] = pref[i - 1] ^ a[i];

    vi cnt (30); for (int i = 0; i < n; i++) for (int j = 0; j < 30; j++) cnt[j] += (i&1<<j) > 0;

    int res = 0;

    for (int i = 0; i < 30; i++) {
        int val = 0; for (int j = 1; j < n; j++) val += (pref[j]&1<<i) > 0;

        if (val != cnt[i]) res += 1<<i;
    }

    vi b (n + 1); b[1] = res; for (int i = 2; i <= n; i++) b[i] = res ^ pref[i - 1]; for (int i = 1; i <= n; i++) cout << b[i] << " "; cout << "\n";
}

int main() {
    io

    solve();

    return 0;
}