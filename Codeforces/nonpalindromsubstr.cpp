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
	int n, q; cin >> n >> q;

    string s; cin >> s;

    vvi m (2, vi (n)); for (int j = 0, l = 0, r = 0; j < 2; j++, l = 0, r = 0) {
        for (int i = 0; i < n; i++) {
            if (i < r) m[j][i] = min(r - i + !j, m[j][l + r - i + !j]);
            while (i - m[j][i] - 1 >= 0 && i + m[j][i] + 1 - !j < n && s[i - m[j][i] - 1] == s[i + m[j][i] + 1 - !j]) m[j][i]++;
            if (i + m[j][i] - !j > r) l = i - m[j][i], r = i + m[j][i]- !j;
        }
    }

    for (int i = 0; i < q; i++) {
        int l, r; cin >> l >> r; l--; r--;

        const int len = r - l + 1;


    }
}

int main() {
    io
    tc

    return 0;
}