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

int logtwo(const int& n) {
    int val = 0;

    while ((1<<(val + 1)) <= n) val++;

    return val;
}

int main() {
    io

    int q {}; cin >> q;

    for (int i = 0; i < q; i++) {
        int n; cin >> n;

        cout << logtwo(n) << "\n";
    }

    return 0;
}