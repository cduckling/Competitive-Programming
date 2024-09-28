#include <iostream>
#include <map>
#include <algorithm>
#include <cstdio>
using namespace std;

int main() {
    freopen("auto.in", "r", stdin); freopen("auto.out", "w", stdout);

    int w {}, n {}; cin >> w >> n;

    string words[w]; map<string, int> a {};
    for (int i {0}; i < w; ++i) {cin >> words[i]; a[words[i]] = {i};}
    sort(words, words + w);

    for (int i {0}; i < n; ++i) {
        int k {}; string s {}; cin >> k >> s;

        pair<int, int> interval {0, w - 1};
        while (interval.first != interval.second) {
            int m {(interval.first + interval.second) / 2};
            if (words[m] >= s) {interval.second = {m};} else {interval.first = {m + 1};}
        }

        if ((interval.first + k - 1) >= w) {cout << -1;}
        else if (words[interval.first + k - 1].substr(0, s.length()) != s) {cout << -1;}
        else {cout << a[words[interval.first + k - 1]] + 1;}
        cout << "\n";
    }
}