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
	i64 l = 0, r = 1e7;
	while (l < r) {
		i64 mid = (l + r) >> 1;
		if (mid * (mid + 1) / 2 >= n) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	//cout << r << endl;
	i64 tot = (1 + r) * r / 2;
	auto sum = [&](i64 x) {
		return x * (x + 1) * (2 * x + 1) / 6;
	};
	i64 ss = sum(tot);
	i64 l1 = n - 1 - (r - 1) * r / 2;
	i64 l2 = tot - n;
	i64 ans1 = 0, ans2 = 0;
	i64 cur = n - 1; i64 tmp = r;
	//cout << "#" << l1 << " " << l2 << endl;
	for (i64 i = l1; i >= 1; i--) {
		i64 len = i;
		ans1 += sum(cur) - sum(cur - len);
		cur -= tmp; tmp--;
	}
	tmp = r; cur = tot;
	for (i64 i = l2; i >= 1; i--) {
		i64 len = i;
		ans2 += sum(cur) - sum(cur - len);
		cur -= tmp;
		tmp--;
	}
	cout << ss - ans1 - ans2 << endl;
}
signed main() {
	i64 T; std::cin >> T;
	while (T--)solve();
}