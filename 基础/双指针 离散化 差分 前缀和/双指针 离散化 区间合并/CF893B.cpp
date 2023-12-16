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
	vector<i64>idx(m + 5, 0); idx[m + 1] = n + 1;
	idx[0] = 1;
	for (i64 i = 1; i <= m; i++)cin >> idx[i];
	i64 k = m;
	for (i64 i = 1; i <= m + 1; i++) {
		if (i == 1) {
			if (idx[1] == 1)continue;
			else k++;
		}
		k += (idx[i] - idx[i - 1] - 1) / d;
	}
	//cout << k << endl;
	i64 f = inf; vector<i64>as(m + 5);
	for (i64 i = 1; i <= m; i++) {
		i64 ans = k;
		i64 v; if (i == 1 and idx[1] == 1) {
			f = min(f, ans);
			as[i] = ans; continue;
		}
		v = (idx[i] - idx[i - 1] - 1) / d + (idx[i + 1] - idx[i] - 1) / d;
		v++;
		i64 add = (idx[i + 1] - idx[i - 1] - 1) / d;
		ans -= v; ans += add;
		f = min(f, ans);
		as[i] = ans;
	}
	i64 cnt = 0;
	for (i64 i = 1; i <= m; i++)if (as[i] == f)cnt++;
	cout << f << " " << cnt << endl;
}
signed main() {
	i64 T; std::cin >> T;
	while (T--)
		solve();
}