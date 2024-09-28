#include <iostream>
#include <cstdio>
using namespace std;

char state(string s, long long n, long long a) {
    if (n <= s.length()) {
        return s[n - 1];
    } else {
        a /= 2; --n;
        if (n != a) {n -= a;}

        a = s.length();
        while (a < n) {a *= 2;}
        return state(s, n, a);
    }
}

int main() {
    freopen("cowcode.in", "r", stdin); freopen("cowcode.out", "w", stdout);

    string s {}; cin >> s;
    long long n {}; cin >> n;

    if (n <= s.length()) {
        cout << s[n - 1];
    } else {
        long long a {static_cast<long long>(s.length())};
        while (a < n) {a *= 2;}

        cout << state(s, n, a);
    }
}