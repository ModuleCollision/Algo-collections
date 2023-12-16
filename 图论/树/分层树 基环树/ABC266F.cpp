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

bool mp[maxn]; i64 n; vector<i64>tr[maxn];
i64 fa[maxn], dep[maxn]; bool vis[maxn];
i64 c[maxn];
/*适用于无向图的DFS生成树 求环*/
void dfs1(i64 u, i64 f) {
	dep[u] = dep[f] + 1;
	fa[u] = f;
	vis[u] = true;
	for (auto v : tr[u]) {
		if (not vis[v]) {
			dfs1(v, u);
		} else if (v != f) {
			if (dep[v] < dep[u]) {
				for (i64 j = u; j != v; j = fa[j]) {
					mp[j] = true;
				}
				mp[v] = true;
				return;
			}
		}
	}
	//vis[u] = false;
	//vis[u] = true 代表向下递归中, vis[u] = false 代表回溯完成
	return;
}
void solve() {
	std::cin >> n;
	for (i64 i = 1; i <= n; i++) {
		i64 u, v; std::cin >> u >> v;
		tr[u].push_back(v); tr[v].push_back(u);
	}
	dfs1(1, 0);//dfs生成树
	auto bfs = [&](i64 t) {
		queue<i64>q;
		q.push(t); c[t] = t;
		while (q.size()) {
			auto u = q.front(); q.pop();
			for (auto v : tr[u]) {
				if (c[v] or mp[v])continue;
				c[v] = t; q.push(v);
			}
		}
	};
	for (i64 i = 1; i <= n; i++) {
		if (mp[i])bfs(i);
	}
	i64 q; std::cin >> q;
	while (q--) {
		i64 u, v; std::cin >> u >> v;
		if (c[u] == c[v]) {
			puts("Yes");
		} else puts("No");
	}
}
signed main() {
	solve();
}