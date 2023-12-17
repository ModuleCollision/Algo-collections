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
	i64 N; std::cin >> N;
	vector<i64>c(N + 5, 0);
	vector<vector<i64>>tr(N + 5);
	vector<vector<i64>>dp(N + 5, vector<i64>(4, 0));
	for (i64 i = 2; i <= N; i++) {
		i64 p; std::cin >> p; p++;
		tr[p].push_back(i);
	}
	for (i64 i = 1; i <= N; i++)cin >> c[i];
	auto inv = [&](i64 x) {
		i64 ret = 1; i64 b = mod - 2;
		while (b) {
			if (b & 1)ret = ret * x % mod;
			x = x * x % mod;
			b >>= 1;
		}
		return ret;
	};
	function<void(i64, i64)>dfs = [&](i64 u, i64 f) {
		if (c[u] == 0) {
			dp[u][0] = 1; dp[u][1] = 0;
			for (auto v : tr[u]) {
				if (v == f)continue;
				dfs(v, u);
				dp[u][0] = (dp[u][0] % mod) * (dp[v][1] % mod + dp[v][0]) % mod;
			}
		} else {
			dp[u][0] = 0; dp[u][1] = 1;
			for (auto v : tr[u]) {
				if (v == f)continue;
				dfs(v, u);
				dp[u][1] = (dp[u][1] % mod) * (dp[v][0] % mod + dp[v][1] % mod) % mod;
			}
			for (auto v : tr[u]) {
				if (v == f)continue;
				i64 k = inv((dp[v][0] % mod + dp[v][1]) % mod) % mod;
				dp[u][0] = (dp[u][0] % mod + dp[v][0] % mod * dp[u][1] % mod * k % mod) % mod;
			}
		}
	};
	dfs(1, 1);
	cout << dp[1][0] << endl;
}
signed main() {
	solve();
}
