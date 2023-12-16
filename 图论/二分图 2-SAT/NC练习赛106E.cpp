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
	i64 n, m; std::cin >> n >> m;
	vector<i64>co(n + 5, 0);
	if (n > 1000) {
		puts("YES"); return;
	}
	vector<vector<bool>>del(n + 5, vector<bool>(n + 5, false));
	for (i64 i = 1; i <= m; i++) {
		i64 u, v; std::cin >> u >> v; del[u][v] = del[v][u] = 1;
	}
	function<bool(i64)>dfs = [&](i64 u) {
		for (i64 v = 1; v <= n; v++) {
			if (v == u or del[u][v])continue;
			if (co[v] and co[u] == co[v]) {
				return false;
			} else if (not co[v]) {
				co[v] = 3 - co[u];
				bool f = dfs(v);
				if (not f)return false;
			}
		}
		return true;
	};
	for (i64 i = 1; i <= n; i++) {
		if (not co[i]) {
			co[i] = 1; bool f = dfs(i);
			if (not f) {
				puts("YES"); return;
			}
		}
	}
	puts("NO");
}
signed main() {
	i64 T; std::cin >> T;
	while (T--)solve();
}