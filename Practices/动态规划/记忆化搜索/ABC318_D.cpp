#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e6 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
	ll n; std::cin >> n;
	vector w(n + 5, vector<ll>(n + 5, 0));
	for (ll i = 1; i <= n - 1; i++) {
		for (ll j = i + 1; j <= n; j++)cin >> w[i][j];
	}
	std::map<pair<ll, ll>, ll>dp;
	function<ll(ll, ll)>dfs = [&](ll x, ll y) {
		if (not x) {
			return dp[ {x, y}] = 0;
		}
		if (dp.count({x, y}))return dp[ {x, y}];
		ll res = 0;
		res = max(res, dfs(x - 1, y));
		for (ll j = x + 1; j <= n; j++) {
			if (((y >> (j - 1)) & 1) == 1 and ((y >> (x - 1)) & 1) == 1) {
				res = max(res, dfs(x - 1, y - (1 << (j - 1)) - (1 << (x - 1))) + w[x][j]);
			}
		}
		dp[ {x, y}] = res;
		return res;
	};
	ll ans = 0;
	for (ll i = 0; i < (1 << n); i++) {
		ans = max(ans, dfs(n - 1, i));
	}
	cout << ans << endl;
}
signed main() {
	solve();
}