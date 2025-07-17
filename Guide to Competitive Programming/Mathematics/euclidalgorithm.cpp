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

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int extended(const int a, const int b, int& x, int& y) {
    if (b == 0) {
        x = 1; y = 0;
        return a;
    }
    int x_1 {}, y_1 {};
    int d = extended(b, a % b, x_1, y_1);
    x = y_1, y = x_1 - y_1 * (a / b);
    return d;
}

int main() {
    io

    int a {}, b {}; cin >> a >> b;
    cout << gcd(a, b) << "\n";

    int x {}, y {};
    extended(a, b, x, y);
    cout << x << " " << y << "\n";

    cout << ((x * 7) % b + b) % b;
}