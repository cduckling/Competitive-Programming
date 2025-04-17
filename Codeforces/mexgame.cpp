#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

#define tc int t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;
typedef pair<int, int> pii;

int mex(const map<int, int>& m) {
    vector<int> a {}; a.reserve(m.size()); for (auto i : m) a.push_back(i.first);

    vector<bool> f (a.size() + 1); for (int i : a) if (i <= a.size()) f[i] = true;
    int mex = 0; while (f[mex]) ++mex;
    return mex;
}

int grundy(const vector<int>& a) {
    vector<bool> f (a.size() + 1); for (int i : a) if (i <= a.size()) f[i] = true;
    int mex = 0; while (f[mex]) ++mex;
    return mex;
}


void solve() {
    int n {}; cin >> n;

    map<int, int> in {}; for (int i {0}; i < n; ++i) {
        int j {}; cin >> j; ++in[j];
    } int m = mex(in);
    map<int, int> inp {}; for (auto & i : in) if (i.first < m) inp.insert(i); if (inp.empty()) {
        cout << 0 << "\n"; return;
    }

    vector<int> c {};

    set<pii> a {}; for (auto i : inp) a.insert({i.second, i.first});

    while (!a.empty()) {
        c.push_back((*a.begin()).second); a.erase(a.begin());

        if (!a.empty()) {const pii e = *a.begin(); a.erase(a.begin()); if (e.first > 1) a.insert({e.first - 1, e.second});}
    }

    cout << grundy(c) << "\n";
}

int main() {
    io
    tc

    return 0;
}