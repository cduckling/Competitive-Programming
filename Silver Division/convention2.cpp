#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

bool visited[1000000];

int main() {
    freopen("convention2.in", "r", stdin); freopen("convention2.out", "w", stdout);


    int n {}; cin >> n;

    pair<int, int> a[n]; int t[n];
    for (int i {0}; i < n; ++i) {cin >> a[i].first >> t[i]; a[i].second = {i};}
    sort(a, a + n);

    int wait {0};

    if (n == 1) {
        cout << wait;
    } else {
        int time {a[0].first + t[a[0].second]}; visited[a[0].second] = true;

        for (int i {1}; i < n; ++i) {
            pair<int, int> cow {0, n};

            for (int j {0}; j < n; ++j) {
                if (a[j].first > time) {
                    if (cow.first == 0 && cow.second == n) {cow = a[j]; cow.second -= n;} break;
                } else {
                    if (a[j].second < cow.second && !visited[a[j].second]) {cow = a[j];}
                }
            }

            if (cow.second < 0) {
                cow.second += n;
                time = cow.first + t[cow.second];
            } else {
                wait = max(wait, time - cow.first);
                time += t[cow.second];
            }

            visited[cow.second] = true;
        }

        cout << wait;
    }
}