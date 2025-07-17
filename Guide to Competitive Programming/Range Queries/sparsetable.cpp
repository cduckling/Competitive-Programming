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

#define io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pb(i) push_back(i);
#define inf 1e18;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vpii;
typedef vector<bool> vb;
typedef set<int> si;
typedef map<int, int> mi;
typedef map<int, vector<int>> mvi;
typedef map<int, pair<int, int>> mpii;
typedef map<int, bool> mb;

int e[31];

int main() {
    io

    e[0] = 1; for (int i {1}; i <= 30; ++i) e[i] = e[i - 1] * 2;

    int n {}; cin >> n;

    vector<int> a (n); for (int i {0}; i < n; ++i) cin >> a[i];

    vector<vector<int>> st (n, vector<int> (static_cast<int>(log2(n)) + 1)); for (int i {0}; i < n; ++i) st[i][0] = a[i];

    for (int l {1}; l <= log2(n); ++l) for (int p {0}; p < n - e[l] + 1; ++p) st[p][l] = min(st[p][l - 1], st[p + e[l - 1]][l - 1]);

    int q {}; cin >> q;

    for (int i {0}; i < q; ++i) {
        int u {}, v {}; cin >> u >> v;

        int l = static_cast<int>(log2(v - u + 1));

        cout << min(st[u][l], st[v - e[l] + 1][l]) << "\n";
    }

    return 0;
}