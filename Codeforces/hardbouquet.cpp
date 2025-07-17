#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

#define tc int t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

void solve() {
    ll n {}, m {}; cin >> n >> m;

    vector<pair<ll, ll>> a (n);
    for (int i {0}; i < n; ++i) {
        cin >> a[i].first;
    }
    for (int i {0}; i < n; ++i) {
        cin >> a[i].second;
    }
    sort(a.begin(), a.end());
    
    ll petals {0};
    for (int i {0}; i < n; ++i) {
        ll next = 0;

        if (a[i + 1].first == a[i].first + 1) {next = a[i + 1].second;}

        ll b_{min(a[i].second, m / a[i].first)}, rem{m - b_ * a[i].first}, a_ {0}; if (next > 0) {a_ = {min(next, rem / (a[i].first + 1))}; rem -= a_ * (a[i].first + 1);}

        petals = max(petals, b_ * a[i].first + a_ * (a[i].first + 1));

        ll c_ = min(min(b_, rem), next - a_); b_ -= c_; a_ += c_;

        petals = max(petals, b_ * a[i].first + a_ * (a[i].first + 1));
    }

    cout << petals << "\n";
}

int main() {
    tc
    io

    return 0;
}