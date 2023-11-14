#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 5e3 + 5;
const ll inf = 0x3f3f3f3f;
const ll mod = 998244353;
ll n, m, q, t, s;
vector<ll>tr[maxn];
ll dis[maxn], vis[maxn];
void solve() {
	std::cin >> n >> m >> q;

	for (ll i = 1; i <= m; i++) {
		ll u, v; std::cin >> u >> v;
		tr[u].push_back(v);
		tr[v].push_back(u);
	}
	while (q--) {
		std::cin >> t >> s;
		std::priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>>pq;
		memset(dis, 0x3f, sizeof(dis));
		memset(vis, 0, sizeof(vis));
		for (ll i = 1; i <= t; i++) {
			ll v; std::cin >> v; pq.push({0, v});
			dis[v] = 0;
		}
		while (pq.size()) {
			auto cur = pq.top();
			pq.pop();
			ll u = cur.second, d = cur.first; vis[u] = 1;
			for (auto v : tr[u]) {
				if (dis[v] > dis[u] + 1) {
					dis[v] = min(dis[v], dis[u] + 1);
					if (not vis[v]) {
						pq.push({dis[v], v});
					}
				}
			}
		}
		ll ans = 0;
		for (ll i = 1; i <= n; i++) {
			if (dis[i] and dis[i] <= s) {
				ans++;
			}
		}
		cout << ans << endl;
	}
}
signed main() {
	solve();
}