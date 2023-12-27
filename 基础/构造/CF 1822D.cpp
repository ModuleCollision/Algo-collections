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
	vector<i64>d(n + 5, 0);
	i64 l = 0, r = n - 1;
	for (i64 i = 1; i <= n; i += 2) {
		d[i] = l; d[i + 1] = r;
		l++; r--;
	}
	vector<bool>vis(n + 5, 0);
	vector<i64>ans(n + 5, 0);
	for (i64 i = 1; i <= n; i++) {
		i64 v = ((d[i] - d[i - 1]) % n + n) % n;
		if (v == 0)v += n;
		if (vis[v]) {
			puts("-1"); return;
		}
		ans[i] = v; vis[v] = 1;
	}
	for (i64 i = 1; i <= n; i++) {
		cout << ans[i] << " ";

	}
	cout << endl;
}
signed main() {
	i64 T; std::cin >> T;
	while (T--)
		solve();
}