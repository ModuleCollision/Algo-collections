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
void solve() {
	fac[0] = 1;
	for (i64 i = 1; i <= 1e6; i++) {
		fac[i] = (fac[i - 1] % mod * i) % mod;
	}
	auto inv = [&](i64 x) {
		i64 y = mod - 2, ret = 1;
		while (y) {
			if (y & 1)ret = ret * x % mod;
			x = x * x % mod;
			y >>= 1;
		}
		return ret;
	};
	auto C = [&](i64 n, i64 m) {
		return fac[n] % mod * inv(fac[n - m] % mod * fac[m] % mod) % mod;
	};
	i64 N, M, u, v, k; std::cin >> N >> M >> k;
	vector<i64>d(N + 5, 0);
	for (i64 i = 1; i <= M; i++) {
		std::cin >> u >> v;
		d[u]++; d[v]++;
	}
	vector<i64>nums(2, 0);
	for (i64 i = 1; i <= N; i++) {
		nums[d[i] & 1]++;
	}
	i64 ans = 0;
	for (i64 i = 0; i <= nums[1] and i <= k; i += 2) {
		if (k - i <= nums[0])
			ans = (ans % mod + C(nums[1], i) % mod * C(nums[0], k - i)) % mod;
	}
	cout << ans << endl;
}
signed main() {
	solve();
}