/*Tarjan缩点求SCC*/
#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 50005;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
struct edge {
	ll u; ll v; ll nx;
} e[maxn];
ll head[maxn]; ll tot_edge = 0;
ll dfn[maxn], low[maxn], dfncnt, s[maxn], in_stack[maxn], tp;
ll scc[maxn], sc;//节点所在scc编号,scc总数;
ll sz[maxn];//每个scc的大小
ll in[maxn];
void add_edge(ll u, ll v) {
	e[tot_edge].v = v;
	e[tot_edge].nx = head[u];
	head[u] = tot_edge++;
}
void solve() {
	ll N, M; std::cin >> N >> M;
	std::fill(head + 1, head + 1 + N, -1);
	vector<ll>x(M + 5), y(M + 5);
	for (ll i = 1; i <= M; i++) {
		std::cin >> x[i] >> y[i];
		add_edge(x[i], y[i]);
	}
	function<void(ll)>tarjan = [&](ll u) {
		low[u] = dfn[u] = ++dfncnt;
		s[++tp] = u; in_stack[u] = 1;
		for (ll i = head[u]; i != -1; i = e[i].nx) {
			ll v = e[i].v;
			if (not dfn[v]) {
				tarjan(v);
				low[u] = min(low[u], low[v]);
			} else if (in_stack[v]) {
				low[u] = min(low[u], dfn[v]);
			}
		}
		if (dfn[u] == low[u]) {
			++sc;
			while (s[tp] != u) {
				scc[s[tp]] = sc;
				sz[sc]++;
				in_stack[s[tp]] = 0;
				tp--;
			}
			scc[s[tp]] = sc;
			sz[sc]++;
			in_stack[s[tp]] = 0;
			--tp;
		}
	};
	for (ll i = 1; i <= N; i++) {
		if (not dfn[i]) {
			tarjan(i);
		}
	}
	for (ll i = 1; i <= M; i++) {
		if (scc[x[i]] == scc[y[i]]) {
			continue;
		}
		in[scc[x[i]]]++;
	}
	ll sum = 0, k;
	for (ll i = 1; i <= sc; i++) {
		if (in[i] == 0) {
			sum++; k = i;
		}
	}
	if (sum >= 2) {
		puts("0"); return;
	}
	sum = 0;
	for (ll i = 1; i <= N; i++) {
		if (scc[i] == k)sum++;
	}
	cout << sum << endl;
}
signed main() {
		solve();
}