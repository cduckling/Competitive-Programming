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
typedef tuple<int, int, int> tiii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vpii;
typedef vector<tuple<int, int, int>> vtiii;
typedef vector<bool> vb;
typedef set<int> si;
typedef map<int, int> mi;
typedef map<int, vector<int>> mvi;
typedef map<int, pair<int, int>> mpii;
typedef map<int, bool> mb;

int main() {
    io

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

        bool p = false;

        if (len % 2 == 0) {
            const int mid = (l + r + 1) / 2;

            if (m[0][mid] >= len / 2) p = true;
        } else {
            const int mid = (l + r) / 2;

            if (m[1][mid] >= (len - 1) / 2) p = true;
        }

        cout << (p ? "YES" : "NO");
    }

    return 0;
}