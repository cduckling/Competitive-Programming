#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define tc ll t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;
typedef pair<int, int> pii;

void solve() {
    ll a {}, b {}; cin >> a >> b;

    vector<int> v (a + b + 1); v[a] = 1;

    queue<ll> q {}; q.push(a);

    while (!q.empty()) {
        ll p = q.front(); q.pop();

        if (p == b) {
            cout << v[b] - 1 << "\n";
            return;
        }

        if (2 * p <= a + b + 1 && !v[2 * p]) {
            q.push(2 * p); v[2 * p] = v[p] + 1;
        }

        if (p + 1 <= a + b + 1 && !v[p + 1]) {
            q.push(p + 1); v[p + 1] = v[p] + 1;
        }

        if (p % 2 == 0) {
            if (p / 2 <= a + b + 1 && !v[p / 2]) {
                q.push(p / 2);
                v[p / 2] = v[p] + 1;
            }
        }
    }

    cout << v[b] - 1 << "\n";
}

int main() {
    io
    tc

    return 0;
}