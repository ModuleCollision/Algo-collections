/*最小费用最大流模板*/
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
	i64 v; i64 cap; i64 flow; i64 c; i64 nx;
} e[maxn];
i64 head[maxn], cur[maxn], dis[maxn]; bool vis[maxn];
void solve() {
	i64 n, m, s, t; std::cin >> n >> m >> s >> t;
	std::fill(head + 1, head + 1 + n, -1);
	i64 cnt = 0;
	auto add_edge = [&](i64 u, i64 v, i64 w, i64 c) {
		e[cnt].flow = 0;
		e[cnt].v = v; e[cnt].cap = w; e[cnt].c = c; e[cnt].nx = head[u];
		head[u] = cnt++;
	};
	while (m--) {
		i64 u, v, w, c; std::cin >> u >> v >> w >> c;
		add_edge(u, v, w, c);
		add_edge(v, u, 0, -c);
	}
	auto spfa = [&](i64 s, i64 t) {
		std::fill(dis + 1, dis + 1 + n, inf);
		std::queue<i64>q;
		q.push(s); dis[s] = 0; vis[s] = 1;
		while (q.size()) {
			i64 u = q.front();
			q.pop(); vis[u] = 0;
			for (i64 i = head[u]; i != -1; i = e[i].nx) {
				i64 v = e[i].v;
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
	i64 ret = 0;
	function<i64(i64 , i64, i64)>dfs = [&](i64 u, i64 t, i64 flow) {
		if (u == t)return flow;
		vis[u] = 1;
		i64 ans = 0;
		for (i64 i = cur[u]; i != -1 and ans < flow; i = e[i].nx) {
			i64 v = e[i].v;
			if (not vis[v] and e[i].cap - e[i].flow and dis[v] == dis[u] + e[i].c) {
				i64 x = dfs(v, t, min(e[i].cap - e[i].flow, flow - ans));
				if (x) {
					ret += x * e[i].c; e[i].flow += x; e[i ^ 1].flow -= x;
					ans += x;
				}
			}
		}
		vis[u] = 0;
		return ans;
	};
	auto mcmf = [&](i64 s, i64 t) {
		i64 ans = 0;
		while (spfa(s, t)) {
			memcpy(cur, head, sizeof(i64) * (n + 1));
			i64 x; while (x = dfs(s, t, inf)) {
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