#include <iostream>
#include <set>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ld> pii;

ld H[2000]; set<pii> G[2000];

void solve() {
    int n {}; cin >> n;

    for (int i {0}; i < n; ++i) cin >> H[i];

    for (int i {0}; i < n; ++i) {
        ld s = -1e9;

        for (int j = i + 1; j < n; ++j) {
            s = max(s, (H[j] - H[i]) / (j - i));

            if (s <= (H[j] - H[i]) / (j - i)) G[i].insert({j, (H[j] - H[i]) / (j - i)});
        }
    }

    int q {}; cin >> q;

    while (q--) {
        int pos {}, c {}; cin >> pos >> c; --pos; H[pos] += c;

        int p = 0;

        for (int i {0}; i < pos; ++i) {
            ld s = (H[pos] - H[i]) / (pos - i);

            auto fir = --G[i].upper_bound({pos, 1e9});

            if (fir->second <= s) {
                while (G[i].lower_bound({pos, -1e9}) != G[i].end() && G[i].lower_bound({pos, -1e9})->second < s) G[i].erase(G[i].lower_bound({pos, -1e9}));

                G[i].insert({pos, s});
            }
        }

        G[pos].clear();

        ld s = -1e9;

        for (int i = pos + 1; i < n; ++i) {
            s = max(s, (H[i] - H[pos]) / (i - pos));

            if (s <= (H[i] - H[pos]) / (i - pos)) G[pos].insert({i, (H[i] - H[pos]) / (i - pos)});
        }

        for (int i = 0; i < n; ++i) p += G[i].size();

        cout << p << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    solve();

    return 0;
}