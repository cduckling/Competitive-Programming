#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int n {}, k {};

int visited[100000];
unordered_set<int> positions[100000];

void flood(int node, int color, int adj[]) {
    if (visited[node]) {
        return;
    } else {
        visited[node] = color;
        flood(adj[node], color, adj);
    }
}

int main() {
    cin >> n >> k;

    int cows[n]; for (int i {0}; i < n; ++i) {
        cows[i] = i;
        positions[i].insert(i);
    }

    for (int i {0}; i < k; ++i) {
        int a {}, b {}; cin >> a >> b; --a; --b;
        positions[cows[a]].insert(b);
        positions[cows[b]].insert(a);
        swap(cows[a], cows[b]);
    }

    int color {0}; for (int i {0}; i < n; ++i) {
        if (!visited[i]) {
            ++color;
            flood(i, color, cows);
        }
    }

    vector<int> components[color]; for (int i {0}; i < n; ++i) {
        components[visited[i] - 1].push_back(i);
    }

    int sizes[n];
    for (int i {0}; i < color; ++i) {
        unordered_set<int> a {};

        for (int cow : components[i]) {
            for (int p : positions[cow]) {
                a.insert(p);
            }
        }

        for (int cow : components[i]) {
            sizes[cow] = a.size();
        }
    }

    for (int i {0}; i < n; ++i) {
        cout << sizes[i] << "\n";
    }
}