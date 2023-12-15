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
	i64 n, m; std::cin >> n >> m; i64 ans = 0;
	vector<i64>w(m + 5, 0); for (i64 i = 0; i < m; i++)cin >> w[i];
	for (i64 i = 1; i < (1 << m); i++) {
		i64 k = 1; i64 cnt = 0; bool f = 1;
		for (i64 j = 0; j < m; j++) {
			if ((i >> j) & 1) {
				if (k * w[j] > n) {
					f = 0; break;
				}
				cnt++; k *= w[j];
			}
		}
		if (f) {
			i64 res = n / k;
			if (cnt & 1)ans += res;
			else ans -= res;
		}
	}
	cout << ans << endl;
}
signed main() {
	solve();
}