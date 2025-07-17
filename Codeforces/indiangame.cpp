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

map<int, int> dp; map<int, bool> vis;

int mex(vi &a) {
    sort(a.begin(), a.end()); int m = 0; for (const int i : a) if (i == m) m++; return m;
}

int msb(const int a) {
    for (int i = 29; i >= 0; i--) if ((a&1<<i) > 0) return i;
}

int g(const int s) {
    if (vis[s]) return dp[s];

    vi next; for (int i = 1; i <= msb(s); i++) next.pb(g((s>>i)|(s&((1<<i) - 1))));

    dp[s] = mex(next), vis[s] = true;

    return dp[s];
}

void solve() {
    int n; cin >> n;

    vi a (n); for (int i = 0; i < n; i++) cin >> a[i];

    map<int, int> p; for (int i = 0; i < n; i++) {
        for (int j = 2; j * j <= a[i]; j++) {
            if (a[i] % j != 0) continue;

            int cnt = 0; while (a[i] % j == 0) a[i] /= j, cnt++; p[j] |= 1<<cnt;
        }

        if (a[i] > 1) p[a[i]] |= 2;
    }

    int sum = 0; for (const pii i : p) sum ^= g(i.sec); cout << (sum == 0 ? "Arpa" : "Mojtaba") << "\n";
}

int main() {
    io

    dp[0] = 0, vis[0] = true;
    dp[1] = 0, vis[1] = true;

    solve();

    return 0;
}