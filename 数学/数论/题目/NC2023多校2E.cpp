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
	i64 x; std::cin >> x; i64 s = x;
	string xx = "";
	while (s) {
		xx += ('0' + (s % 10));
		s /= 10;
	}
	reverse(xx.begin(), xx.end());
	auto ksm = [&](i64 a, i64 b) {
		i64 ret = 1;
		while (b) {
			if (b & 1)ret = ret * a;
			a = a * a;
			b >>= 1;
		}
		return ret;
	};
	for (i64 k = x, cnt = 0; k <= 1e18; k *= 10, cnt++) {
		i64 f = (k + (10, cnt));
		i64 k1 = sqrt(k); i64 k2 = sqrt(f);
		for (i64 j = k1; j <= (k2 + 1); j++) {
			i64 w = j * j;
			string tmp = "";
			while (w) {
				tmp += ('0' + (w % 10));
				w /= 10;
			}
			reverse(tmp.begin(), tmp.end());
			if (tmp.substr(0, xx.length()) == xx) {
				cout << j << endl; return;
			}
		}
	}
	puts("-1"); return;
}
signed main() {
	i64 T; std::cin >> T;
	while (T--)
		solve();
}