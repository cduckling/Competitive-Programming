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
#define pb(i) push_back(i);
#define ceil(a, b) ((a + b - 1) / b)
#define inf 1e18

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
typedef map<int, set<int>> misi;
typedef map<int, bool> mib;

void solve() {
    ll n;
    cin >> n;
    vector<pair<ll, ll>> d(n);
    for(int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        d[i] = {x, i};
    }
    sort(d.rbegin(), d.rend());
    vector<ll> p(2 * n, -1);
    for(int i = 1; i < n; i++)
    {
        p[d[i].second * 2] = d[i - 1].second * 2;
    }
    for(int i = 0; i < n; i++)
    {
        ll l = d[i].first;
        if(l - 1 + i < n)
        {
            p[d[i].second * 2 + 1] = d[i + l - 1].second * 2;
        }
        else
        {
            ll diff = d[i - 1].first - l;
            ll v = d[i - 1].second * 2 + 1;
            for(int j = 0; j < diff; j++)
            {
                v = p[v];
            }
            p[d[i].second * 2 + 1] = v;
        }
    }
    for(int i = 0; i < 2 * n; i++)
    {
        if(p[i] != -1)
        {
            cout << i + 1 << ' ' << p[i] + 1 << endl;
        }



}

int main() {
    io

    solve();

    return 0;
}