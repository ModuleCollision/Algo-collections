/*求 1 到 n 的约数个数和*/
/*思路,对于每个因子k考虑,显然在k的倍数的数字处,k的贡献为1*/
/*我们可以据此写出O(n)的代码*/
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
	i64 ans = 0;
	for (i64 i = 1; i <= n; i++) {
		ans += n / i;
	}
	cout << ans << endl;
}
signed main() {
	i64 T; std::cin >> T;
	while (T--)solve();
}