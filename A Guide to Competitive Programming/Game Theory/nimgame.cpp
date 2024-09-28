#include <iostream>
#include <vector>
using namespace std;

#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

int main() {
    io

    int n {}; cin >> n;

    vector<int> a (n); for (int i {0}; i < n; ++i) cin >> a[i];

    int s {a[0]}; for (int i {1}; i < n; ++i) s = (s^a[i]);

    cout << (s == 0 ? "Bob" : "Alice") << "\n";

    return 0;
}