#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
#include <cctype>
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

string bad = "1234567890"

string fix(const string s) {
    string S = ""; for (const char i : s) S += tolower(i); return S;
}

int occ(const string s, const string sec) {
    int cnt = 0; for (int i = 0; i < sec.length() - s.size(); i++) if (s == sec.substr(i, s.size())) cnt++; return cnt;
}

void solve() {
    int s, w; cin >> s >> w; cin.ignore();

    vector<string> sec (s); for (int i = 0; i < s; i++) getline(cin, sec[i]), sec[i] = fix(sec[i]);

    for (int i = 0; i < w; i++) {

    }
}

int main() {
    io
    tc

    return 0;
}