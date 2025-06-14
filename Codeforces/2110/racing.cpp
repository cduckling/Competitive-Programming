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
#define inf (ll) 1e9
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

#define fail {cout << -1 << "\n"; return;}

pii inter(const pii a, const pii b) {
    return {max(a.fir, b.fir), min(a.sec, b.sec)};
}

void solve() {
    int n; cin >> n;

    vi d (n + 1); for (int i = 1; i <= n; i++) cin >> d[i];

    vpii lr (n + 1); for (int i = 1; i <= n; i++) cin >> lr[i].fir >> lr[i].sec;

    vpii ok (n + 1); ok[n] = {-inf, +inf};

    for (int i = n; i >= 1; i--) {
        ok[i] = inter(ok[i], lr[i]); if (ok[i].sec < ok[i].fir) fail

        if (d[i] == 1) {
            ok[i - 1] = {ok[i].fir - 1, ok[i].sec - 1};
        } else if (d[i] == 0) {
            ok[i - 1] = ok[i];
        } else {
            ok[i - 1] = {ok[i].fir - 1, ok[i].sec};
        }
    }

    pii start;

    if (d[1] == 1) {
        start = {1, 1};
    } else if (d[1] == 0) {
        start = {0, 0};
    } else {
        start = {0, 1};
    }

    start = inter(start, ok[1]); if (start.sec < start.fir) fail

    int h = 0;

    for (int i = 1; i <= n; i++) {
        if (d[i] == 1) {
            h++;
        } else if (d[i] == 0) {
            ;
        } else {
            if (ok[i].fir <= h && h <= ok[i].sec) {
                d[i] = 0;
            } else if (ok[i].fir <= h + 1 && h + 1 <= ok[i].sec) {
                d[i] = 1, h++;
            }
        }

        if (lr[i].fir > h || lr[i].sec < h) fail
    }

    for (int i = 1; i <= n; i++) cout << d[i] << " "; cout << "\n";
}

int main() {
    io
    tc

    return 0;
}