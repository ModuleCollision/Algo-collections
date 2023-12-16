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

i64 n, m;

void solve() {
	std::cin >> n >> m;
	vector<i64>a(n + 5, 0), b(n + 5, 0), pre(n + 5, 0);
	for (i64 i = 1; i <= n; i++) {
		std::cin >> a[i]; b[i] = a[i];
	}
	std::sort(b.begin() + 1, b.begin() + 1 + n);
	for (i64 i = 1; i <= n; i++) {
		pre[i] = pre[i - 1] + b[i];
	}
	auto check = [&](i64 mid)->bool{
		if (mid == n + 1) {
			return true;
		}
		if (pre[n + 1 - mid] <= m) {
			return true;
		}
		if (pre[n - mid] > m) {
			return false;
		}
		i64 t = m - pre[n - mid];
		t += b[n - mid];
		if (t >= a[n - mid + 1]) {
			return true;
		} else{
			return false;
		}
	};
	i64 L = 1, R = n + 1, ans = n + 1;//二分最小值时把ans设为上界,最大值亦然
	while (L <= R) {
		i64 mid = (L + R) >> 1;
		if (check(mid)) {
			ans = mid;
			R = mid - 1;
		} else {
			L = mid + 1;
		}
	}
	cout << ans << endl;
}
signed main() {
	i64 T; std::cin >> T;
	while (T--) {
		solve();
	}
}