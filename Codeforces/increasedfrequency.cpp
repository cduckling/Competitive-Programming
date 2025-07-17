#include <iostream>
#include <vector>
#include <map>
using namespace std;

#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

void solve() {
    int n {}, c {}; cin >> n >> c;

    map<int, vector<int>> pos {}; vector<int> pref (n + 1), a (n + 1); for (int i {1}; i <= n; ++i) {
        cin >> a[i]; pos[a[i]].push_back(i); if (a[i] == c) ++pref[i]; pref[i] += pref[i - 1];
    }

    int r = 0;

    for (const auto& i : pos) {
        if (i.first == c) continue;

        vector<int> dp (i.second.size()); dp[0] = 1; r = max(r, 1);

        for (int j {1}; j < i.second.size(); ++j) {
            dp[j] = max(1, 1 + dp[j - 1] - (pref[i.second[j]] - pref[i.second[j - 1]]));

            r = max(r, dp[j]);
        }
    }

    cout << pref[n] + r;
}

int main() {
    io

    solve();

    return 0;
}