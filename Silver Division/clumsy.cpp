#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    freopen("clumsy.in", "r", stdin); freopen("clumsy.out", "w", stdout);

    string s {}; cin >> s;

    int d {0}, r {0};
    for (char i : s) {
        if (i == '(') {d++;} else {d--;}
        if (d < 0) {r++; d += 2;}
    }

    cout << r + d / 2;
}