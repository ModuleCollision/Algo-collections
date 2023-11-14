#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 2e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
ll head[maxn];
struct edge {
	ll nx; ll v; ll w;
} e[maxn << 1];
ll cnt = 0;
ll dis[maxn], ch[maxn << 5][2], tot = 1, ans = 0;
void solve() {
	auto insert = [&](ll x) {
		for (ll i = 30, u = 1; i >= 0; i--) {
			ll c = ((x >> i) & 1);
			if (not ch[u][c])ch[u][c] = ++tot;
			u = ch[u][c];
		}
	};
	auto get = [&](ll x) {
		ll res = 0;
		for (ll i = 30, u = 1; i >= 0; i--) {
			ll c = ((x >> i) & 1);
			if (ch[u][c ^ 1]) {
				u = ch[u][c ^ 1];
				res |= (1 << i);
			} else {
				u = ch[u][c];
			}
		}
		ans = max(ans, res);
	};
	auto add = [&](ll u, ll v, ll w) {
		e[cnt].v = v;
		e[cnt].nx = head[u];
		e[cnt].w = w;
		head[u] = cnt++;
	};
	function<void(ll, ll)>dfs = [&](ll u, ll f) {
		insert(dis[u]);
		get(dis[u]);
		for (ll i = head[u]; i != -1; i = e[i].nx) {
			ll v = e[i].v;
			if (v == f)continue;
			dis[v] = dis[u] ^ e[i].w;
			dfs(v, u);
		}
	};
	ll n; std::cin >> n;
	std::fill(head + 1, head + 1 + n, -1);
	for (ll i = 1; i < n; i++) {
		ll u, v, w; std::cin >> u >> v >> w;
		add(u, v, w);
		add(v, u, w);
	}
	dfs(1, 0);
	cout << ans << endl;
}
signed main() {
	solve();
}