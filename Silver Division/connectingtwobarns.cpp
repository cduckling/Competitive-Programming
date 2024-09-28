#include <iostream>
#include <vector>
using namespace std;

#define square(a) ((a) * (a))

int visited[100000];

void fill(int node, int color, vector<vector<int>>& adj) {
    if (visited[node]) {
        return;
    } else {
        visited[node] = color;

        for (int a : adj[node]) {
            fill(a, color, adj);
        }
    }
}
long long cost(vector<long long>& a, vector<long long>& b) {
    long long c {5000000000};

    for (long long A : a) {
        pair<int, int> interval {0, b.size() - 1};
        while (interval.first != interval.second) {
            int median = {(interval.first + interval.second) / 2};

            if (b[median] >= A) {
                interval.second = median;
            } else {
                interval.first = median + 1;
            }
        }

        if (interval.first == 0) {
            c = min(c, square(A - b[interval.first]));
        } else {
            c = min(c, min(square(A - b[interval.first - 1]), square(A - b[interval.first])));
        }
    }

    return c;
}

int main() {
    int t {}; cin >> t;

    while (t > 0) {
        int n {}, m {}; cin >> n >> m;

        vector<vector<int>> adj (n, vector<int> ());
        for (int i {0}; i < m; ++i) {
            pair<int, int> path {}; cin >> path.first >> path.second; --path.first; --path.second;
            adj[path.first].push_back(path.second);
            adj[path.second].push_back(path.first);
        } for (int i {0}; i < n; ++i) {
            visited[i] = 0;
        }
        int color {0}; for (int i {0}; i < n; ++i) {
            if (!visited[i]) {
                ++color;
                fill(i, color, adj);
            }
        }

        vector<long long> components[color];
        for (int i {0}; i < n; ++i) {
            --visited[i];
            components[visited[i]].push_back(i);
        }

        long long c {0};

        if (n == 1 || visited[0] == visited[n - 1]) {
            c = 0;
        } else {
            c = cost(components[visited[0]], components[visited[n - 1]]);

            for (int i {0}; i < color; ++i) {
                if (i != visited[0] && i != visited[n - 1]) {
                    long long a {0};
                    if (components[visited[0]].size() > components[i].size()) {
                        a = cost(components[i], components[visited[0]]);
                    } else {
                        a = cost(components[visited[0]], components[i]);
                    }

                    long long b {0};
                    if (components[visited[n - 1]].size() > components[i].size()) {
                        b = cost(components[i], components[visited[n - 1]]);
                    } else {
                        b = cost(components[visited[n - 1]], components[i]);
                    }

                    c = min(c, a + b);
                }
            }
        }

        cout << c << "\n";

        --t;
    }
}