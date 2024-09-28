#include <iostream>
#include <vector>
using namespace std;

int n {};

bool visited[500];
bool cycle = false;
vector<int> adjacency[500];

void dfs(int cow, int preference) {
    if (preference == cow) {
        cycle = true;
        return;
    } else if (visited[preference]) {
        return;
    } else {
        visited[preference] = true;
        for (int i : adjacency[preference]) {
            dfs(cow, i);
        }
    }
}

int main() {
    cin >> n;

    int wishlists[n][n];
    for (int i {0}; i < n; ++i) {
        for (int j {0}; j < n; ++j) {
            cin >> wishlists[i][j];
            --wishlists[i][j];
        }
    }

    for (int i {0}; i < n; ++i) {
        for (int j {0}; j < n; ++j) {
            if (wishlists[i][j] != i) {
                adjacency[i].push_back(wishlists[i][j]);
            } else {
                break;
            }
        }
    }

    for (int i {0}; i < n; ++i) {
        int gift {-1};

        for (int j {0}; j < n; ++j) {
            if (wishlists[i][j] != i) {
                for (int k {0}; k < n; ++k) {visited[k] = false;}
                dfs(i, wishlists[i][j]);
                if (cycle) {gift = {wishlists[i][j]}; cycle = false; break;}
            } else {
                break;
            }
        }

        cout << (gift == -1 ? i + 1 : gift + 1) << "\n";
    }
}