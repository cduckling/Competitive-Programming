#include <iostream>
#include <cstdio>
using namespace std;

int n {};

bool broadcasts[200]; pair<int, int> cows[200]; int powers[200];

void dfs(int cow) {
    if (broadcasts[cow] || cows[cow].first == 0) {
        return;
    } else {
        broadcasts[cow] = true;
        for (int i {0}; i < n; ++i) {
            int d = (cows[cow].first - cows[i].first) * (cows[cow].first - cows[i].first) + (cows[cow].second - cows[i].second) * (cows[cow].second - cows[i].second);
            if (d <= powers[cow] * powers[cow]) {dfs(i);}
        }
    }
}

int main() {
    freopen("moocast.in", "r", stdin); freopen("moocast.out", "w", stdout);

    cin >> n;

    for (int i {0}; i < n; ++i) {
        cin >> cows[i].first >> cows[i].second >> powers[i];
    }

    int broadcast {0};
    for (int i {0}; i < n; ++i) {
        dfs(i);
        int b {0}; for (int j {0}; j < n; ++j) {b += broadcasts[j]; broadcasts[j] = false;} broadcast = max(b, broadcast);
    }

    cout << broadcast;
}