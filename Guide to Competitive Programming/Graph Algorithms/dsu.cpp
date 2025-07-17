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

struct DSU {
    vi pars, sizes;

    DSU(const int n) : pars(n), sizes(n, 1) {
      for (int i = 0; i < n; i++) pars[i] = i;
    }

    int root(const int ver) {
        return pars[ver] == ver ? ver : (pars[ver] = root(pars[ver]));
    }

    void unite(const int a, const int b) {
        if (root(a) == root(b)) return;

        int A = root(a), B = root(b);

        if (sizes[A] < sizes[B]) swap(A, B);

        sizes[A] += sizes[B]; pars[B] = A;
    }

    bool connected(const int u, const int v) {
        return root(u) == root(v);
    }
};

int main() {
    io

    return 0;
}
