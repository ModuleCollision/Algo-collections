#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e5 + 5;
const ll inf = 0x3f3f3f3f;
const ll mod = 1e9 + 7;
void solve() {
	ll n; std::cin >> n;
	vector<vector<pair<ll, ll>>>tr(n + 5);
	for (ll i = 1; i <= n - 1; i++) {
		ll u, v; std::cin >> u >> v;
		tr[u].push_back({v, i});
		tr[v].push_back({u, i});
	}
	ll ans = 0;
	auto bfs = [&]() {
		queue<array<ll, 3>>q;
		q.push({1, 0, 1});
		vector<bool>vis(n + 5, 0); vis[1] = 1;
		while (q.size()) {
			auto [u, i1, s1] = q.front(); q.pop();
			ans = max(ans, s1);
			for (auto [v, i2] : tr[u]) {
				if (vis[v])continue;
				vis[v] = 1;
				if (i2 >= i1) {
					q.push({v, i2, s1});
				} else {
					q.push({v, i2, s1 + 1});
				}
			}
		}
	};
	bfs();
	cout << ans << endl;
}
signed main() {
	ll T; std::cin >> T;
	while (T--)
		solve();
}