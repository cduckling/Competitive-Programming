#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define tc ll t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

void divisors(vector<ll>& d, ll n) {
    for (ll i {1}; i * i <= n; ++i) {
        if (n % i == 0) {
            d.push_back(i); d.push_back(n / i);
        }
    }
}

ll gcd(ll a, ll b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

ll lcm(ll a, ll b) {
    return (a * b) / gcd(a, b);
}

void solve() {
    ll n {}; cin >> n;

    vector<ll> a (n); for (ll i {0}; i < n; ++i) cin >> a[i]; sort(a.begin(), a.end());

    ll l_ = a[0]; for (ll i : a) {
        l_ = lcm(l_, i);

        if (l_ > a[n - 1]) {
            cout << n << "\n";
            return;
        }
    }

    ll s = 0;

    if (l_ > a[n - 1]) {
        cout << n << "\n"; return;
    } else {
        vector<ll> d {}; divisors(d, a[n - 1]);

        for (ll div : d) {
            vector<ll> seq {};

            bool c = false;

            for (int i {0}; i < n; ++i) {
                if (div == a[i]) { c = true; break; }
                if (div % a[i] == 0) seq.push_back(a[i]);
            }

            if (c || seq.empty()) continue;

            ll l = seq[0]; for (ll i : seq) l = lcm(l, i);

            ll sub = seq.size();
            if (div == l) s = max(s, sub);
        }
    }
    
    cout << s << "\n";
}

int main() {
    io
    tc

    return 0;
}