#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;

bool p(const string& a) {
    for (ll i {0}; i < a.length() / 2; ++i) {
        if (a[i] != a[a.length() - i - 1]) {
            return false;
        }
    }

    return true;
}

bool palindrome(const vector<char>& s, const ll& k) {
    for (ll i {0}; i <= s.size() - k; ++i) {
        string a {};

        for (ll j {i}; j < i + k; ++j) {
            a += s[j];
        }

        if (p(a)) {
            return false;
        }
    }

    return true;
}

int main() {
    ll n {}, k {}; cin >> n >> k;

    vector<char> s (n); for (ll i {0}; i < n; ++i) {
        cin >> s[i];
    } sort(s.begin(), s.end());

    if (n == 1) {
        if (k == 1) {
            cout << 0;
        } else {
            cout << 1;
        }

        return 0;
    }

    ll valid {0};

    do {
        valid += palindrome(s, k);

    } while (next_permutation(s.begin(), s.end()));

    cout << valid;
}