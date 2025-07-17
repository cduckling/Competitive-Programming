#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

#define tc int t {}; cin >> t; while (t--) {solve();}

typedef long long ll;

bool c(pair<int, char> a, pair<int, char> b) {
    return a.first > b.first;
}

int same(const int& n, const int& a, const vector<pair<int, char>>& f) {
    int s {0};

    for (int i {0}; i < a; ++i) {
        s += min(n / a, f[i].first);
    }

    return s;
}

void solve() {
    int n {}; cin >> n;
    string s {}; cin >> s;

    vector<pair<int, char>> frequencies (26, {0, ' '});
    for (int i {0}; i < 26; ++i) {
        frequencies[i].second = static_cast<char>('a' + i);
    } for (int i {0}; i < n; ++i) {
        ++frequencies[s[i] - 'a'].first;
    }
    sort(frequencies.begin(), frequencies.end(), c);

    pair<int, int> t {0, 100001};
    for (int a {1}; a <= 26; ++a) {
        if (n % a == 0) {
            int d = n - same(n, a, frequencies);

            if (d < t.second) {
                t = {a, d};
            }
        } else {
            continue;
        }
    }

    map<char, int> a {}; int b {n / t.first};
    for (int i {0}; i < t.first; ++i) {
        a[frequencies[i].second] = b;
    }

    for (int i {0}; i < n; ++i) {
        if (a[s[i]] == 0) {
            s[i] = '.';
        } else {
            --a[s[i]];
        }
    }

    multiset<char> a_ {}; for (auto i : a) {
        for (int j {0}; j < i.second; ++j) {
            a_.insert(i.first);
        }
    }

    for (int i {0}; i < n; ++i) {
        if (s[i] == '.') {
            s[i] = *a_.begin();
            a_.erase(a_.begin());
        }
    }

    cout << t.second << "\n" << s << "\n";
}

int main() {
    tc
}