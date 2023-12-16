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
const f64 eps = 0.0000001;
void solve() {
	i64 v0, x, y;
	std::cin >> v0 >> x >> y;
	auto f = [&](f64 t)->f64{
		return (f64)t + (f64)y / ((f64)v0 + t * x);
	};
	f64 l = 0, r = 1e9;
	while (r - l > eps) {
		f64 mid = (l + r) / 2;
		f64 lmid = mid - eps;
		f64 rmid = mid + eps;
		if (f(lmid) < f(rmid)) {
			r = mid;
		} else l = mid;
	}
	printf("%.8lf", f(l));
}
signed main() {
	solve();
}