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

int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> dp(n + 1);
    dp[1] = 1;
    dp[0] = 0;
    for (int i = 2; i <= n; i++) {
        ll cnt = 1;
        while (i - cnt > max(i - k- 1, ll(0))) {
            dp[i] += dp[i - cnt];
            cnt++;
        }
    }
    cout << dp[n] << endl;
    return 0;
}
