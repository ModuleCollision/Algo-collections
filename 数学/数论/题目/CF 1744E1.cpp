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
	i64 a, b, c, d; std::cin >> a >> b >> c >> d;
	function<i64(i64, i64)>gcd = [&](i64 a, i64 b) {
		return b == 0 ? a : gcd(b, a % b);
	};
	for (i64 i = a + 1; i <= c; i++) {
		i64 x = i;
		i64 k = a * b / gcd(a * b, x);
		i64 s; if (d % k == 0)s = d;
		else s = d / k * k;
		if (s > b) {
			cout << x << " " << s << endl; return;
		}
	}
	puts("-1 -1"); return;
}
signed main() {
	i64 T; std::cin >> T;
	while (T--) {
		solve();
	}
}