#include <iostream>
#include <vector>
#include <array>
using namespace std;

#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

vector<ll> adj[200000]; ll hay[200000]; ll bale[200000]; ll sub[200000];

void bales(ll vertice, ll parent) {
    vector<ll> children {};

    for (ll i : adj[vertice]) {
        if (i == parent) continue;

        bales(i, vertice);
        children.push_back(i);
    }

    if (!children.empty()) {
        for (ll i : children) {
            sub[vertice] += sub[i];
            hay[vertice] += hay[i];
        }
    }
}

vector<array<ll, 3>> moves {}; ll avg {0};

void dfs(ll vertice, ll parent) {
    vector<ll> children {};

    for (ll child : adj[vertice]) {
        if (child == parent) continue;

        if (hay[child] >= sub[child] * avg) {
            dfs(child, vertice);
        } else {
            children.push_back(child);
        }
    }

    for (ll child : children) {
        moves.push_back({vertice, child, avg * sub[child] - hay[child]});

        bale[vertice] -= avg * sub[child] - hay[child]; bale[child] += avg * sub[child] - hay[child];

        dfs(child, vertice);
    }

    moves.push_back({vertice, parent, max(bale[vertice] - avg, 0ll)});
    bale[parent] += max(bale[vertice] - avg, 0ll); bale[vertice] = avg;
}

int main() {
    io

    ll n {}; cin >> n;

    for (ll i {0}; i < n; ++i) {
        cin >> hay[i]; bale[i] = hay[i]; ++sub[i]; avg += hay[i];
    }
    for (ll i {0}; i < n - 1; ++i) {
        ll a {}, b {}; cin >> a >> b; --a; --b;
        adj[a].push_back(b); adj[b].push_back(a);
    }

    avg /= n;

    bales(0, 0); dfs(0, 0);

    ll m {0};

    for (auto i : moves) m += (i[2] != 0);

    cout << m << "\n";

    for (auto i : moves) {
        if (i[2] == 0) continue;

        cout << i[0] + 1 << " " << i[1] + 1 << " " << i[2] << "\n";
    }

    return 0;
}