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

i64 fa[maxn]; i64 sz[maxn];
void solve() {
	i64 n, m; std::cin >> n >> m;
	vector<vector<i64>>tr(n + 1);
	vector<vector<i64>>p(n + 1);
	for (i64 i = 1; i <= n - 1; i++) {
		i64 u, v; std::cin >> u >> v;
		tr[u].push_back(v); tr[v].push_back(u);
	}
	for (i64 i = 1; i <= m; i++) {
		i64 u, v; std::cin >> u >> v;
		p[u].push_back(v); p[v].push_back(u);
	}
	for (i64 i = 1; i <= n; i++)fa[i] = i;
	auto find = [&](i64 x) {
		while (x != fa[x])x = fa[x] = fa[fa[x]];
		return x;
	};
	auto merge = [&](i64 a, i64 b) {
		i64 x = find(a), y = find(b);
		if (x == y)return;
		fa[x] = y; sz[y] += sz[x];
	};
	vector<i64>f(n + 5, 0);
	vector<i64>dep(n + 5); vector<vector<i64>>ws;
	dep[1] = 1;
	auto bfs = [&]() {
		deque<i64>q; q.push_back(1);
		while (q.size()) {
			i64 sz = q.size();
			vector<i64>lay;
			for (i64 i = 0; i < sz; i++) {
				auto cur = q.front();
				q.pop_front();
				lay.push_back(cur);
				for (auto v : tr[cur]) {
					if (dep[v])continue;
					dep[v] = dep[cur] + 1;
					f[v] = cur;
					q.push_back(v);
				}
			}
			ws.push_back(lay);
		}
	};
	bfs();
	vector<i64>dp(n + 5, 0);
	for (i64 i = ws.size() - 1; i >= 0; i--) {
		if (not ws[i].size())continue;
		auto &lay = ws[i];
		for (auto u : ws[i]) {
			if (tr[u].size() == 1) {
				dp[u] = 1; continue;
			}
			for (auto v : tr[u]) {
				if (v == f[u])continue;
				dp[u] = (dp[u] % mod + dp[v]) % mod;
			}
		}
		for (auto u : lay) {
			sz[u] = dp[u] % mod;
		}
		for (auto u : lay) {
			for (auto v : p[u])merge(u, v);
		}
		for (auto u : lay) {
			dp[u] = sz[find(u)] % mod;
		}
	}
	cout << dp[1] % mod << endl;
}
signed main() {
	solve();
}