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

i64 N, dp[maxn][2];
i64 u, v; vector<i64>tr[maxn];
void solve() {
	for (i64 i = 1; i <= N; i++) {
		tr[i].clear();
	}
	memset(dp, 0, sizeof(dp));
	for (i64 i = 1; i <= N - 1; i++) {
		std::cin >> u >> v;
		tr[u].push_back(v);
		tr[v].push_back(u);
	}
	function<void(i64, i64)>dfs = [&](i64 u, i64 f) {
		dp[u][0] = 0; dp[u][1] = 1;
		for (auto v : tr[u]) {
			if (v == f)continue;
			dfs(v, u);
			dp[u][1] += min(dp[v][1], dp[v][0]);
			dp[u][0] += dp[v][1];
		}
	};
	dfs(1, 1);
	cout << min(dp[1][1], dp[1][0]) << endl;
}
signed main() {
	while (cin >> N)solve();
}