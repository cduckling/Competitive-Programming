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

struct SEGTREE {
    int N; vi Q;

    SEGTREE(int n) {
        N = n; Q.assign(2 * n, 0);
    }

    SEGTREE(const vi& a) : SEGTREE(a.size()) {
        for (int i = 0; i < a.size(); i++) change(i, a[i]);
    }

    int query(int a, int b) {
        a += N, b += N;

        int val = 0;

        while (a <= b) {
            if (a % 2 == 1) val += Q[a++];
            if (b % 2 == 0) val += Q[b--];

            a /= 2; b /= 2;
        }

        return val;
    }

    void change(int pos, const int c) {
        pos += N; Q[pos] += c;

        for (pos /= 2; pos >= 1; pos /= 2) Q[pos] = Q[2 * pos] + Q[2 * pos + 1];
    }
};

int inv(const int n, const vi& a) {
    SEGTREE freq (n + 1);

    int inv = 0;

    for (const int i : a) {
        inv += freq.query(i + 1, n);
        freq.change(i, 1);
    }

    return inv;
}

void solve() {
    int n; cin >> n;

    vi a (n + 1); for (int i = 1; i <= n; i++) cin >> a[i];

    vi odd; for (int i = 1; i <= n; i += 2) odd.pb(a[i]);
    vi even; for (int i = 2; i <= n; i += 2) even.pb(a[i]);

    const int o = inv(n, odd), e = inv(n, even);

    sort(all(odd)); sort(all(even));

    vi res (n + 1);

    for (int i = 1, j = 0; i <= n; i += 2, j++) res[i] = odd[j];
    for (int i = 2, j = 0; i <= n; i += 2, j++) res[i] = even[j];

    if ((o % 2 != 0 && e % 2 == 0) || (o % 2 == 0 && e % 2 != 0)) swap(res[n], res[n - 2]);

    for (int i = 1; i <= n; i++) cout << res[i] << " "; cout << "\n";
}

int main() {
    io
    tc

    return 0;
}