#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int n {};

int loss[100000];

int main() {
    freopen("lifeguards.in", "r", stdin); freopen("lifeguards.out", "w", stdout);

    cin >> n;

    pair<int, pair<bool, int>> shifts[2 * n];
    for (int i {0}; i < n; ++i) {
        cin >> shifts[2 * i].first >> shifts[2 * i + 1].first;
        shifts[2 * i].second = {false, i}; shifts[2 * i + 1].second = {true, i};
    }
    sort(shifts, shifts + 2 * n);

    set<int> cows {}; int time {shifts[0].first}, empty {0};
    for (int i {0}; i < 2 * n; ++i) {
        if (cows.size() == 1) {
           loss[*cows.begin()] += shifts[i].first - time;
        }

        if (cows.empty()) {
            empty += shifts[i].first - time;
        }

        if (shifts[i].second.first) {
            cows.erase(shifts[i].second.second);
        } else {
            cows.insert((shifts[i].second.second));
        }

        time = shifts[i].first;
    }

    int l {1000000000};
    for (int i {0}; i < n; ++i) {
        l = min(l, loss[i]);
    }


    cout << shifts[2 * n - 1].first - shifts[0].first - empty - l;
}