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

int e[100001];

void eratosthenes(int n) {
   e[0] = 1; e[1] = 1;

    for (int i {2}; i <= n; ++i) {
        if (e[i]) {
            continue;
        } else {
            for (int j {2 * i}; j <= n; j += i) e[j] = 1;
        }
    }
}

int p[100001];

void prime(int n) {
    p[0] = 1; p[1] = 1;

    for (int i {2}; i <= n; ++i) {
        if (p[i]) {
            continue;
        } else {
            for (int j {i}; j <= n; j += i) p[j] = i;
        }
    }
}

int main() {
    io

    int n {}; cin >> n;

    eratosthenes(n);
    for (int i {0}; i <= n; ++i) cout << e[i] << " ";

    cout << "\n\n";

    prime(n); vi f {}; int d = n;
    while (true) {
        if (d == p[d]) {
            f.pb(d);
            break;
        } else {
            f.pb(p[d]);
            d /= p[d];
        }
    }

    for (int i : f) cout << i << " ";
}