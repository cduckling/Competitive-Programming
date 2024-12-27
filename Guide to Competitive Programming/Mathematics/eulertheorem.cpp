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

int phi(int n) {
    int a {n};

    for (int p {2}; p * p <= n; ++p) {
        if (n % p == 0) {
            while (n % p == 0) n /= p;

            a /= p;
            a *= (p - 1);
        }
    }

    if (n > 1) {
        a /= n;
        a *= (n - 1);
    }

    return a;
}

int main() {
    io

    int n {}; cin >> n;

    cout << phi(n);
}