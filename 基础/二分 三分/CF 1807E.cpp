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

i64 n;
void solve() {
	std::cin >> n;
	vector<i64>pre(n + 5, 0);
	for (i64 i = 1; i <= n; i++) {
		std::cin >> pre[i];
		pre[i] += pre[i - 1];
	}
	i64 l = 1, r = n, ans;
	while (l < r) {
		i64 mid = (l + r) >> 1;
		cout << "? " << (mid - l + 1) << endl;
		for (i64 i = l; i <= mid; i++) {
			cout << i << " ";
		}
		cout << endl << flush;
		i64 x; std::cin >> x;
		if (x == pre[mid] - pre[l - 1]) {
			l = mid + 1;
		} else {
			r = mid - 1; ans = mid;
		}
	}
	cout << "! " << ans << endl << flush;
}
signed main() {
	i64 T; std::cin >> T;
	while (T--)solve();
}