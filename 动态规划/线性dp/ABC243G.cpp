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

i64 dp[60005];
bool check(i64 x) {
	i64 t = (i64)sqrt(x);
	return (t * t) == x;
}
void pre() {
	dp[1] = 1;
	for (i64 i = 2; i <= 60000; i++) {
		dp[i] += dp[i - 1];
		if (check(i)) dp[i] += dp[(i64)sqrt(i)];
	}
}

signed main() {
	i64 T; std::cin >> T; pre();
	while (T--) {
		i64 n; cin >> n; i64 m = (i64)sqrt(n);
		i64 ans = 0; if (m * m > n)m--;
		for (i64 i = 1; i * i <= m; i++) {
			ans += dp[i] * (m - i * i + 1);
		}
		cout << ans << endl;
	}

}