#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define tc int t {}; cin >> t; while (t--) solve();
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;
typedef pair<int, int> pii;

void solve() {
    int n {}, m {}, l {}; cin >> n >> m >> l;

    vector<pii> h (n + 1); for (int i {1}; i <= n; ++i) cin >> h[i].first >> h[i].second;

    vector<pii> pu (m + 1); for (int i {1}; i <= m; ++i) cin >> pu[i].first >> pu[i].second;

    priority_queue<int> pq {}; int pt {1}, pow {1}, op {0};

    for (int i {1}; i <= n; ++i) {
        while (pt <= m && pu[pt].first < h[i].first) {
            pq.push(pu[pt].second);
            ++pt;
        }

        while (pow < (h[i].second - h[i].first + 2)) {
            if (pq.empty()) {
                cout << -1 << "\n"; return;
            }

            pow += pq.top(); pq.pop(); ++op;
        }
    }

    cout << op << "\n";
}

int main() {
    io
    tc

    return 0;
}