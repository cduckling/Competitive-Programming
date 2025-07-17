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

#include <complex>

typedef complex<double> cd;
const double pi = acos(-1);

vector<cd> fft(const vector<cd>& a, const int d = 1) {
    int n = a.size();

    vector<cd> r (n);

    for (int i = 0; i < n; i++) {
        int b = 0;

        for (int j = 1; j < n; j *= 2) {
            b *= 2; if (i&j) b++;
        }

        r[b] = a[i];
    }

    for (int i = 2; i <= n; i *= 2) {
        cd wm = exp(cd{0,d * 2 * pi / i});

        for (int j = 0; j < n; j += i) {
            cd w = 1;

            for (int k = 0; k < i / 2; k++) {
                cd u = r[j + k], t = w * r[j + k + i / 2];

                r[j + k] = u + t, r[j + k + i / 2] = u - t;

                w = w * wm;
            }
        }
    }

    if (d == -1) for (int i = 0; i < n; i++) r[i] /= n;

    return r;
}

int main() {
    io

    int n; cin >> n;

    vector<cd> f (n); for (int i = 0; i < n; i++) cin >> f[i]; f = fft(f);
    vector<cd> g (n); for (int i = 0; i < n; i++) cin >> g[i]; g = fft(g);

    vector<cd> prod (n); for (int i = 0; i < 2 * n - 1; i++) prod[i] = f[i] * g[i];

    prod = fft(prod,-1);

    for (int i = 0; i < n; i++) cout << static_cast<int>(prod[i].real() + 0.5) << " "; cout << "\n";

    return 0;
}