#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e4 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
ll head[maxn], cur[maxn]; ll dep[maxn];
struct edge {
	ll v, cap; ll flow; ll nxt;
} e[200005]; ll cnt = 0; ll s, t;
/*此题为求解二分图最大匹配,转换为网络流问题求解*/
void solve() {
	ll n, m; std::cin >> n >> m;
	std::fill(head, head + n + 5, -1);
	auto add_edge = [&](ll u, ll v, ll w) {
		e[cnt] = {v, w, 0, head[u]};
		head[u] = cnt++;
	};
	ll u, v;
	while (cin >> u >> v) {
		add_edge(u, v, 1);
		add_edge(v, u, 0);
		//if (not u or not v)break;
	}
	for (ll i = 1; i <= m; i++) {
		add_edge(0, i, 1);
		add_edge(i, 0, 0);
	}
	for (ll i = m + 1; i <= n; i++) {
		add_edge(i, n + 1, 1);
		add_edge(n + 1, i, 0);
	}
	s = 0, t = n + 1;
	auto bfs = [&]() {
		queue<ll>q; for (ll i = 0; i <= n + 5; i++)dep[i] = 0;
		dep[s] = 1;
		q.push(s);
		while (q.size()) {
			ll u = q.front(); q.pop();
			for (ll j = head[u]; j != -1; j = e[j].nxt) {
				ll v = e[j].v;
				if ((not dep[v]) and (e[j].cap > e[j].flow)) {
					dep[v] = dep[u] + 1;//未曾增广过而且流量存有剩余
					q.push(v);
				}
			}
		}
		return dep[t];
	};
	function<ll(ll , ll)>dfs = [&](ll u, ll flow) {
		if (u == t or (not flow))return flow;
		ll ret = 0;
		for (ll j = cur[u]; j != -1; j = e[j].nxt) {
			ll v = e[j].v;
			if (dep[v] == dep[u] + 1) {
				//到达汇点时的剩余流量回溯至增广路
				ll d = dfs(v, min(e[j].cap - e[j].flow, flow - ret));
				if (d) {
					ret += d;
					e[j].flow += d;
					e[j ^ 1].flow -= d;
					if (ret == flow)return ret;
				}
			}
		}
		return ret;
	};
	ll ans = 0;
	auto dinic = [&]() {
		while (bfs()) {
			ll d = 0;
			memcpy(cur, head, sizeof(ll) * (n + 5));
			while (d = dfs(s, inf)) {
				ans += d;
			}
		}
		cout << ans << endl;
	};
	dinic();
}
signed main() {
	solve();
}