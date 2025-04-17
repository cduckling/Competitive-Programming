#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <numeric>
using namespace std;

#define tc int t {}; cin >> t; while (t--) solve();
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pb(i) push_back(i);
#define inf 1e18;

typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vpii;
typedef vector<tuple<int, int, int>> vtiii;
typedef vector<bool> vb;
typedef multiset<int> msi;
typedef set<int> si;
typedef map<int, int> mi;
typedef map<int, vector<int>> mvi;
typedef map<int, pair<int, int>> mpii;
typedef map<int, bool> mb;

bool palindrome(const string& s) {
    int a = 0, b = s.size() - 1;
    while (a <= b) {
        if (s[a] != s[b]) return false;

        ++a; --b;
    }

    return true;
}

void solve() {
    string s {}; cin >> s;

    if (!palindrome(s)) {
        cout << "YES\n1\n" + s + "\n"; return;
    }

    int p = 0; while (s[p] == s[0]) ++p; ++p;

    if (p == s.size() + 1) {
        cout << "NO\n";
    } else {
        if (!palindrome(s.substr(p))) {
            cout << "YES\n2\n" << s.substr(0, p) << " " << s.substr(p) << "\n"; return;
        }

        if (p == 2 || p == (s.size() + 1) / 2) {
            cout << "NO\n";
        } else {
            cout << "YES\n2\n" << s.substr(0, p + 1) << " " << s.substr(p + 1) << "\n"; return;
        }
    }
}

// Ab(Ab...bA)

int main() {
    io
    tc

    return 0;
}