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
 i64 co[maxn]; vector< i64>tr[maxn];
 i64 sz[5];  i64 N, M, cnt = 0;
void solve() {
	 i64 n, m, k; std::cin >> n >> m >> k;
	vector<vector<pair< i64,  i64>>>tr(n + 5 + m);
	while (k--) {
		 i64 x1, y1, x2, y2;
		std::cin >> x1 >> y1 >> x2 >> y2;
		tr[min(x1, x2)].push_back({n + min(y1 , y2), (x1 + y1 != x2 + y2)});
		tr[n + min(y1, y2)].push_back({min(x1, x2), (x1 + y1 != x2 + y2)});
	}
	vector< i64>co(n + m + 5, -1);
	function<bool( i64)>dfs = [&]( i64 u) {
		for (auto [v, e] : tr[u]) {
			if (co[v] != -1) {
				if (co[v] != co[u] ^ e)return false;
			} else {
				co[v] = co[u] ^ e;
				bool f = dfs(v);
				if (not f)return false;
			}
		}
		return true;
	};
	for ( i64 i = 1; i <= n + m; i++) {
		if (co[i] == -1) {
			co[i] = 0; bool f = dfs(i);
			if (not f) {
				puts("NO"); return;
			}
		}
	}
	puts("YES");
}

signed main() {
	 i64 T; std::cin >> T;
	while (T--)
		solve();
}


