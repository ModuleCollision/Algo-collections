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

i64 dfn[maxn]; i64 rk[maxn]; i64 sz[maxn]; i64 cnt = 0;
i64 d[maxn];
void solve() {
	i64 n, q; std::cin >> n >> q;
	vector<vector<i64>>tr(n + 1);
	for (i64 i = 1; i <= n - 1; i++) {
		i64 u, v; std::cin >> u >> v;
		tr[u].push_back(v); tr[v].push_back(u);
	}
	function<void(i64, i64)>dfs = [&](i64 u, i64 f) {
		++cnt; dfn[u] = cnt; rk[cnt] = u; sz[u] = 1;
		for (auto v : tr[u]) {
			if (v == f)continue;
			dfs(v, u);
			sz[u] += sz[v];
		}
	};
	dfs(1, 0);
	while (q--) {
		i64 p, x; std::cin >> p >> x;
		d[dfn[p]] += x;
		d[dfn[p] + sz[p]] -= x;
	}
	for (i64 i = 1; i <= n; i++)d[i] += d[i - 1];
	for (i64 i = 1; i <= n; i++)cout << d[dfn[i]] << " ";
}
signed main() {
	solve();
}