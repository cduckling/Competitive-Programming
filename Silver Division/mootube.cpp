#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int n {}, q {}, s {0}, k {};

bool videos[5000];

void dfs(int video, int relevance, vector<pair<int, int>> adjacency[]) {
    if (videos[video]) {
        return;
    } else {
        videos[video] = true;
        s += relevance >= k;
        for (pair<int, int> v : adjacency[video]) {
            dfs(v.first, min(relevance, v.second), adjacency);
        }
    }
}

int main() {
    freopen("mootube.in", "r", stdin); freopen("mootube.out", "w", stdout);

    cin >> n >> q;

    vector<pair<int, int>> adjacency[n];
    for (int i {1}; i < n; ++i) {
        pair<int, int> video {}; cin >> video.first >> video.second; --video.first; --video.second;
        int relevance {}; cin >> relevance;

        adjacency[video.first].emplace_back(video.second, relevance);
        adjacency[video.second].emplace_back(video.first, relevance);
    }

    for (int i {0}; i < q; ++i) {
        int v {}; cin >> k >> v; --v;
        dfs(v, 1000000001, adjacency);
        for (int j {0}; j < n; ++j) {videos[j] = false;}
        cout << s - 1 << "\n";
        s = 0;
    }
}