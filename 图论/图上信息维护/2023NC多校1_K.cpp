#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
	ll n, m = 0, k = 0; std::cin >> n >> m >> k;
	vector<vector<pair<ll, ll>>>tr(n + 5);
	vector<pair<ll, ll>>e(m + 5); vector<ll>d(n + 5, 0);
	for (ll i = 1; i <= m; i++) {
		ll u, v; std::cin >> u >> v;
		d[u]++; d[v]++;
		tr[u].push_back({i, v});
		tr[v].push_back({i, u});
		e[i] = {u, v};
	}
	vector<bool>vis(m + 5, 0);
	queue<ll>q; q.push(1); ll res = 0;
	vector<ll>dis(n + 5, -1); dis[1] = 0; ll maxd = 0;
	while (q.size()) {
		auto u = q.front(); q.pop();
		maxd = max(maxd, dis[u]);
		if (dis[u] <= k)res++;
		for (auto [idx, v] : tr[u]) {
			if (dis[v] != -1)continue;
			dis[v] = dis[u] + 1;
			q.push(v);
			vis[idx] = 1;
		}
	}
	std::map<ll, vector<ll>>ws;
	for (ll i = 1; i <= n; i++) {
		ws[dis[i]].push_back(i);
		//cout << "#" << dis[i] << endl;
	}
	//cout << "#" << dis[2] << endl;
	for (ll i = 1; i <= min(maxd, k - 1); i++) {
		for (auto u : ws[i]) {
			if (d[u] == 1)res += k - i;
			//continue;
			for (auto [idx, v] : tr[u]) {
				if (vis[idx])continue;
				res += k - i;
			}
		}
	}
	//if (res == 13)res += 2;
	cout << res << endl;
}
signed main() {
	solve();
}