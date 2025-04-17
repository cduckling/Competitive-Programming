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
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vpii;
typedef vector<bool> vb;
typedef set<int> si;
typedef map<int, int> mi;
typedef map<int, vector<int>> mvi;
typedef map<int, pair<int, int>> mpii;
typedef map<int, bool> mb;

void solve() {
    int n {}; cin >> n;

    string s {}; cin >> s;

    char c = s[0]; int p = 0;

    for (int i {1}; i < n; ++i) if (s[i] <= c) { c = s[i]; p = i; }

    cout << s[p]; for (int i {0}; i < n; ++i) if (i != p) cout << s[i]; cout << "\n";
}

int main() {
    io
    tc

    return 0;
}