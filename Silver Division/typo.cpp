#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    freopen("typo.in", "r", stdin); freopen("typo.out", "w", stdout);

    string parentheses {}; cin >> parentheses; int n = static_cast<int>(parentheses.length());

    pair<int, int> p[n];
    for (int i {0}; i < n; ++i) {if (parentheses[i] == '(') {p[i] = {1, 1};} else {p[i] = {-1, -1};}}
    for (int i {1}; i < n; ++i) {p[i].second += p[i - 1].second;}

    int r {0};

    if (p[n - 1].second == 2) {
        for (int i {n - 1}; i >= 0; --i) {if (p[i].second == 1) {break;} else if (p[i].first == 1) {++r;}}
    } else if (p[n - 1].second == -2) {
        for (int i {0}; i <= n - 1; ++i) {if (p[i].second == -1) {++r; break;} else if (p[i].first == -1) {++r;}}
    }

    cout << r;
}