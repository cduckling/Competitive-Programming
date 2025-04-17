#include <iostream>
#include <vector>
#include <set>
#include <map>
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
#define ceil(a, b) ((a + b - 1) / b)
#define inf (ll) 1e18
#define fail cout << -1 << "\n"; return;

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
typedef tuple<int, int, int> tii;
typedef vector<tuple<int, int, int>> vtii;
typedef vector<vector<tuple<int, int, int>>> vvtii;
typedef vector<vector<vector<tuple<int, int, int>>>> vvvtii;
typedef set<int> si;
typedef vector<set<int>> vsi;
typedef vector<vector<set<int>>> vvsi;
typedef map<int, int> mii;
typedef map<int, bool> mib;
typedef map<int, double> mid;
typedef vector<map<int, int>> vmii;
typedef vector<map<int, double>> vmid;
typedef vector<map<int, bool>> vmib;

void solve() {
    int n; cin >> n;

    vvd p (n, vd (n)); for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> p[i][j];

    vvd dp (1<<n, vd (n));


}

/*
 * If jedi is held in subset, this is trivial.
 *
 * If jedi is not in subset, whenever it is introduced, I want to get the probability of jedi winning.
 *
 * For this case, I want to have the probabilities of each sith in the previous subset that optimize the probability of jedi winning.
 *
 * Do we want the specific probabilities for each one, because in doing so for some probability is suboptimal for spec things.
 *
 * Take,
 *
 * consider DP[s][i] = probability of jedi winning if for subset that is currently the winner
 *
 * the thing is for the same subset there are multiple probs of a jedi winning
 *
 * how do we maximize for jedi?
 *
 *
 */

int main() {
    io
    tc

    return 0;
}