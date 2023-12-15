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
	vector<i64>b = {2, 3, 5};
	std::map<i64, i64>cnt;
	for (i64 i = 0; i < 3; i++) {
		if (n % b[i] == 0) {
			i64 k = 0;
			while (n % b[i] == 0) {
				n /= b[i]; k++;
			}
			cnt[b[i]] = k;
		}
	}
	auto inv = [&](i64 x) {
		i64 b = mod - 2; i64 ret = 1;
		while (b) {
			if (b & 1)ret = ret * x % mod;
			x = x * x % mod;
			b >>= 1;
		}
		return ret;
	};
	i64 d = inv(5);
	i64 x = cnt[2], y = cnt[3], z = cnt[5];
	i64 dp[x + 5][y + 5][z + 5];
	for (i64 i = 0; i <= x; i++) {
		for (i64 j = 0; j <= y; j++) {
			for (i64 k = 0; k <= z; k++)dp[i][j][k] = 0;
		}
	}
	if (n != 1) {
		puts("0"); return;
	}
	dp[0][0][0] = 1;
	for (i64 i = 0; i <= x; i++) {
		for (i64 j = 0; j <= y; j++) {
			for (i64 k = 0; k <= z; k++) {
				if (i + 1 <= x)
					dp[i + 1][j][k] = (dp[i + 1][j][k] % mod + dp[i][j][k] % mod * d) % mod;
				if (j + 1 <= y)
					dp[i][j + 1][k] = (dp[i][j + 1][k] % mod + dp[i][j][k] % mod * d) % mod;
				if (k + 1 <= z)
					dp[i][j][k + 1] = (dp[i][j][k + 1] % mod + dp[i][j][k] % mod * d) % mod;
				if (i + 2 <= x)
					dp[i + 2][j][k] = (dp[i + 2][j][k] % mod + dp[i][j][k] % mod * d) % mod;
				if (i + 1 <= x and j + 1 <= y)
					dp[i + 1][j + 1][k] = (dp[i + 1][j + 1][k] % mod + dp[i][j][k] % mod * d) % mod;
			}
		}
	}
	cout << dp[x][y][z] % mod << endl;
}
signed main() {
	solve();
}