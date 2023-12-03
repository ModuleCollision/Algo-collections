#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e6 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
void solve() {
	ll n, m, k; std::cin >> n >> m >> k;
	vector<ll>h(n + 5, 0);
	vector<vector<ll>>tr(n + 1);
	vector<ll>d(n + 5, 0), w(n + 5, 0);
	queue<ll>q;
	for (ll i = 1; i <= n; i++)cin >> h[i];
	for (ll i = 1; i <= m; i++) {
		ll u, v; std::cin >> u >> v;
		tr[u].push_back(v); w[v]++;
	}
	vector<pair<ll, ll>>p;
	for (ll i = 1; i <= n; i++) {
		if (not w[i]) {
			q.push(i); p.push_back({i, h[i]});
		}
	}
	while (q.size()) {
		auto u = q.front(); q.pop();
		for (auto v : tr[u]) {
			w[v]--;
			d[v] = max(d[v], d[u] + (h[u] > h[v]));
			if (not w[v])q.push(v);
		}
	}
	ll ws = 0;
	for (ll i = 1; i <= n; i++) {
		ws = max(ws, d[i] * k + h[i]);
	}
	ll ans = inf;
	function<void(ll)>dfs = [&](ll x) {
		d[x]++;
		ws = max(ws, d[x] * k + h[x]);
		for (auto v : tr[x]) {
			if (d[v] < (d[x] + (h[x] > h[v])))dfs(v);
		}
	};
	std::sort(p.begin(), p.end(), [&](auto x, auto y)->bool{
		return x.se < y.se;
	});
	for (ll i = 0; i < p.size(); i++) {
		ans = min(ans, ws - p[i].se);
		dfs(p[i].fi);
	}
	cout << ans << endl;
}
signed main() {
	ll T; std::cin >> T;
	while (T--)
		solve();
}