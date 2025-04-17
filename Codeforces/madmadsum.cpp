#include <iostream>
#include <vector>
#include <set>
using namespace std;

#define tc ll t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

void process(vector<ll>& a) {
    set<ll> p {a[0]}; a[0] = 0;

    for (ll i {1}; i < a.size(); ++i) {
        ll b = a[i]; a[i] = a[i - 1];

        if (p.count(b)) {
            a[i] = max(a[i], b);
        }

        p.insert(b);
    }
}

void solve() {
    ll n {}; cin >> n;

    ll s {};

    vector<ll> a (n); for (ll i {0}; i < n; ++i) {
        cin >> a[i]; s += a[i];
    }

    process(a); for (const ll& i : a) {
        s += i;
    }
    process(a); for (const ll& i : a) {
        s += i;
    }

    for (ll i {0}; i < n; ++i) {
        s += a[i] * (a.size() - i - 1);
    }

    cout << s << "\n";
}

int main() {
    io
    tc

    return 0;
}