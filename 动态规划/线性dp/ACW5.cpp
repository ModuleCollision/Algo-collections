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
i64 N, V;
i64 v[maxn], w[maxn], s[maxn];
i64 x[maxn], y[maxn];
i64 dp[maxn], cnt = 0;
/*多重背包的二进制优化*/
void solve() {
	std::cin >> N >> V;
	for (i64 i = 1; i <= N; i++) {
		std::cin >> v[i] >> w[i] >> s[i];
	}
	for (i64 i = 1; i <= N; i++) {
		for (i64 j = 1;; j <<= 1) {
			if (s[i] < j)break;
			s[i] -= j; ++cnt;
			x[cnt] += j * v[i];
			y[cnt] += j * w[i];
		}
		if (s[i]) {
			++cnt; x[cnt] += s[i] * v[i];
			y[cnt] += s[i] * w[i];
		}
		s[i] = 0;
	}
	for (i64 i = 1; i <= cnt; i++) {
		for (i64 j = V; j >= x[i]; j--) {

			dp[j] = max(dp[j], dp[j - x[i]] + y[i]);
		}
	}
	cout << dp[V] << endl;
}
signed main() {
	solve();
}