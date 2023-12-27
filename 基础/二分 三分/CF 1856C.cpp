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
	i64 n, k; std::cin >> n >> k;
	vector<i64>A(n + 1, 0);
	for (i64 i = 1; i <= n; i++) cin >> A[i];
	auto check = [&](i64 x) {
		for (i64 i = 1; i <= n; i++) {
			i64 cur = k, h = x;
			for (i64 j = i; j <= n; j++, h--) {
				if (h <= A[j])return true;
				cur -= h - A[j];
				if (cur < 0)break;
			}
		}
		return false;
	};
	i64 l = *max_element(A.begin() + 1, A.begin() + 1 + n);
	i64 r = 1e10; i64 ans = l;
	while (l <= r) {
		i64 mid = (l + r) >> 1;
		if (check(mid)) {
			l = mid + 1; ans = mid;
		} else r = mid - 1;
	}
	cout << ans << endl;
}
signed main() {
	i64 T; std::cin >> T;
	while (T--)
		solve();
}