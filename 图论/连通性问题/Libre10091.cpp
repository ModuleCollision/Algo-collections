/*Tarjan缩点求SCC*/
#include<bits/extc++.h>

using i8 = signed char;
using u8 = unsigned char;
using i16 = signed short int;
using u16 = unsigned short int;
using i32 = signed int;
using u32 = unsigned int;
using f32 = float;
using i64 = signed long long;
using u64 = unsigned long long;
using f64 = double;
using i128 = __int128_t;
using u128 = __uint128_t;
using f128 = long double;
using namespace std;

constexpr i64 mod = 998244353;
constexpr i64 maxn = 4e6 + 5;
constexpr i64 inf = 0x3f3f3f3f3f3f3f3f;

struct edge {
	i64 u; i64 v; i64 nx;
} e[maxn];
i64 head[maxn]; i64 tot_edge = 0;
i64 dfn[maxn], low[maxn], dfncnt, s[maxn], in_stack[maxn], tp;
i64 scc[maxn], sc;//节点所在scc编号,scc总数;
i64 sz[maxn];//每个scc的大小
i64 in[maxn];
void add_edge(i64 u, i64 v) {
	e[tot_edge].v = v;
	e[tot_edge].nx = head[u];
	head[u] = tot_edge++;
}
void solve() {
	i64 N, M; std::cin >> N >> M;
	std::fill(head + 1, head + 1 + N, -1);
	vector<i64>x(M + 5), y(M + 5);
	for (i64 i = 1; i <= M; i++) {
		std::cin >> x[i] >> y[i];
		add_edge(x[i], y[i]);
	}
	function<void(i64)>tarjan = [&](i64 u) {
		low[u] = dfn[u] = ++dfncnt;
		s[++tp] = u; in_stack[u] = 1;
		for (i64 i = head[u]; i != -1; i = e[i].nx) {
			i64 v = e[i].v;
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
	for (i64 i = 1; i <= N; i++) {
		if (not dfn[i]) {
			tarjan(i);
		}
	}
	for (i64 i = 1; i <= M; i++) {
		if (scc[x[i]] == scc[y[i]]) {
			continue;
		}
		in[scc[x[i]]]++;
	}
	i64 sum = 0, k;
	for (i64 i = 1; i <= sc; i++) {
		if (in[i] == 0) {
			sum++; k = i;
		}
	}
	if (sum >= 2) {
		puts("0"); return;
	}
	sum = 0;
	for (i64 i = 1; i <= N; i++) {
		if (scc[i] == k)sum++;
	}
	cout << sum << endl;
}
signed main() {
		solve();
}