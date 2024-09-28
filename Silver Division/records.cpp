#include <iostream>
#include <set>
#include <cstdio>
using namespace std;

int main() {
    freopen("records.in", "r", stdin); freopen("records.out", "w", stdout);

    int n {}; cin >> n;

    multiset<multiset<string>> records {};

    for (int i {0}; i < n; ++i) {
        string a {}, b {}, c {}; cin >> a >> b >> c;
        multiset<string> record {};
        record.insert(a); record.insert(b); record.insert(c);
        records.insert(record);
    }

    int g {0};

    for (auto group : records) {
        int t {static_cast<int>(records.count(group))};
        g = max(g, t);
    }

    cout << g;
}