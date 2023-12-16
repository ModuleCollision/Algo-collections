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
	i64 n, k, m, a, b;
	std::cin >> n >> k >> m >> a >> b;
	i64 ans = 1e15; bool f = 0;
	i64 v = 0;
	if (k == 1) {
		if (n % m) {
			cout << -1 << endl;
		} else {
			cout << 0 << endl;
		}
		return;
	}
	for (i64 s = n;; s /= k) {
		i64 tmp = 0; i64 ct = 0;
		for (i64 ts = s; ts <= 1e18; ts *= k, ct += 1) {
			i64 d = tmp;
			i64 l = ts, r = ts + d;
			i64 p = (l + m - 1) / m * m;
			if (p <= r) {
				f = 1;
				ans = min(ans, ct * a + v);
				break;
			}
			p = (r / m) * m;
			if (p >= l) {
				f = 1; ans = min(ans, ct * a + v);
				break;
			}
			tmp = (tmp) * k + k - 1;
		}
		if (not s)break;
		v += b;
	}
	if (not f) {
		puts("-1"); return;
	}
	cout << ans << endl;
}
signed main() {
	i64 T; std::cin >> T;
	while (T--)
		solve();
}