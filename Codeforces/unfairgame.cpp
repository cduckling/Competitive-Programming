#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
using namespace std;

#define tc int t; cin >> t; while (t--) solve();
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(a) (a).begin(), (a).end()
#define pb(i) push_back(i)
#define eb(i) emplace_back(i)
#define inf (ll) 1e18
#define fir first
#define sec second

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
typedef vector<double> vd;
typedef vector<vector<double>> vvd;
typedef vector<vector<vector<double>>> vvvd;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef vector<vector<vector<bool>>> vvvb;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vpii;
typedef vector<vector<pair<int, int>>> vvpii;
typedef vector<vector<vector<pair<int, int>>>> vvvpii;
typedef tuple<int, int, int> tiii;
typedef vector<tuple<int, int, int>> vtiii;
typedef vector<vector<tuple<int, int, int>>> vvtiii;
typedef vector<vector<vector<tuple<int, int, int>>>> vvvtiii;
typedef vector<string> vs;
typedef vector<vector<string>> vvs;
typedef set<int> si;
typedef vector<set<int>> vsi;
typedef vector<vector<set<int>>> vvsi;
typedef set<pair<int, int>> spii;
typedef vector<set<pair<int, int>>> vspii;
typedef map<int, int> mii;
typedef map<int, bool> mib;
typedef map<int, double> mid;
typedef vector<map<int, int>> vmii;
typedef vector<map<int, double>> vmid;
typedef vector<map<int, bool>> vmib;

int dp[201][201][201];

void solve() {
    int a, b, c, d; cin >> a >> b >> c >> d;

    cout << dp[a][b][c] + d / 2 << "\n";
}

int main() {
    io

    for (int a = 1; a <= 200; a++) {
        dp[a][0][0] = dp[a - 1][0][0];

        if (a % 2 == 0) dp[a][0][0]++;
    }

    for (int a = 0; a <= 200; a++) for (int b = 1; b <= 200; b++) {
        dp[a][b][0] = dp[a][b - 1][0]; if (a > 0) dp[a][b][0] = max(dp[a][b][0], dp[a - 1][b][0]);

        if (a % 2 == 0 && b % 2 == 0) dp[a][b][0]++;
    }

    for (int a = 0; a <= 200; a++) for (int b = 0; b <= 200; b++) for (int c = 1; c <= 200; c++) {
        dp[a][b][c] = dp[a][b][c - 1]; if (a > 0) dp[a][b][c] = max(dp[a][b][c], dp[a - 1][b][c]); if (b > 0) dp[a][b][c] = max(dp[a][b][c], dp[a][b - 1][c]);

        if ((a % 2 != 0) == (b % 2 != 0) && (b % 2 != 0) == (c % 2 != 0)) dp[a][b][c]++;

    }

    tc

    return 0;
}