#include <iostream>
#include <vector>
#include <set>
using namespace std;

#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

ll alphabet[26];

void wipe(ll a) {
    for (ll i {a}; i < 26; ++i) alphabet[i] = 0;
}

int main() {
    io

    ll n {}, q {}; cin >> n >> q;

    vector<ll> fence (n); for (ll i {0}; i < n; ++i) {
        char c {}; cin >> c; fence[i] = c - 'A';
    }

    vector<ll> strokes (n); strokes[0] = 1; alphabet[fence[0]] = 1; ll s {1};

    for (ll i {1}; i < n; ++i) {
        if (fence[i] >= fence[i - 1]) {
            if (alphabet[fence[i]] == 0) {
                ++s; alphabet[fence[i]] = s; strokes[i] = s;
            } else {
                strokes[i] = alphabet[fence[i]];
            }
        } else {
            wipe(fence[i] + 1);

            if (alphabet[fence[i]] == 0) {
                ++s; alphabet[fence[i]] = s; strokes[i] = s;
            } else {
                strokes[i] = alphabet[fence[i]];
            }
        }
    }
    
    set<ll> p_ {}, s_ {};
    vector<ll> pref (n), suf (n);
    
    for (ll i {0}; i < n; ++i) {
        p_.insert(strokes[i]); pref[i] = p_.size();
    } for (ll i {n - 1}; i >= 0; --i) {
        s_.insert(strokes[i]); suf[i] = s_.size();
    }

    pref.insert(pref.begin(), 0); suf.insert(suf.begin(), 0);

    for (ll i {0}; i < q; ++i) {
        ll a {}, b {}; cin >> a >> b;

        cout << pref[a - 1] + suf[b + 1] << "\n";
    }

    return 0;
}