#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
using namespace std;

#define tc int t; cin >> t; while (t--) solve();
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(a) (a).begin(), (a).end()
#define pb(i) push_back(i);
#define ceil(a, b) ((a + b - 1) / b)
#define inf 1e18

typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<set<int>> vsi;
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
typedef map<int, set<int>> misi;
typedef map<int, bool> mib;

void solve() {
    int n, q; cin >> n >> q;

    vi a (n + 1); for (int i = 1; i <= n; i++) cin >> a[i];

    vi p (n + 1); for (int i = 1; i <= n; i++) p[i] = p[i - 1]^a[i];

    mivi m; for (int i = 1; i <= n; i++) m[p[i]].pb(i);

    for (int i = 0; i < q; i++) {
        int l, r; cin >> l >> r;

        const int y = p[l - 1]^p[r];

        if (y == 0) {
            cout << "YES\n";
        } else {
            const int f = p[l - 1]^y, s = p[l - 1];

            const int fir = upper_bound(all(m[f]), l - 1) - m[f].begin();

            if (fir == m[f].size() || m[f][fir] >= r) {
                cout << "NO\n"; continue;
            }

            const int sec = upper_bound(all(m[s]), m[f][fir]) - m[s].begin();

            if (sec == m[s].size() || m[s][sec] >= r) {
                cout << "NO\n"; continue;
            }

            cout << "YES\n";
        }
    }

    cout << "\n";
}

int main() {
    io
    tc

    return 0;
}