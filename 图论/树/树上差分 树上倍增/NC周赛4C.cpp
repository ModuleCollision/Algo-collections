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
	 i64 n, l, r; std::cin >> n >> l >> r;
	vector<vector< i64>>tr(n + 1);
	string w; std::cin >> w;
	w = " " + w;
	 i64 ans = 0;
	for ( i64 i = 1; i <= n - 1; i++) {
		 i64 u, v; cin >> u >> v; tr[u].push_back(v);
		tr[v].push_back(u);
	}
	function<void( i64,  i64,  i64)>dfs = [&]( i64 u,  i64 f,  i64 cur) {
		for (auto v : tr[u]) {
			if (v == f)continue;
			 i64 y = (cur << 1) + w[v] - '0';
			if (y <= r) {
				if (y >= l)ans++;
				dfs(v, u, y);
			}
		}
	};
	for ( i64 i = 1; i <= n; i++) {
		dfs(i, 0, w[i] - '0');
	}
	cout << ans << endl;
}
signed main() {
	solve();
}