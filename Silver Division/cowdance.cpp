#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;

queue<int> d {};

int ballet(int k) {
    queue<int> durations = d;
    priority_queue <int, vector<int>, greater<>> dancing;
    for (int i {0}; i < k; ++i) {dancing.push(durations.front()); durations.pop();}

    int time {0};

    for (int i {0}; i < d.size(); ++i) {
        time = max(time, dancing.top()); dancing.pop();
        if (!durations.empty()) {dancing.push(durations.front() + time); durations.pop();}
    }

    return time;
}

int main() {
    freopen("cowdance.in", "r", stdin); freopen("cowdance.out", "w", stdout);

    int n {}, t {}; cin >> n >> t;

    for (int i {0}; i < n; ++i) {int j {}; cin >> j; d.push(j);}

    pair<int, int> k {1, n};

    while (k.first != k.second) {
        int m {(k.first + k.second) / 2};

        if (ballet(m) <= t) {
            k.second = m;
        } else {
            k.first = m + 1;
        }
    }

    cout << k.first;
}