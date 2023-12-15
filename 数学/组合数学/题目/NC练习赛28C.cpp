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

vector<pair<i64, i64>>tr[maxn];
i64 N, dt[2];
void solve() {
	std::cin >> N;
	i64 u, v, w;
	for (i64 i = 1; i <= N - 1; i++) {
		std::cin >> u >> v >> w;
		tr[u].push_back({v, w});
		tr[v].push_back({u, w});
	}
	function<void(i64, i64, i64)>dfs = [&](i64 u, i64 f, i64 d) {
		for (auto [v, w] : tr[u]) {
			if (v == f)continue;
			dt[d]++;
			dfs(v, u, (d + w) % 2);
		}
	};
	dfs(1, 0, 0);
	i64 ans = (dt[0] * dt[0] * dt[0] + dt[1] * dt[1] * dt[1]);
	cout << ans << endl;
}
signed main() {
	solve();
}