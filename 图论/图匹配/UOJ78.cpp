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

void solve() {
	i64 n, m, e; std::cin >> n >> m >> e;
	vector<i64>pa(n + 5, 0), pb(n + m + 5, 0), vis(n + 5, 0);
	i64 dfn = 0, res = 0;
	vector<vector<i64>>tr(n + 5);
	for (i64 i = 1; i <= e; i++) {
		i64 u, v; std::cin >> u >> v;
		tr[u].push_back(v + n);
	}
	function<bool(i64)>dfs = [&](i64 u) {
		vis[u] = dfn;
		for (auto v : tr[u]) {
			if (not pb[v]) {
				pb[v] = u; pa[u] = v; return true;
			}
		}
		for (auto v : tr[u]) {
			if (vis[pb[v]] != dfn and dfs(pb[v])) {
				pa[u] = v; pb[v] = u; return true;
			}
		}
		return false;
	};
	while (1) {
		dfn++; i64 cnt = 0;
		for (i64 i = 1; i <= n; i++) {
			if ((not pa[i]) and dfs(i))cnt++;
		}
		if (not cnt)break;
		res += cnt;
	}
	cout << res << endl;
	for (i64 i = 1; i <= n; i++) {
		cout << max(0ll, pa[i] - n) << " \n"[i == n];
	}
}
signed main() {
	solve();
}