#include <iostream>
#include <queue>
using namespace std;

#define tc int t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

void solve() {
    int n {}; cin >> n;

    priority_queue<int> a {}; for (int i {0}; i < n; ++i) {
        int j {}; cin >> j; a.push(-j);
    }

    while (!a.empty()) {
        int i = a.top(); a.pop(); if (a.empty()) {
            cout << -i << "\n"; break;
        }

        int j = a.top(); a.pop();
        a.push((i + j) / 2);
    }
}

int main() {
    io
    tc

    return 0;
}