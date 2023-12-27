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

//dfs生成树找无向图环
void solve() {
	i64 n, a, b; std::cin >> n >> a >> b;
	vector<vector<i64>>tr(n + 1);
	for (i64 i = 1; i <= n; i++) {
		i64 u, v; std::cin >> u >> v;
		tr[u].push_back(v); tr[v].push_back(u);
	}
	vector<i64>dep(n + 1);
	vector<i64>fa(n + 1); vector<bool>vis(n + 1);
	vector<bool>mp(n + 1);
	vector<i64>c(n + 1);
	function<void(i64, i64)>dfs = [&](i64 u, i64 f) {
		dep[u] = dep[f] + 1;
		fa[u] = f;
		vis[u] = true;
		for (auto v : tr[u]) {
			if (not vis[v])dfs(v, u);
			else if (v != f) {
				if (dep[v] < dep[u]) {
					for (i64 j = u; j != v; j = fa[j]) {
						mp[j] = true;
					}
					mp[v] = true;
					return;
				}
			}
		}
		vis[u] = false;
		return;
	};
	dfs(1, 0);
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
	if (a == b) {
		puts("NO"); return;
	}
	if (mp[b]) {
		puts("YES"); return;
	} else {
		for (i64 i = 1; i <= n; i++)if (mp[i])bfs(i);
		i64 t = c[b];
		vector<i64>dis(n + 1, -1);
		auto bfs2 = [&](i64 u) {
			queue<i64>q; q.push(u); dis[u] = 1;
			while (q.size()) {
				auto u = q.front(); q.pop();
				for (auto v : tr[u]) {
					if (dis[v] != -1)continue;
					dis[v] = dis[u] + 1;
				}
			}
		};
		bfs2(t);
		if (dis[b] >= dis[a])puts("NO");
		else puts("YES");
	}
}
signed main() {
	i64 T; std::cin >> T;
	while (T--)
		solve();
}