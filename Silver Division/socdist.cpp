#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

typedef long long ll;

ll n {}, m {};

ll grazing(ll d, vector<pair<ll, ll>> fields) {
    ll cows {0}, end {-1};

    for (ll i {0}; i < m; ++i) {
        if (end >= fields[i].first) {
            fields[i].first = end + 1;
            if (fields[i].first > fields[i].second) {
                continue;
            }
        }

        ll points {fields[i].second - fields[i].first + 1};
        ll additional {(points + d - 1) / d};
        cows += additional;
        end = fields[i].first + additional * d - 1;
    }

    return cows;
}

int main() {
    freopen("socdist.in", "r", stdin); freopen("socdist.out", "w", stdout);

    cin >> n >> m;

    vector<pair<ll, ll>> fields (m, {0, 0});
    for (ll i {0}; i < m; ++i) {cin >> fields[i].first >> fields[i].second;}
    sort(fields.begin(), fields.end());

    pair<ll, ll> interval {1, 1000000000000000000};

    while (interval.first != interval.second) {
        ll d {(interval.first + interval.second + 1) / 2};

        if (grazing(d, fields) >= n) {
            interval.first = d;
        } else {
            interval.second = d - 1;
        }
    }

    cout << interval.first;
}