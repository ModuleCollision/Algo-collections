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
	i64 n, m, k; std::cin >> n >> m >> k;
	vector dp(n + 5, vector<i64>(k + 5, 0));
	vector pre(n + 5, vector<i64>(k + 5, 0));
	i64 off = 1;
	dp[0][0 + off] = 1;
	pre[0][0 + off] = 1;
	for (i64 j = 1; j <= k; j++)pre[0][j + off] = pre[0][j - 1 + off];
	for (i64 i = 1; i <= n; i++) {
		for (i64 j = i; j <= k; j++) {
			i64 s = min(j, m);
			i64 v = ((pre[i - 1][j - 1 + off] - pre[i - 1][j - s - 1 + off]) % mod + mod) % mod;

			dp[i][j + off] = (dp[i][j + off] % mod + v) % mod;
		}
		for (i64 j = 1; j <= k; j++) {
			pre[i][j + off] = (pre[i][j + off - 1] % mod + dp[i][j + off]) % mod;
		}
	}
	i64 ans = 0;
	for (i64 i = 1; i <= k; i++)ans = (ans % mod + dp[n][i + off]) % mod;
	cout << ans << endl;
}
signed main() {
	solve();
}