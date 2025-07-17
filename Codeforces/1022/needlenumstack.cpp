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

int query(const int n, const int pos) {
    if (pos > n) return -1;
    cout << "?" << " " << pos << endl;
    int val; cin >> val; return val;
}

void solve() {
    int n, k; cin >> n >> k;

    if (n == 2 * k) {
        cout << "! " << k << " " << k << endl; return;
    }

    vi b (k + 1); for (int i = 1; i <= k; i++) b[i] = query(n, i);

    vi g (k + 1);

    for (int i = 1; i <= k; i++) {
        pii r = {1, n / k}; if (n - n % k + i <= n) r.sec++;

        while (r.fir != r.sec) {
            const int mid = (r.fir + r.sec + 1) / 2;

            const int val = query(n, (mid - 1) * k + i);

            if (val != b[i]) {
                r.sec = mid - 1;
            } else {
                r.fir = mid;
            }
        }

        g[i] = r.fir + 1;
    }

    int bad = n + 1; for (int i = 1; i <= k; i++) bad = min(bad, (g[i] - 1) * k + i); bad = min(bad, n - k + 1);

    if (bad == n + 1) {
        cout << "! -1" << endl;
    } else if (query(n, bad - 1) == query(n, bad - 1 + k)) {
        cout << "! -1" << endl;
    } else {
        cout << "! " << bad - 1 << " " << n - bad + 1 << endl;
    }
}

int main() {
    io
    tc

    return 0;
}