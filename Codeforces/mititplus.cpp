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

#define tc int t; cin >> t; while (t--) solve();
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(a) (a).begin(), (a).end()
#define pb(i) push_back(i);
#define inf 1e18;

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
typedef map<int, int> mi;
typedef map<int, vector<int>> mivi;
typedef map<int, pair<int, int>> mipii;
typedef map<int, bool> mib;

void solve() {
    int n; cin >> n; string s; cin >> s;

    int pos = 1; if (s[0] != 'M') {
        cout << "NO\n"; return;
    }

    for (int i = 1; i < n; i++) {
        if (pos == 0) {
            if (s[i] != 'M') {
                cout << "NO\n"; return;
            }
        } else {
            switch (s[i]) {
                case 'M':
                    if (s[i - 1] != 'T') {
                        cout << "NO\n"; return;
                    }

                    pos = 0;
                    break;
                case 'I':
                    if (s[i - 1] == 'I') {
                        cout << "NO\n"; return;
                    }

                    break;
                case 'T':
                    if (s[i - 1] != 'I') {
                        cout << "NO\n"; return;
                    }

                    break;
            }
        }

        pos++;
    }

    if (s[s.size() - 1] != 'T') {
        cout << "NO\n"; return;
    }

    cout << "YES\n";
}

int main() {
    io
    tc

    return 0;
}