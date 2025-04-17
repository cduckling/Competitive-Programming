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
typedef map<int, bool> mib;

void solve() {
    int n; cin >> n;

    vi a (n); for (int i = 0; i < n; i++) cin >> a[i]; sort(a.begin(), a.end());
    vi b (n); for (int i = 0; i < n; i++) cin >> b[i]; sort(b.begin(), b.end());

    si aa; for (const int i : a) aa.insert(i);
    si bb; for (const int i : b) bb.insert(i);

    if (aa.size() + bb.size() > 3) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    io
    tc

    return 0;
}