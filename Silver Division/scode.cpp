#include <iostream>
#include <cstdio>
using namespace std;

int operation(pair<string, string> a) {
    if (a.first.length() > a.second.length()) {
        return ((a.first.substr(1, a.first.length() - 1) == a.second) + (a.first.substr(0, a.first.length() - 1) == a.second));
    } else {
        return ((a.second.substr(1, a.second.length() - 1) == a.first) + (a.second.substr(0, a.second.length() - 1) == a.first));
    }
}

int backtrack(string s) {
    int p {0};

    if (s.length() <= 2 || s.length() % 2 == 0) {
        return 0;
    } else {
        char c {s[s.length() / 2]};
        pair<string, string> a {s.substr(0, s.length() / 2), s.substr((s.length() + 1) / 2, s.length() / 2)};
        pair<string, string> b {a.first, a.second};
        a.first += c; b.second = c + b.second;

        int a_ {operation(a)}, b_ {operation(b)};
        p += (a_ + b_) + (a_ * backtrack(a.first)) + (b_ * backtrack(b.second));
    }

    return p;
}

int main() {
    freopen("scode.in", "r", stdin); freopen("scode.out", "w", stdout);

    string s {}; cin >> s;
    cout << backtrack(s);
}