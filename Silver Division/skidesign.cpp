#include <iostream>
#include <cstdio>
using namespace std;

typedef long long ll;

int main() {
    freopen("skidesign.in", "r", stdin); freopen("skidesign.out", "w", stdout);

    int n {}; cin >> n;

    ll a[n];
    for (int i {0}; i < n; ++i) {cin >> a[i];}

    ll cost {1000000};

    for (ll i {0}; i < 83; ++i) {ll c {0}; for (ll h : a) {if (h < i) {c += (i - h) * (i - h);} if (h > i + 17) {c += (h - i - 17) * (h - i - 17);}} cost = min(cost, c);}

    cout << cost;
}