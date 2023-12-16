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
	 i64 n; std::cin >> n;
	vector<vector<pair< i64,  i64>>>tr(n + 5);
	for ( i64 i = 1; i <= n - 1; i++) {
		 i64 u, v; std::cin >> u >> v;
		tr[u].push_back({v, i});
		tr[v].push_back({u, i});
	}
	 i64 ans = 0;
	auto bfs = [&]() {
		queue<array< i64, 3>>q;
		q.push({1, 0, 1});
		vector<bool>vis(n + 5, 0); vis[1] = 1;
		while (q.size()) {
			auto [u, i1, s1] = q.front(); q.pop();
			ans = max(ans, s1);
			for (auto [v, i2] : tr[u]) {
				if (vis[v])continue;
				vis[v] = 1;
				if (i2 >= i1) {
					q.push({v, i2, s1});
				} else {
					q.push({v, i2, s1 + 1});
				}
			}
		}
	};
	bfs();
	cout << ans << endl;
}
signed main() {
	 i64 T; std::cin >> T;
	while (T--)
		solve();
}