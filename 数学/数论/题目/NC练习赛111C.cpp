/*数论分块*/
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

constexpr i64 mod = 1145141;
constexpr i64 maxn = 4e6 + 5;
constexpr i64 inf = 0x3f3f3f3f3f3f3f3f;


void solve() {
	i64 m, x; std::cin >> m >> x;
	i64 k = m / x;
	i64 ans = 0;
	ans += m / k - x + 1;
	k++;
	if (k) {
		ans += x - m / k - 1;
	}
	cout << ans << endl;
}
signed main() {
	i64 T; std::cin >> T;
	while (T--)
		solve();
}