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

vector<ll> sq;
ll k = 0;

void init(vector<ll>& a) {
    ll n = a.size();
    k = sqrt(n);
    for (int i = 0; i < a.size(); i+=k) {
        ll sum = 0;
        for (int j = i; j < min( n ,i + k); j++) {
            sum += a[j];
        }
        sq.push_back(sum);
    }
    return;
}

ll sum(vector<ll>& a, ll l , ll r) {
    ll n = a.size();
    ll sum = 0;
    while (l % k != 0) {
        sum += a[l];
        l++;
    }
    while ((r + 1) % k != 0) {
        sum += a[r];
        r--;
    }
    for (int i = l; i <= r; i+= k) {
        sum += sq[i / k];
    }
    return sum;
}

void update(vector<ll>& a, ll pos, ll x) {
    ll n = a.size();
    ll i = pos / k;
    a[pos] = x;
    ll sum = 0;
    for (int j = pos; j < i + k; j++) {
        sum += a[j];
    }
    sq[i] = sum;
    return;
}

int main() {
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    init(v);
    ll q;
    cin >> q;
    while (q--) {
        ll l, r;
        cin >> l >> r;
        l--; r--;
        cout << sum(v, l, r) << endl;
    }
    return 0;
}