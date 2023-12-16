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

i64 head[maxn], cur[maxn]; i64 dep[maxn];
struct edge {
	i64 v, cap; i64 flow; i64 nxt;
} e[200005]; i64 cnt = 0; i64 s, t;
/*此题为求解二分图最大匹配,转换为网络流问题求解*/
void solve() {
	i64 n, m; std::cin >> n >> m;
	std::fii64(head, head + n + 5, -1);
	auto add_edge = [&](i64 u, i64 v, i64 w) {
		e[cnt] = {v, w, 0, head[u]};
		head[u] = cnt++;
	};
	i64 u, v;
	while (cin >> u >> v) {
		add_edge(u, v, 1);
		add_edge(v, u, 0);
		//if (not u or not v)break;
	}
	for (i64 i = 1; i <= m; i++) {
		add_edge(0, i, 1);
		add_edge(i, 0, 0);
	}
	for (i64 i = m + 1; i <= n; i++) {
		add_edge(i, n + 1, 1);
		add_edge(n + 1, i, 0);
	}
	s = 0, t = n + 1;
	auto bfs = [&]() {
		queue<i64>q; for (i64 i = 0; i <= n + 5; i++)dep[i] = 0;
		dep[s] = 1;
		q.push(s);
		while (q.size()) {
			i64 u = q.front(); q.pop();
			for (i64 j = head[u]; j != -1; j = e[j].nxt) {
				i64 v = e[j].v;
				if ((not dep[v]) and (e[j].cap > e[j].flow)) {
					dep[v] = dep[u] + 1;//未曾增广过而且流量存有剩余
					q.push(v);
				}
			}
		}
		return dep[t];
	};
	function<i64(i64 , i64)>dfs = [&](i64 u, i64 flow) {
		if (u == t or (not flow))return flow;
		i64 ret = 0;
		for (i64 j = cur[u]; j != -1; j = e[j].nxt) {
			i64 v = e[j].v;
			if (dep[v] == dep[u] + 1) {
				//到达汇点时的剩余流量回溯至增广路
				i64 d = dfs(v, min(e[j].cap - e[j].flow, flow - ret));
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
	i64 ans = 0;
	auto dinic = [&]() {
		while (bfs()) {
			i64 d = 0;
			memcpy(cur, head, sizeof(i64) * (n + 5));
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