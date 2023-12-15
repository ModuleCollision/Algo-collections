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

i64 fac[maxn];
void init() {
	fac[0] = 1;
	for (i64 i = 1; i <= 1e6; i++)fac[i] = (fac[i - 1] % mod * i) % mod;
}
i64 ksm(i64 a, i64 b) {
	i64 ret = 1;
	while (b) {
		if (b & 1)ret = ret * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ret % mod;
}
i64 inv(i64 x) {
	return ksm(x, mod - 2) % mod;
}
i64 comb(i64 n, i64 m) {
	return fac[n] % mod * inv(fac[n - m] % mod * fac[m] % mod) % mod;
}

void solve() {
	init();
	i64 H, W, A, B; std::cin >> H >> W >> A >> B;
	i64 ans = 0;
	for (i64 i = 0; i < W - B; i++) {
		//cout << H - A - 1 + i + B << endl;
		i64 v = comb(H - A - 1 + i + B, B + i) % mod;
		i64 v2 = comb(W - B - i + A - 2, A - 1) % mod;
		ans = (ans % mod + v % mod * v2 % mod) % mod;
	}
	cout << ans % mod << endl;
}
signed main() {
	solve();
}