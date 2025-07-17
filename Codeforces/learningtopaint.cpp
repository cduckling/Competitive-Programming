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

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")

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

void solve() {
    int n, k; cin >> n >> k;

    vvi a (n + 1, vi (n + 1)); for (int i = 1; i <= n; i++) for (int j = i; j <= n; j++) cin >> a[i][j];

    vmii dp (n + 1); dp[n][0] = 1, dp[n][a[n][n]] = 1;

    for (int i = n - 1; i >= 1; i--) {
        for (int j = i; j <= n; j++) {
             
        }
    }
}

/*
 * dp is obvious; if we maintain dp[i] and go from right to left, then if dp[i] = optimal config given i is painted,
 * we can solve in quadratic time; can this be optimized by some sort of structure; we can use math in a way; if the contiguous block from j continues to k, then this state (k) is associated with dp[k + 1]
 * obviously this can be bashed in quadratic time, but maybe d&c? yea divide and conquer seems like it would work well and logarithmic time if the various values are set properly
 * so values i...N; create a segtree for each i in 1...N; then when a dp is set add to the app in o(n), then search in logN; this is kinda worse but still functional and may prove useful as a structure
 *
 * obviously now we have a prefix, suffix, etc. minima/maxima if needed
 *
 * if we have the most beautiful config, what is the second most beautiful config, and so on? we could just state that some config is banned?
 * also consider the # of ways to make dp[i], and multiply things with combo -- does this have use here? probably not
 *
 * segtree would probably not be useful, more information can be gained easily with normal bash
 *
 * so we have for dp[i], find max value of a[i][j] + dp[j + 1]. pherhaps store all?
 *
 * we are probably expected to solve in something like O(n^2 + k)
 *
 * pherhaps consider the bounds from -1e6 to 1e6?
 *
 * guess extremals, restatements, and minimals; maybe best and worst (1st and kth optimal values, arranged by largest)
 *
 * how does the answer, ith optimal value, decrease and change; it is obviously non-increasing.
 *
 * can each step down be found with smth like binary search
 *
 * we want to minimize the step down, wanting it to be smth like 1, 2, ... as small as possible
 *
 * find what the smallest decrease from dp[1] can be? granted # of ways dp[1] can do optimal (overall) value
 *
 * restate dp[i], this is stupid, i is not necessarily painted
 *
 * so im starting to think is that we need to approach this from a more bashy, computational view point; not really the amounts of decrease or what the kth thing is
 * do we need to have all the possibilites?
 *
 * well this is starting to look quite real;
 *
 * so i guess we could ask; is dp[i] = {val, # of config that produce val, ...} something we can compute?
 *
 * well how what would the time we would need for some dp[i] be?
 *
 * well, there might be the need for some kind of math to find the size of map dp[j] that we kinda need to merge...
 *
 * so of course, we're going to fix some kinda block right for the transition; this is kinda obvious
 *
 * im not sure if one exists, but rn im looking for some kidn of unstated bound...
 *
 * idk what it would be, ig less than const * 1e6 diff vals that would be there, therefore merging is bounded by thsi
 *
 * i think we might be able to do smth quadratic; tbh this triangular nums are actually so common
 *
 * n is small right; tbh i think we are downplaying this
 *
 * how many diff numbers can be made with a_i ... a_n? ofc there are 2^n of these diff configs
 *
 * rly... n^2 no? i think thats the strictest bound i can give, and its kidna hinted to be true by the 1e6 ... maybe?
 */

int main() {
    io
    tc

    return 0;
}