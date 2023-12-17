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

vector<i64>tr[maxn]; i64 n, x, y;
i64 dp[maxn][2];
void solve() {
	std::cin >> n >> x >> y;
	for (i64 i = 1; i <= n - 1; i++) {
		i64 u, v; std::cin >> u >> v;
		tr[u].push_back(v); tr[v].push_back(u);
	}
	auto inv = [&](i64 a) {
		i64 ret = 1, b = mod - 2;
		while (b) {
			if (b & 1) {
				ret = ret * a % mod;
			}
			a = a * a % mod;
			b >>= 1;
		}
		return ret;
	};
	function<void(i64, i64)>dfs = [&](i64 u, i64 f) {
		dp[u][0] = x, dp[u][1] = y;
		for (auto v : tr[u]) {
			if (v == f)continue;
			dfs(v, u);
			dp[u][0] = (dp[u][0] % mod * (dp[v][0] % mod + dp[v][1]) % mod) % mod;
			dp[u][1] = (dp[u][1] % mod * (dp[v][0] % mod + dp[v][1] % mod * (y - 1) % mod * inv(y) % mod) % mod) % mod;
		}
		return;
	};
	dfs(1, 0);
	cout << (dp[1][0] % mod + dp[1][1]) % mod << endl;
}
signed main() {
	solve();
}