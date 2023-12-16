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

/*bool cal(i64 x) {
	i64 cnt = 0;
	for (i64 i = 0; i <= 33; i++) {
		if ((x >> i) & 1)cnt++;
	}
	return cnt & 1;
}
void solve(i64 x) {
	i64 ans = 0;
	for (i64 i = 1; i <= x; i++) {
		if (cal(i))ans++;
	}
	cout << x << ":" << ans << endl;
}*/
//打表
void solve() {
	auto get = [&](i64 x) {
		if (x & 1) {
			return x / 2 + 1;
		} else {
			i64 cnt = 0;
			for (i64 i = 0; i <= 33; i++) {
				if ((x >> i) & 1)cnt++;
			}
			if (cnt & 1) {
				return x / 2 + 1;
			} else {
				return x / 2;
			}
		}
	};
	i64 l, r; std::cin >> l >> r;
	cout << get(r) - get(l - 1) << endl;
}
signed main() {
	i64 T; std::cin >> T;
	while (T--)
		solve();
}