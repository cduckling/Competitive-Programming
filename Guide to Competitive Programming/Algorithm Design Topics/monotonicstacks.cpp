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

    int n; cin >> n;

    vi a (n + 1); for (int i = 1; i <= n; ++i) cin >> a[i];

    stack<int> s; for (int i = 1; i <= n; ++i) {
        while (!s.empty() && s.top() >= a[i]) s.pop();

        if (s.empty()) {
            cout << -1 << " ";
        } else {
            cout << s.top() << " ";
        }

        s.push(a[i]);
    }

    return 0;
}