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
	i64 n, m, d; std::cin >> n >> m >> d;
	vector< i64>f(n + 5, 0);
	i64 ans = 0;
	for ( i64 i = 1; i <= n; i++)cin >> f[i];
	std::multiset< i64>st;  i64 tot = 0;
	for ( i64 i = 1; i <= n; i++) {
		if (f[i] <= 0)continue;
		ans = max(ans, tot + f[i] - d * i);
		if (m != 1) {
			if (st.size() < m - 1) {
				st.insert(f[i]); tot += f[i];
			} else {
				i64 k = *st.begin();
				if (f[i] > k) {
					tot -= k; tot += f[i];
					st.erase(st.begin());
					st.insert(f[i]);
				} else continue;
			}
		}
	}
	cout << ans << endl;
}
signed main() {
	i64 T; std::cin >> T;
	while (T--)
		solve();
}