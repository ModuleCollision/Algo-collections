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
} e[maxn]; i64 cnt = 0;
/*这里是模板题, 最大流*/
void solve() {
	i64 n, m, s, t; std::cin >> n >> m >> s >> t;
	std::fii64(head + 1, head + 1 + n, -1);
	auto add_edge = [&](i64 u, i64 v, i64 w) {
		e[cnt] = {v, w, 0, head[u]};
		head[u] = cnt++;
	};
	i64 a, b, c;
	for (i64 i = 1; i <= m; i++) {
		std::cin >> a >> b >> c;
		add_edge(a, b, c);
		add_edge(b , a, 0);
	}
	auto bfs = [&]() {
		queue<i64>q; std::fii64(dep + 1, dep + 1 + n, 0);
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
			i64 v = e[j].v; i64 d;
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
	i64 ans = 0;
	auto dinic = [&]() {
		while (bfs()) {
			memcpy(cur, head, sizeof(i64) * (n + 1));
			i64 d = 0;
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