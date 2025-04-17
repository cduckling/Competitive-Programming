#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

#define tc ll t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;
typedef pair<ll, ll> pii;

void solve() {
    ll n {}, d {}, k {}; cin >> n >> d >> k;

    vector<pii> jobs (k); for (ll i {0}; i < k; ++i) cin >> jobs[i].first >> jobs[i].second;

    map<ll, ll> diff; for (ll i {0}; i < k; ++i) if (max(1ll, jobs[i].first - (d - 1)) <= min(n - d + 1, jobs[i].second)) {++diff[max(1ll, jobs[i].first - (d - 1))]; --diff[min(n - d + 1, jobs[i].second) + 1];}

    pii extrema {-1, 1e9}; ll c = {0}, max = {1}, min = {1};

    for (ll i = {1}; i <= n - d + 1; ++i) {
        if (diff.find(i) != diff.end()) c += diff[i];
        if (c > extrema.first) {extrema.first = c; max = i;}
        if (c < extrema.second) {extrema.second = c; min = i;}
    }

    cout << max << " " << min << "\n";
}

int main() {
    io
    tc

    return 0;
}