#include <iostream>
#include <vector>
#include <array>
using namespace std;

#define tc int t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;
typedef array<int, 4> quad;

void solve() {
    int n {}; cin >> n;

    vector<int> a (n + 1); for (int i {1}; i <= n; ++i) cin >> a[i];

    if (n < 4) {
        cout << a[1] << "\n";
        return;
    }

    vector<quad> dp (n + 1);

    dp[4][0] = a[1] + a[3] + a[4]; dp[4][1] = a[1] + a[4]; dp[4][2] = a[1] + a[2]; dp[4][3] = a[1] + a[3];
    for (int i {5}; i <= n; ++i) {dp[i][0] = dp[i - 1][1] + a[i]; dp[i][1] = min(dp[i - 1][2], dp[i - 1][3]) + a[i]; dp[i][2] = dp[i - 1][3]; dp[i][3] = min(dp[i - 1][0], dp[i - 1][1]);}
    cout << min(min(dp[n][0], dp[n][1]), min(dp[n][2], dp[n][3])) << "\n";
}

int main() {
    io
    tc

    return 0;
}