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
	vector<i64>A(n + 1, 0); vector<i64>pre(n + 1, 0);
	for (i64 i = 1; i <= n; i++)cin >> A[i];
	for (i64 i = 1; i <= n; i++) {
		pre[i] = A[i] ^ pre[i - 1];
	}
	i64 ans = 0;
	auto ksm = [&](i64 x, i64 y) {
		i64 ret = 1;
		while (y) {
			if (y & 1)ret = ret * x % mod;
			x = x * x % mod;
			y >>= 1;
		}
		return ret % mod;
	};
	for (i64 i = 0; i <= 33; i++) {
		vector<i64>cnt(2, 0); vector<i64>p(2, 0);
		for (i64 j = 0; j <= n; j++) {
			i64 cur = ((pre[j] >> i) & 1);
			i64 d = cnt[cur ^ 1] % mod * j % mod;
			d = ((d - p[cur ^ 1]) % mod + mod) % mod;
			ans = (ans % mod + d % mod * ksm(2, i)) % mod;
			cnt[cur]++; p[cur] += j;
		}
	}
	cout << ans % mod << endl;
}
signed main() {
	solve();
}