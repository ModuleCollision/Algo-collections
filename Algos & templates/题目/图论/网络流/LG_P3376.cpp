#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 5e6 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
ll head[maxn], cur[maxn]; ll dep[maxn];
struct edge {
	ll v, cap; ll flow; ll nxt;
} e[maxn]; ll cnt = 0;
/*这里是模板题, 最大流*/
void solve() {
	ll n, m, s, t; std::cin >> n >> m >> s >> t;
	std::fill(head + 1, head + 1 + n, -1);
	auto add_edge = [&](ll u, ll v, ll w) {
		e[cnt] = {v, w, 0, head[u]};
		head[u] = cnt++;
	};
	ll a, b, c;
	for (ll i = 1; i <= m; i++) {
		std::cin >> a >> b >> c;
		add_edge(a, b, c);
		add_edge(b , a, 0);
	}
	auto bfs = [&]() {
		queue<ll>q; std::fill(dep + 1, dep + 1 + n, 0);
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
			ll v = e[j].v; ll d;
			if ((dep[v] == dep[u] + 1) and (d = dfs(v, min(e[j].cap - e[j].flow, flow - ret)))) {
				//剩余容量递归
				//到达汇点时的剩余流量回溯至增广路
				ret += d;
				e[j].flow += d;
				e[j ^ 1].flow -= d;
				if (ret == flow)return ret;
			}
		}
		return ret;
	};
	ll ans = 0;
	auto dinic = [&]() {
		while (bfs()) {
			memcpy(cur, head, sizeof(ll) * (n + 1));
			ll d = 0;
			while (d = dfs(s, inf))
				ans += d;
		}
	};
	dinic();
	cout << ans << endl;
}
signed main() {
	solve();
}