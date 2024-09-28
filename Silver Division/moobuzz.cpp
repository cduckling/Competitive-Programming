#include <iostream>
#include <cstdio>
using namespace std;

typedef long long ll;

int main() {
    freopen("moobuzz.in", "r", stdin); freopen("moobuzz.out", "w", stdout);

    ll n {}; cin >> n;

    pair<ll, ll> interval {1, 2000000000};

    while (interval.first != interval.second) {ll m {(interval.first + interval.second) / 2}, p {m - m / 3 - m / 5 + m / 15}; if (p < n) {interval.first = m + 1;} else {interval.second = m;}}

    cout << interval.first;
}