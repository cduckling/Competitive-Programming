#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int greatest(int a, int b, int c) {return max(max(a, b), c);}

int main() {
    freopen("hps.in", "r", stdin); freopen("hps.out", "w", stdout);

    int n {}; cin >> n;

    vector<int> h (n + 1, 0);
    vector<int> p (n + 1, 0);
    vector<int> s (n + 1, 0);

    for (int i {1}; i <= n; ++i) {char m {}; cin >> m; ++(m == 'H' ? h : (m == 'P' ? p : s))[i];}
    for (int i {1}; i <= n; ++i) {h[i] += h[i - 1]; p[i] += p[i - 1]; s[i] += s[i - 1];}

    int w {0};
    for (int i {1}; i <= n; ++i) {w = max(w, greatest(h[i] - h[0], p[i] - p[0], s[i] - s[0]) + greatest(h[n] - h[i], p[n] - p[i], s[n] - s[i]));}
    w = max(w, greatest(h[n], p[n], s[n]));

    cout << w;
}