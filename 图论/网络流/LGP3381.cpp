/*最小费用最大流模板*/
#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 5e6 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
struct edge {
	ll v; ll cap; ll flow; ll c; ll nx;
} e[maxn];
ll head[maxn], cur[maxn], dis[maxn]; bool vis[maxn];
void solve() {
	ll n, m, s, t; std::cin >> n >> m >> s >> t;
	std::fill(head + 1, head + 1 + n, -1);
	ll cnt = 0;
	auto add_edge = [&](ll u, ll v, ll w, ll c) {
		e[cnt].flow = 0;
		e[cnt].v = v; e[cnt].cap = w; e[cnt].c = c; e[cnt].nx = head[u];
		head[u] = cnt++;
	};
	while (m--) {
		ll u, v, w, c; std::cin >> u >> v >> w >> c;
		add_edge(u, v, w, c);
		add_edge(v, u, 0, -c);
	}
	auto spfa = [&](ll s, ll t) {
		std::fill(dis + 1, dis + 1 + n, inf);
		std::queue<ll>q;
		q.push(s); dis[s] = 0; vis[s] = 1;
		while (q.size()) {
			ll u = q.front();
			q.pop(); vis[u] = 0;
			for (ll i = head[u]; i != -1; i = e[i].nx) {
				ll v = e[i].v;
				if (e[i].cap > e[i].flow and dis[v] > dis[u] + e[i].c) {
					dis[v] = dis[u] + e[i].c;
					if (not vis[v]) {
						vis[v] = 1; q.push(v);
					}
				}
			}
		}
		return dis[t] != inf;
	};
	ll ret = 0;
	function<ll(ll , ll, ll)>dfs = [&](ll u, ll t, ll flow) {
		if (u == t)return flow;
		vis[u] = 1;
		ll ans = 0;
		for (ll i = cur[u]; i != -1 and ans < flow; i = e[i].nx) {
			ll v = e[i].v;
			if (not vis[v] and e[i].cap - e[i].flow and dis[v] == dis[u] + e[i].c) {
				ll x = dfs(v, t, min(e[i].cap - e[i].flow, flow - ans));
				if (x) {
					ret += x * e[i].c; e[i].flow += x; e[i ^ 1].flow -= x;
					ans += x;
				}
			}
		}
		vis[u] = 0;
		return ans;
	};
	auto mcmf = [&](ll s, ll t) {
		ll ans = 0;
		while (spfa(s, t)) {
			memcpy(cur, head, sizeof(ll) * (n + 1));
			ll x; while (x = dfs(s, t, inf)) {
				ans += x;
			}
		}
		return ans;
	};
	cout << mcmf(s, t) << " " << ret << endl;
}
signed main() {
	solve();
}