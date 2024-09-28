#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

#define io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define game_(vertice) game[vertice.first][vertice.second]
#define monsters_(vertice) monsters[vertice.first][vertice.second]
#define visited_(vertice) visited[vertice.first][vertice.second]

typedef long long ll;

typedef pair<ll, ll> pii;

void floodfill(const vector<vector<char>>& game, vector<vector<ll>>& monsters, const ll& n, const ll& m) {
    queue<pii> q {}; for (ll i {1}; i <= n; ++i) {
        for (ll j {1}; j <= m; ++j) {
            if (game[i][j] == 'M') {
                monsters[i][j] = 0; q.emplace(i, j);
            }
        }
    } while (!q.empty()) {
        pii vertice = q.front(); q.pop();

        pii a {vertice}; --a.first; if ((game_(a) == '.' || game_(a) == 'A') && monsters_(a) == -1) {
            q.push(a); monsters_(a) = monsters_(vertice) + 1;
        }
        pii b {vertice}; ++b.first; if ((game_(b) == '.' || game_(b) == 'A') && monsters_(b) == -1) {
            q.push(b); monsters_(b) = monsters_(vertice) + 1;
        }
        pii c {vertice}; --c.second; if ((game_(c) == '.' || game_(c) == 'A') && monsters_(c) == -1) {
            q.push(c); monsters_(c) = monsters_(vertice) + 1;
        }
        pii d {vertice}; ++d.second; if ((game_(d) == '.' || game_(d) == 'A') && monsters_(d) == -1) {
            q.push(d); monsters_(d) = monsters_(vertice) + 1;
        }
    }
}

void bfs(const vector<vector<char>>& game, const vector<vector<ll>>& monsters, const ll& n, const ll& m) {
    pii p {}; for (ll i {1}; i <= n; ++i) {
        for (ll j {1}; j <= m; ++j) {
            if (game[i][j] == 'A') {
                p = {i, j}; break;
            }
        }
    }

    queue<pii> q {}; q.push(p);

    if (p.first == 1 || p.first == n || p.second == 1 || p.second == m) {
        cout << "YES\n0"; return;
    }

    vector<vector<ll>> visited (n + 2, vector<ll> (m + 2, -1)); visited_(p) = 0;
    map<pii, pii> parents {};

    pair<ll, ll> boundary {};

    while (!q.empty()) {
        pii vertice = q.front(); q.pop();

        if (vertice.first == 1 || vertice.first == n || vertice.second == 1 || vertice.second == m) {
            boundary = vertice; break;
        }

        pii a {vertice}; --a.first; if (game_(a) == '.' && (monsters_(a) > visited_(vertice) + 1 || monsters_(a) == -1) && visited_(a) == -1) {
            q.push(a); visited_(a) = visited_(vertice) + 1; parents[a] = vertice;
        }

        pii b {vertice}; ++b.first; if (game_(b) == '.' && (monsters_(b) > visited_(vertice) + 1 || monsters_(b) == -1) && visited_(b) == -1) {
            q.push(b); visited_(b) = visited_(vertice) + 1; parents[b] = vertice;
        }

        pii c {vertice}; --c.second; if (game_(c) == '.' && (monsters_(c) > visited_(vertice) + 1 || monsters_(c) == -1) && visited_(c) == -1) {
            q.push(c); visited_(c) = visited_(vertice) + 1; parents[c] = vertice;
        }

        pii d {vertice}; ++d.second; if (game_(d) == '.' &&(monsters_(d) > visited_(vertice) + 1 || monsters_(d) == -1) && visited_(d) == -1) {
            q.push(d); visited_(d) = visited_(vertice) + 1; parents[d] = vertice;
        }
    }

    if (boundary.first == 0 && boundary.second == 0) {
        cout << "NO";
    } else {
        vector<pii> path {boundary}; while (parents[boundary] != p) {
            boundary = parents[boundary]; path.push_back(boundary);
        } path.push_back(p); reverse(path.begin(), path.end());

        cout << "YES\n" << path.size() - 1 << "\n";

        for (ll i {0}; i < path.size() - 1; ++i) {
            if (path[i].first - path[i + 1].first == -1) {
                cout << 'D';
            } else if (path[i].first - path[i + 1].first == 1) {
                cout << 'U';
            } else if (path[i].second - path[i + 1].second == 1) {
                cout << 'L';
            } else {
                cout << 'R';
            }
        }
    }
}

int main() {
    io

    ll n {}, m {}; cin >> n >> m;

    vector<vector<char>> game (n + 2, vector<char> (m + 2, ' ')); for (ll i {1}; i <= n; ++i) {
        for (ll j {1}; j <= m; ++j) cin >> game[i][j];
    }
    vector<vector<ll>> monsters (n + 2, vector<ll> (m + 2, -1));

    floodfill(game, monsters, n, m); bfs(game, monsters, n, m);

    return 0;
}