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

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef set<int> si;
typedef map<int, int> mii;
typedef map<int, vector<int>> miv;

void solve() {
    vector<pii> a (3); for (int i {0}; i < 3; ++i) cin >> a[i].first >> a[i].second;

    vector<pii> p {}, q {}; for (pii i : a) {
        if (i.second == 0) {
            p.push_back(i);
        } else {
            q.push_back(i);
        }
    }

    sort(p.begin(), p.end());

    cout << abs(p[1].first - p[0].first) * abs(q[0].second) * 5 << "\n";
}

int main() {
    io
    tc

    return 0;
}