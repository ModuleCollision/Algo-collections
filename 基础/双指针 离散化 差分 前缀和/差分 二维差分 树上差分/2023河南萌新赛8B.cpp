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

i64 d1[maxn], d2[maxn];
void solve() {
	i64 n; std::cin >> n;
	for ( i64 i = 1; i <= n; i++) {
		i64 l1, r1, l2, r2;
		cin >> l1 >> r1 >> l2 >> r2;
		++d1[l1]; --d1[r1 + 1];
		++d1[l2]; --d1[r2 + 1];
		i64 l = max(l1, l2);  i64 r = min(r1, r2);
		if (l <= r) {
			++d2[min(l1, l2)];
			--d2[max(r1, r2) + 1];
		} else {
			++d2[l1]; --d2[r1 + 1];
			++d2[l2]; --d2[r2 + 1];
		}
	}
	auto ksm = [&]( i64 a,  i64 b) {
		i64 ret = 1;
		while (b) {
			if (b & 1)ret = ret * a % mod;
			a = a * a % mod;
			b >>= 1;
		}
		return ret % mod;
	};
	i64 ans = 0;
	for ( i64 i = 1; i <= 5e5; i++) {
		d1[i] += d1[i - 1];
		d2[i] += d2[i - 1];
	}
	for ( i64 i = 1; i <= 5e5; i++) {
		if (d2[i] == n) {
			ans = (ans % mod + ksm(2, d1[i] - n)) % mod;
		}
	}
	cout << ans << endl;
}
signed main() {
	solve();
}