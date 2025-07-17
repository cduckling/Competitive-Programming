#include <iostream>
#include <vector>
using namespace std;

#define pb(a) push_back(a)

typedef vector<int> vi;

bool p[751][751]; vi adj[751];

void check(const int i, const int j) {
    int val = 0;

    for (const int k : adj[i]) val += p[k][j];

    if (val % 2 != p[i][j]) adj[i].pb(j);
}

void solve() {
    int n; cin >> n;

    for (int i = 1; i <= n; i++) for (int j = i + 1; j <= n; j++) {
        char c; cin >> c; p[i][j] = c == '1';
    }

    for (int dist = 1; dist < n; dist++) {
        for (int i = 1; i <= n; i++) {
            if (i + dist > n) continue;

            check(i, i + dist);
        }
    }

    int cnt = 0; for (int i = 1; i <= n; i++) cnt += adj[i].size(); cout << cnt << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    solve();

    return 0;
}