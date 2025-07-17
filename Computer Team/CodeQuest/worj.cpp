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
#define inf 1e18
#define fail cout << -1 << "\n"; return;

typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<set<int>> vsi;
typedef vector<pair<int, int>> vpii;
typedef vector<vector<pair<int, int>>> vvpii;
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

map<int, string> name;
vector<map<char, int>> adj (10);

vector<char> split(const string s) {
    vector<char> p;

    for (const char i : s) if (i != ' ') p.pb(i);

    return p;
}

void solve() {
    int id; cin >> id; cin.ignore();

    string s; getline(cin, s);

    vector<char> p = split(s);

    int state = 0;

    string sol;

    for (const char i : p) {
        if (adj[state][i] == 0) {
            sol += ">Invalid Command";
        } else {
            state = adj[state][i];
            sol += ">" + name[state];
        }
    }

    string ans = ""; for (int i = 1; i < sol.size(); i++) ans += sol[i];

    cout << id << " " << ans << "\n";
}

int main() {
    io

    name[1] = "New";
    name[2] = "Draft";
    name[3] = "Preliminary Review";
    name[4] = "Waiting Preliminary";
    name[5] = "Final Review";
    name[6] = "Waiting Final";
    name[7] = "Rejected";
    name[8] = "Approved";
    name[9] = "Customer Notified";

    adj[0]['C'] = 1;
    adj[1]['S'] = 2;
    adj[2]['S'] = 2;
    adj[2]['B'] = 3;
    adj[3]['S'] = 3;
    adj[3]['X'] = 7;
    adj[3]['A'] = 5;
    adj[3]['R'] = 4;
    adj[5]['S'] = 5;
    adj[5]['X'] = 7;
    adj[5]['A'] = 8;
    adj[5]['R'] = 6;
    adj[4]['I'] = 3;
    adj[6]['I'] = 5;
    adj[7]['N'] = 9;
    adj[8]['N'] = 9;

    tc

    return 0;
}