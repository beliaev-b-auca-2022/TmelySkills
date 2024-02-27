#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <map>
#include <string>
#include <bitset>
#include <queue>

using namespace std;

typedef long long ll;

vector<bool> used(1e5 + 1, false);
vector<vector<ll>> g(1e5 + 1);

void dfs(ll s) {
    used[s] = true;
    for (int i = 0; i < g[s].size(); i++) {
        ll to = g[s][i];
        if (!used[to]) {
            dfs(to);
        }
    }
}

int main() {
    ll n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        x--; y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    ll s, t;
    cin >> s >> t;
    s--; t--;
    queue<ll> q;
    q.push(s);
    vector<ll> d(n + 1, 1e9);
    vector<bool> used(n + 1, false);
    d[s] = 0;
    used[s] = true;
    while (!q.empty()) {
        ll v = q.front();
        q.pop();
        for (int i = 0; i < g[v].size(); i++) {
            ll to = g[v][i];
            if (!used[to]) {
                d[to] = d[v] + 1;
                used[to] = true;
                q.push(to);
            }
        }
    }
    cout << d[t] << endl;
    return 0;
}