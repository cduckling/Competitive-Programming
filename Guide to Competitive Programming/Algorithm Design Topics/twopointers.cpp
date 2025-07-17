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

int main() {
    io

    int n, t; cin >> n >> t;

    vi a (n + 1); for (int i = 1; i <= n; ++i) cin >> a[i];

    vi pref (n + 1); for (int i = 1; i <= n; ++i) pref[i] = a[i] + pref[i - 1];

    pii p {0, 0};

    while (pref[p.second] - pref[p.first] != t) {
        if (pref[p.second] - pref[p.first] < t) {
            ++p.second;
        } else {
            ++p.first;
        }

        if (p.first > n) {
            --p.first;
            break;
        }

        if (p.second > n) {
            --p.second; break;
        }
    }

    if (p.first == n && p.second == n) {
        cout << "NO\n"; return 0;
    }

    cout << p.first + 1 << " " << p.second << "\n";

    return 0;
}