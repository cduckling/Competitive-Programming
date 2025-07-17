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

void solve() {
    int n; cin >> n;

    vpii b (n + 1); for (int i = 1; i <= n; i++) cin >> b[i].fir >> b[i].sec;

    vvi good (30), bad (30);

    for (int i = 1; i <= n; i++) {
        if (b[i].sec % 2 != 0) good[0].pb(i);

        for (int j = 1; j < 30; j++) if ((b[i].sec&1<<j) > 0) {
            if ((b[i].sec|(1<<j) - 1) - (1<<j) < b[i].fir) {
                good[j].pb(i);
            }  else {
                bad[j].pb(i);
            }
        }
    }

    int q; cin >> q;

    for (int i = 1; i <= q; i++) {
        int l, r; cin >> l >> r;

        int res = 0;

        for (int j = 29; j >= 0; j--) {
            const int G = --upper_bound(all(good[j]), r) - lower_bound(all(good[j]), l) + 1, B = --upper_bound(all(bad[j]), r) - lower_bound(all(bad[j]), l) + 1;

            if (G) res |= 1<<j;

            if (G + B >= 2 && B) {
                res |= (1<<(j + 1)) - 1; break;
            }

            if (G + B == 1) {
                res |= 1<<j;
            }
        }

        cout << res << " ";
    }

    cout << "\n";
}

int main() {
    io
    tc

    return 0;
}