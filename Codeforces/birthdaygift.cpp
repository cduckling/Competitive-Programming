#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <numeric>
using namespace std;

#define tc int t; cin >> t; while (t--) solve();
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pb(i) push_back(i);
#define inf 1e18;

typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vpii;
typedef vector<tuple<int, int, int>> vtiii;
typedef vector<bool> vb;
typedef multiset<int> msi;
typedef set<int> si;
typedef set<pair<int, int>> spii;
typedef set<tuple<int, int, int>> stiii;
typedef map<int, int> mi;
typedef map<int, vector<int>> mivi;
typedef map<int, pair<int, int>> mipii;
typedef map<int, bool> mib;

int segs(const si& rem, const vi& a) {
    int k = 1;

    mi bit; for (int i = 0; i < 30; i++) if ((a[0]&(1<<i)) && rem.count(i)) bit[i]++;

    for (int i = 1; i < a.size(); i++) {
        bool fin = true; for (const auto j : bit) if (j.second % 2 != 0) fin = false;

        if (fin) {
            k++; for (auto j : bit) j.second = 0;
        }

        for (int j = 0; j < 30; j++) if ((a[i]&(1<<j)) && rem.count(j)) bit[j]++;
    }

    return k;
}

void solve() {
    int n, f; cin >> n >> f;

    vi a (n); for (int i = 0; i < n; i++) cin >> a[i];

    vvi rep (n, vi (30)); for (int i = 0; i < n; i++) for (int j = 0; j < 30; j++) if ((a[i])&(1<<j)) rep[i][j] = true;

    vvi bit (30); for (int i = 0; i < 30; i++) for (int j = 0; j < n; j++) if (rep[j][i]) bit[i].pb(j);

    for (int i = 0; i < 30; i++) if (bit[i].size() % 2 != 0) {
        f -= (1<<i);

        for (int j = 0; j < n; j++) if (rep[j][i]) a[j] -= (1<<i);
    } if (f < 0) {
        cout << -1 << "\n"; return;
    }

    vi even; for (int i = 29; i >= 0; i--) if (bit[i].size() % 2 == 0 && bit[i].size()) even.pb(i);

    int k = 1;

    si rem; for (const int i : even) {
        if ((1<<i) > f) {
            rem.insert(i);
        } else {
            rem.insert(i); k = max(k, segs(rem, a));

            rem.erase(i); f -= (1<<i);
        }
    }

    k = max(k, segs(rem, a));

    cout << k << "\n";
}

int main() {
    io
    tc

    return 0;
}