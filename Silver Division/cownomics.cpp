#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

typedef vector<vector<char>> genome;

int mapped(char c) {switch (c) {case 'A': return 0; case 'C': return 1; case 'G': return 2; case 'T': return 3;}}

bool explain(genome spotty, genome plain, int i, int j, int k) {
    int n {static_cast<int>(spotty.size())};

    vector<int> c (64, 0);

    for (int a {0}; a < n; ++a) {++c[16 * mapped(spotty[a][i]) + 4 * mapped(spotty[a][j]) + mapped(spotty[a][k])];}
    for (int a {0}; a < n; ++a) {if (c[16 * mapped(plain[a][i]) + 4 * mapped(plain[a][j]) + mapped(plain[a][k])]) {return false;}}

    return true;
}

int main() {
    freopen("cownomics.in", "r", stdin); freopen("cownomics.out", "w", stdout);

    int n {}, m {}; cin >> n >> m;

    genome spotty (n, vector<char> (m, ' '));
    genome plain (n, vector<char> (m, ' '));

    for (int i {0}; i < n; ++i) {for (int j {0}; j < m; ++j) {cin >> spotty[i][j];}}
    for (int i {0}; i < n; ++i) {for (int j {0}; j < m; ++j) {cin >> plain[i][j];}}

    int position {0};

    for (int i {0}; i < m; ++i) {
        for (int j {i + 1}; j < m; ++j) {
            for (int k {j + 1}; k < m; ++k) {
                position += explain(spotty, plain, i, j, k);
            }
        }
    }

    cout << position;
}