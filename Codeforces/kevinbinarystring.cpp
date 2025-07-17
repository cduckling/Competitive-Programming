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

#define fail {cout << -1 << "\n"; return;}

void solve() {
    string s, t; cin >> s >> t; s = " " + s, t = " " + t;

    const ll n = s.size();

    vpii blx[2]; blx[0].eb(s[1] == '1', 1), blx[1].eb(t[1] == '1', 1); for (int i = 2; i <= n; i++) {
        if (s[i] == s[i - 1]) {
            blx[0][blx[0].size() - 1].sec = i;
        } else {
            blx[0].eb(s[i] == '1', 1);
        }

        if (t[i] == t[i - 1]) {
            blx[1][blx[1].size() - 1].sec = i;
        } else {
            blx[1].eb(t[i] == '1', 1);
        }
    }

    si a, b; for (const pii i : blx[0]) a.insert(i.sec); for (const pii i : blx[1]) b.insert(i.sec); for (const int i : b) if (!a.count(i)) fail


}

/*
 * math, constructive, standard
 *
 * consider invariants: obviously the operations will keep something constant; parity? some kind of sorting?
 *
 * obviously # of blocks decreases by 2, parity will remain constant?
 *
 * if one of the border blocks, it will decrease by 1?
 *
 * pherhaps if this is wanted, do it automatically?
 */

int main() {
    io
    tc

    return 0;
}