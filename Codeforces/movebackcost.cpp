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

#define tc int t {}; cin >> t; while (t--) solve();
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
typedef map<int, int> mi;
typedef map<int, vector<int>> mvi;
typedef map<int, pair<int, int>> mpii;
typedef map<int, bool> mb;

void solve() {
    int n {}; cin >> n;

    vi a (n + 1); for (int i {1}; i <= n; ++i) cin >> a[i];

    priority_queue<pii> pq {}; for (int i {1}; i <= n; ++i) pq.emplace(-a[i], i);

    int pos = 0; pii r = {1e9, -1};

    vi b {}; msi l {};

    while (pos < n) {
        while (!pq.empty() && pq.top().second <= pos) pq.pop();

        int m = -pq.top().first, p = pq.top().second; while (pq.top().first == m) {
            p = pq.top().second; pq.pop();
        }

        if (m <= r.first) {
            for (int i = pos + 1; i <= p; ++i) if (a[i] == m) { b.pb(m); } else { l.insert(a[i] + 1); r.first = min(r.first, a[i] + 1), r.second = max(r.second, a[i] + 1); }
        } else {
            for (int i = pos + 1; i <= n; ++i) l.insert(a[i] + 1);
            break;
        }

        pos = p;

    }

    for (int i : b) cout << i << " "; for (int i : l) cout << i << " "; cout << "\n";
}

int main() {
    io
    tc

    return 0;
}