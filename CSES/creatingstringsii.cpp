#include <iostream>
using namespace std;

typedef long long ll;

ll m = 1e9 + 7;

ll chars[26];
ll factorials[1000001];
ll inverses[10000001];

ll inverse(ll x) {
    return x <= 1 ? x : m - m / x * inverse(m % x) % m;
}

int main() {
    string s {}; cin >> s;

    for (const char& i : s) {
        ++chars[i - 'a'];
    }

    factorials[0] = 1; for (int i {1}; i <= 1000000; ++i) {
        factorials[i] = ((factorials[i - 1] % m) * (i % m)) % m;
    }
    inverses[0] = 1; inverses[1] = 1;
    for (int i {2}; i <= 1000000; ++i) {
        inverses[i] = ((inverses[i - 1] % m) * (inverse(i) % m)) % m;
    }

    ll d {factorials[s.length()]};

    for (int i {0}; i < 26; ++i) {
        d = ((d % m) * (inverses[chars[i]] % m)) % m;
    }

    cout << d;
}