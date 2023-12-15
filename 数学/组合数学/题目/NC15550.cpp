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

i64 inv[maxn], invfac[maxn], fac[maxn];
void pre() {
	inv[0] = invfac[0] = 1;
	inv[1] = invfac[1] = 1;
	fac[1] = 1;
	for (i64 i = 2; i <= 1e6; i++) {
		inv[i] = (mod - mod / i) * inv[mod % i] % mod;
		invfac[i] = invfac[i - 1] * inv[i] % mod;
		fac[i] = fac[i - 1] * i % mod;//递推逆元以及阶乘逆元, (虽然不常用)
	}
}
i64 C(i64 n, i64 m) {
	return fac[n] * invfac[m] % mod * invfac[n - m] % mod;
}
//可以打表确定规律
signed main() {
	pre();
	i64 m, x, y, p;
	while (std::cin >> m >> x >> y >> p) {
		if (x == 1 or y == 0) {
			cout << p << endl;
			continue;
		}
		i64 ans = 0;
		for (i64 i = 0; i <= y; i++) {
			ans = (ans + C(x - 1, i)) % mod;
		}
		ans = ans * p % mod;
		cout << ans << endl;
	}
	return 0;
}