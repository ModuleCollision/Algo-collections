#include <bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 5e3 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
void solve() {
	ll n, m, k;
	std::cin >> n >> m >> k;
	vector<vector<ll>> G(n + 5, vector<ll>(m + 5, 0));
	ll ans = k;
	ll u, v; ll s = 0;
	for (ll i = 1; i <= k; i++) {
		cin >> u >> v;
		G[u][v] = 1;
	}
	vector<pair<ll, ll>>dir = {{1, 0}, { -1, 0}, {0, 1}, {0, -1}};
	function<void(ll)> dfs = [&](ll s) {
		ans = min(ans, s);
		for (ll i = 1; i <= n; i++) {
			for (ll j = 1; j <= m; j++) {
				if (not G[i][j])continue;
				for (auto [dx, dy] : dir) {
					ll x = i + dx; ll y = j + dy;
					if (not (x >= 1 and x <= n and y >= 1 and y <= m))continue;
					ll xx = x + dx, yy = y + dy;
					if (not (xx >= 1 and xx <= n and yy >= 1 and yy <= m))continue;
					if ((G[i][j] == 1 and G[x][y] == 1 and G[xx][yy] == 0)) {
						G[i][j] = 0; G[x][y] = 0; G[xx][yy] = 1;
						dfs(s - 1);
						G[i][j] = 1; G[x][y] = 1; G[xx][yy] = 0;
					}
				}
			}
		}
	};
	dfs(k);
	cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	ll t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}