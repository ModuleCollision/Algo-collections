/*300兆字节 1- 2 秒*/

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
	int n, r, g, b;
	cin >> n >> r >> g >> b;
	if ((n & 1) && (r + g + b) & 1) cout << "Bob" << endl;
	else cout << "Alice" << endl;
	return ;
}
signed main() {
	int T; cin >> T;
	while (T--) {
		solve();
	}
}