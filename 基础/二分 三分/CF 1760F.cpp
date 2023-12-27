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
	vector<i64>A(n + 5, 0);
	i64 c, d; std::cin >> c >> d;
	for (i64 i = 1; i <= n; i++) {
		std::cin >> A[i];
	}
	std::sort(A.begin() + 1, A.begin() + 1 + n, [&](i64 x, i64 y)->bool{
		return x > y;
	});
	for (i64 i = 1; i <= n; i++) {
		A[i] += A[i - 1];
	}
	if (A[min(d, n)] >= c) {
		puts("Infinity"); return;
	}
	i64 l = 1, r = 1e12;
	auto check = [&](i64 mid) {
		i64 ret = 0;
		i64 rc = min(n, mid);
		ret += d / mid * A[rc];
		i64 re = d % mid;
		rc = min(re, n);
		ret += A[rc];
		return ret >= c;
	};
	i64 ans = 0;
	while (l <= r) {
		i64 mid = (l + r) >> 1;
		if (check(mid)) {
			l = mid + 1; ans = mid;
		} else {
			r = mid - 1;
		}
	}
	/*while (l < r) {
		i64 mid = (l + r + 1) >> 1;
		if (check(mid)) {
			l = mid;
		} else {
			r = mid - 1;
		}
	}*/
	//两种二分都要写
	if (not ans) {
		puts("Impossible"); return;
	}
	cout << ans - 1 << endl;
}
signed main() {
	i64 T; std::cin >> T;
	while (T--)solve();
}
