#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
#include <string>
#include <iomanip>
using namespace std;

#define tc int t; cin >> t; while (t--) solve();
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(a) (a).begin(), (a).end()
#define pb(i) push_back(i)
#define eb(i) emplace_back(i)
#define ceil(a, b) ((a + b - 1) / b)
#define inf 1e18
#define fail cout << -1 << "\n"; return;

typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<set<int>> vsi;
typedef vector<pair<int, int>> vpii;
typedef vector<tuple<int, int, int>> vtiii;
typedef vector<bool> vb;
typedef multiset<int> msi;
typedef set<int> si;
typedef set<pair<int, int>> spii;
typedef set<tuple<int, int, int>> stiii;
typedef map<int, int> mii;
typedef map<int, vector<int>> mivi;
typedef map<int, pair<int, int>> mipii;
typedef map<int, set<int>> misi;
typedef map<int, bool> mib;

vector<string> split(const char c, const string s) {
    vector<string> p;

    string cur;

    for (const char i : s) {
        if (i != c) {
            cur += i;
        } else {
            p.pb(cur); cur = "";
        }
    }

    p.pb(cur);

    return p;
}

void solve() {
    int t, e; cin >> t >> e; cin.ignore();

    map<string, int> id;

    for (int i = 0; i < t; i++) {
        string s; getline(cin, s);

        const string name = split(':', s)[0], code = split(':', s)[1];

        id[name] = stoi(code);
    }

    map<int, double> hrs;

    for (int i = 0; i < e; i++) {
        string s; getline(cin, s);

        const string name = split(':', s)[0], time = split(':', s)[1];

        hrs[id[name]] += stod(time);
    }

    double tot = 0; for (const auto i : hrs) tot += i.second;

    if (tot > 24) {
        cout << "Error" << "\n"; return;
    }

    for (const auto i : hrs) {
        cout << i.first << ":" << i.second << "\n";
    }
}

int main() {
    io

    cout << std::setprecision(1) << std::fixed;

    tc

    return 0;
}