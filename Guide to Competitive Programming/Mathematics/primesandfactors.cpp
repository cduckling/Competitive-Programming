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

bool prime(int n) {
    if (n < 2) return false;

    for (int i {2}; i * i <= n; ++i) if (n % i == 0) return false;

    return true;
}

vector<int> factors(int n) {
    vector<int> f {};

    for (int i {2}; i * i <= n; ++i) {
        while (n % i == 0) {
            f.pb(i);
            n /= i;
        }
    }

    if (n > 1) f.pb(n);

    return f;
}

int main() {
    io

    int n {}; cin >> n;

    vector<int> f (factors(n));

    for (int i : f) cout << i << " ";
}