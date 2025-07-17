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
#define aint(a) (a).begin(), (a).end()
#define pb(i) push_back(i)
#define eb(i) emplace_back(i)
#define inf (int) 1e18
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

bool s[10000001];
int g[10000001], d[10000001];

void solve() {
    int n; cin >> n;

    vi a (n); for (int i = 0; i < n; i++) cin >> a[i];

    vi p (n); for (int i = 0; i < n; i++) p[i] = d[a[i]];

    int sum = 0; for (int i = 0; i < n; i++) {
        if (a[i] == 1) {
            sum ^= 1;
        } else if (a[i] % 2 != 0) {
            sum ^= g[p[i]] + 1;
        }
    }

    cout << (sum == 0 ? "Bob" : "Alice") << "\n";
}

int main() {
    io

    int val = 0;

    for (int i = 2; i <= 10000000; i++) {
        if (s[i] == true) continue;

        g[i] = val++;

        for (int j = i; j <= 10000000; j += i) {
            s[j] = true;

            if (d[j] == 0) d[j] = i;
        }
    }

    tc

    return 0;
}