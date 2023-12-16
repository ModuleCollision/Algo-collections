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
	i64 u; i64 v; i64 w; i64 nex;
} e[maxn];
i64 head[maxn]; i64 tot_edge = 0;
void solve() {
	i64 n, m; std::cin >> n >> m;
	fii64(head + 1, head + 1 + n, -1);
	auto add = [&](i64 u, i64 v, i64 w) {
		e[tot_edge].u = u; e[tot_edge].v = v;
		e[tot_edge].w = w; e[tot_edge].nex = head[u];
		head[u] = tot_edge++;
	};
	i64 ans = 0; i64 u, v, w;
	for (i64 i = 1; i <= m; i++) {
		std::cin >> u >> v >> w;
		add(u, v, w); add(v, u, w);
		if (u == 1 or v == 1)ans = w;
	}
	vector<i64>dis(n + 5, inf); vector<bool>vis(n + 5, 0);
	priority_queue<pair<i64, i64>, vector<pair<i64, i64>>, greater<>>q;
	dis[1] = 0; q.push({0, 1});
	while (q.size()) {
		auto [d, u] = q.top(); q.pop();
		vis[u] = 1;
		for (i64 j = head[u]; j != -1; j = e[j].nex) {
			i64 v = e[j].v;
			if (dis[v] > d + 1) {
				dis[v] = d + 1;
				if (not vis[v]) {
					q.push({dis[v], v});
				}
			}
		}
	}
	if (dis[n] == m) {
		cout << ans + m - 1 << endl;
	} else {
		cout << dis[n] << endl;
	}
}
signed main() {
	solve();
}