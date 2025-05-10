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

bool check(const int n, int q, const vi& a, const vi& pref) {
    if (q <= pref[n - 1]) return true;

    for (int i = n; i >= 2; i--) {
        if (a[i] >= q) {
            q--;
        } else {
            q++;
        }

        if (q <= pref[i - 2]) return true;
    }

    return false;
}

void solve() {
    int n; cin >> n;

    vi a (n + 1); for (int i = 1; i <= n; i++) cin >> a[i];

    vi x (n + 1); for (int i = 1; i <= n; i++) {
        x[i] = x[i - 1];

        if (a[i] > x[i - 1]) {
            x[i]++;
        } else if (a[i] < x[i - 1]) {
            x[i]--;
        }
    }

    vi pref (n + 1); for (int i = 1; i <= n; i++) pref[i] = max(pref[i - 1], x[i]);

    pii r = {0, n};

    while (r.fir != r.sec) {
        const int mid = (r.fir + r.sec + 1) / 2;

        if (check(n, mid, a, pref)) {
            r.fir = mid;
        } else {
            r.sec = mid - 1;
        }
    }

    cout << max(r.first, pref[n - 1]) << "\n";
}

int main() {
    io
    tc

    return 0;
}