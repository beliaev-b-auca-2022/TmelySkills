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

struct graph {
    ll to, cost;
};

vector<vector<graph>> g(1e5 + 1);

int main() {
    ll n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        ll x, y , cost;
        cin >> x >> y >> cost;
        x--; y--;
        g[x].push_back({ y,cost });
        g[y].push_back({ x,cost });
    }
    vector<ll> d(n + 1, 1e18);
    vector<bool> used(n + 1, false);
    set<pair<ll, ll>> s;
    s.insert({ 0 , 0 });
    d[0] = 0;
    while (!s.empty()) {
        auto itt = s.begin();
        ll mn = 0, mni = 0;
        mn = itt->first;
        mni = itt->second;
        s.erase(itt);
        used[mni] = true;
        for (int i = 0; i < g[mni].size(); i++) {
            ll to = g[mni][i].to, cost = g[mni][i].cost;
            if (d[to] > d[mni] + cost) {
                d[to] = d[mni] + cost;
                s.insert({ d[to] , to });
            }
        }
    }
    if (d[n - 1] == 1e18) {
        cout << -1 << endl;
        return 0;
    }
    cout << d[n - 1] << endl;
    return 0;
}