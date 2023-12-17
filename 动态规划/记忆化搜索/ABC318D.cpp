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
	vector w(n + 5, vector<i64>(n + 5, 0));
	for (i64 i = 1; i <= n - 1; i++) {
		for (i64 j = i + 1; j <= n; j++)cin >> w[i][j];
	}
	std::map<pair<i64, i64>, i64>dp;
	function<i64(i64, i64)>dfs = [&](i64 x, i64 y) {
		if (not x) {
			return dp[ {x, y}] = 0;
		}
		if (dp.count({x, y}))return dp[ {x, y}];
		i64 res = 0;
		res = max(res, dfs(x - 1, y));
		for (i64 j = x + 1; j <= n; j++) {
			if (((y >> (j - 1)) & 1) == 1 and ((y >> (x - 1)) & 1) == 1) {
				res = max(res, dfs(x - 1, y - (1 << (j - 1)) - (1 << (x - 1))) + w[x][j]);
			}
		}
		dp[ {x, y}] = res;
		return res;
	};
	i64 ans = 0;
	for (i64 i = 0; i < (1 << n); i++) {
		ans = max(ans, dfs(n - 1, i));
	}
	cout << ans << endl;
}
signed main() {
	solve();
}