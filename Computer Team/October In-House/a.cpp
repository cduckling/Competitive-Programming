#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

void solve() {
    vector<pair<int, string>> a (3);

    a[0].second = "Avni";
    a[1].second = "Bavnith";
    a[2].second = "Clinton";

    cin >> a[0].first >> a[1].first >> a[2].first;

    sort(a.begin(), a.end()); cout << a[1].second;
}

int main() {
    io

    solve();

    return 0;
}