#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 3010;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
	ll n, p, x, q, y; std::cin >> n >> p >> x >> q >> y;
	ll tot = 0;
	for (ll i = 1; i <= n; i++) {
		ll v; std::cin >> v;
		tot = (tot % n + v) % n;
	}
	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>>que;
	vector<vector<pair<ll, ll>>>tr(n + 1);
	for (ll i = 0; i < n; i++) {
		ll v = (i + x) % n;
		tr[i + 1].push_back({v + 1, p});
		v = ((i - y) % n + n) % n;
		tr[i + 1].push_back({v + 1, q});
	}
	vector<ll>dis(n + 5, inf);
	auto dij = [&]() {

		que.push({0, tot + 1});
		dis[tot + 1] = 0; vector<bool>vis(n + 5, false);
		while (que.size()) {
			auto [d, u] = que.top();
			que.pop(); vis[u] = 1;
			for (auto [v, w] : tr[u]) {
				if (dis[u] + w < dis[v]) {
					dis[v] = dis[u] + w;
					if (not vis[v]) {
						que.push({vis[v], v});
					}
				}
			}
		}
	};
	dij();
	if (dis[1] == inf) {
		puts("-1");
	} else {
		cout << dis[1] << endl;
	}
}
signed main() {

	solve();
}