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
    int n, m, k; cin >> n >> m >> k;

    vpii lr (m + 1); for (int i = 1; i <= m; i++) cin >> lr[i].fir >> lr[i].sec; sort(all(lr));

    vi days (n + 2); for (int i = 1; i <= m; i++) days[lr[i].fir]++, days[lr[i].sec + 1]--; for (int i = 1; i <= n; i++) days[i] += days[i - 1];

    vvi rain (n + 1);

    int day = 1; spii r;

    for (int i = 1; i <= n; i++) {
        while (day <= m && lr[day].fir <= i) r.insert({lr[day].sec, day++});
        while (!r.empty() && r.begin()->fir < i) r.erase(r.begin());

        if (days[i] == 2) {
            rain[i].pb(r.begin()->sec); rain[i].pb((++r.begin())->sec);
        } else if (days[i] == 1) {
            rain[i].pb(r.begin()->sec);
        }
    }

    int cnt = 0; for (int i = 1; i <= n; i++) cnt += !days[i];

    vi one (m + 1); for (int i = 1; i <= n; i++) if (days[i] == 1) one[rain[i][0]]++;

    map<pii, int> two; for (int i = 1; i <= n; i++) if (days[i] == 2) two[{rain[i][0], rain[i][1]}]++;

    int res = 0; for (const auto i : two) res = max(res, i.sec + one[i.fir.fir] + one[i.fir.sec]);

    sort(all(one), greater<int>()); res = max(res, one[0] + one[1]);

    cout << res + cnt << "\n";
}

int main() {
    io
    tc

    return 0;
}