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
	i64 l = 0, r = 63;//计算总共有几层
	while (l < r) {
		i64 mid = (l + r) >> 1;
		if ((1i64 << mid) - 1 >= n)r = mid;
		else l = mid + 1;
	}
	auto lowbit = [&](i64 x) {
		return x & -x;
	};
	auto ksm = [&](i64 x, i64 y) {
		i64 ret = 1;
		while (y) {
			if (y & 1)ret = ret * x % mod;
			x = x * x % mod;
			y >>= 1;
		}
		return ret % mod;
	};
	auto inv = [&](i64 x) {
		return ksm(x, mod - 2) % mod;
	};
	if (n + 1 == lowbit(n + 1)) {
		i64 ans = 0;
		for (i64 i = 1; i <= r; i++) {
			ans = (ans % mod + ksm(2, i)) % mod;
		}
		ans = ((ans - r) % mod + mod) % mod;
		cout << ans << endl;
	} else {
		i64 p = r - 1; i64 ps = (1i64 << (p)) - 1;//头顶的满二叉树
		i64 ans = 0;
		for (i64 i = 1; i <= p; i++) {
			ans = (ans % mod + ksm(2, i)) % mod;
		}
		ans = ((ans - p) % mod + mod) % mod;
		i64 d = ((n - ps) % mod + mod) % mod; ans = (ans % mod + d) % mod; //统计一个的
		while (d) {
			ans = (ans % mod + d) % mod; d /= 2;
		}
		cout << ans << endl;
	}
}
signed main() {
	i64 T; std::cin >> T;
	while (T--)
		solve();
}