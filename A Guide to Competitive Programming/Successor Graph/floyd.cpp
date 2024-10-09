#include <iostream>
#include <vector>
using namespace std;

#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

int floyd(const vector<int>& adj) {
    int t = adj[0], h = adj[adj[0]];

    while (t != h) {
        t = adj[t]; h = adj[adj[h]];
    }

    return t;
}

int main() {
    io

    int n {}; cin >> n;

    vector<int> adj (n); for (int i {0}; i < n; ++i) cin >> adj[i];

    cout << floyd(adj);

    return 0;
}