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

i64 n, k; char s[maxn];
i64 pre[30];
i64 dp[maxn][maxn];//以i结尾长度为k的序列总数
void solve() {
	std::cin >> n >> k;
	std::cin >> (s + 1);
	dp[0][0] = 1;
	for (i64 i = 1; i <= n; i++) {
		for (i64 j = 0; j <= k; j++) {
			//老套路,先加上前几位的贡献,再考虑当前位的贡献
			dp[i][j] = (dp[i][j] % mod + dp[i - 1][j]) % mod;
			if (j) {
				dp[i][j] = (dp[i][j] % mod + dp[i - 1][j - 1]) % mod;
			}
			if (pre[s[i] - 'a']) {
				//将第i位重复计算的部分去掉
				dp[i][j] = ((dp[i][j] - dp[pre[s[i] - 'a'] - 1][j - 1]) % mod + mod) % mod;//这一部分做了重复贡献
			}
		}
		pre[s[i] - 'a'] = i;
	}
	cout << dp[n][k] % mod << endl;
}
signed main() {
	solve();
}