#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
using namespace std;

#define tc int t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;
typedef unsigned long long ull;

ll modpow(ll base, ll exp) {
    ll res = 1;
    while (exp > 0) {
        if (exp % 2 == 1) res = res * base;

        base = base * base;
        exp /= 2;
    }
    return res;
}

void solve() {
    ll n {}; cin >> n;


    if (__builtin_popcountll(n) == 1) {
        cout << 1 << "\n" << n << "\n"; return;
    } else {
        bitset<63> r {static_cast<ull>(n)}; vector<ll> a {n}; ll p {};

        cout << __builtin_popcountll(n) + 1 << "\n";

        for (int i {0}; i < 63; ++i) {
            if (!r[i]) continue;

            n += p;
            p = modpow(2, i);
            n -= p;
            a.push_back(n);
        }

        reverse(a.begin(), a.end()); for (ll i : a) {
            cout << i << " ";
        }

        /*for (ull i {a.size() - 1}; i >= 0; --i) {
            cout << a[i] << " ";
        }*/

        cout << "\n";
    }
}



int main() {
    io
    tc

    return 0;
}