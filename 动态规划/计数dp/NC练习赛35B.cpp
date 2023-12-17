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

i64 dp[maxn][2], N, A, B;
//长度为i结尾为元/辅音的总单词数
void solve() {
	std::cin >> N >> A >> B;
	memset(dp, 0, sizeof(dp));
	dp[0][0] = dp[0][1] = 1;
	auto ksm = [&](i64 x, i64 y) {
		i64 ret = 1;
		while (y) {
			if (y & 1) {
				ret = ret * x % mod;
			}
			x = x * x % mod;
			y >>= 1;
		}
		return ret;
	}; i64 ans = 0;
	for (i64 i = 1; i <= N; i++) {
		for (i64 j = i - 1; j >= max(0i64, i - A); j--) {
			dp[i][0] = (dp[i][0] % mod + dp[j][1] % mod * ksm(5, i - j)) % mod;
		}
		for (i64 j = i - 1; j >= max(0i64, i - B); j--) {
			dp[i][1] = (dp[i][1] % mod + dp[j][0] % mod * ksm(21, i - j)) % mod;
		}
		ans = (ans % mod + dp[i][0]) % mod;
		ans = (ans % mod + dp[i][1]) % mod;
	}
	cout << ans << endl;
}
signed main() {
	i64 T; std::cin >> T;
	while (T--)solve();
}

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
	i64 N, A, B; std::cin >> N >> A >> B;
	vector dp(N + 5, vector (55, array<i64, 2> {0, 0}));
	dp[1][1][0] = 5;
	dp[1][1][1] = 21;//0 : 元音, 1 : 辅音
	//以元音辅音结尾, 有几个元音 / 辅音的单词总数
	for (i64 i = 2; i <= N; i++) {
		for (i64 j = 1; j <= A; j++) {
			dp[i][1][1] = (dp[i][1][1] % mod + dp[i - 1][j][0] % mod * 21) % mod;
		}
		for (i64 j = 2; j <= B; j++) {
			dp[i][j][1] = (dp[i][j][1] % mod + dp[i - 1][j - 1][1] % mod * 21) % mod;
		}
		for (i64 j = 1; j <= B; j++) {
			dp[i][1][0] = (dp[i][1][0] % mod + dp[i - 1][j][1] % mod * 5) % mod;
		}
		for (i64 j = 2; j <= A; j++) {
			dp[i][j][0] = (dp[i][j][0] % mod + dp[i - 1][j - 1][0] % mod * 5) % mod;
		}
	}
	i64 ans = 0;
	for (i64 i = 1; i <= N; i++)
		for (i64 j = 1; j <= A; j++)ans = (ans % mod + dp[i][j][0]) % mod;
	for (i64 i = 1; i <= N; i++)
		for (i64 j = 1; j <= B; j++)ans = (ans % mod + dp[i][j][1]) % mod;
	cout << ans << endl;
}
signed main() {
	i64 T; std::cin >> T;
	while (T--)solve();
}