

/*采用记忆化搜索来写*/
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

i64 N, M;
void solve() {
	std::cin >> N >> M;
	vector<i64>A(N + 5, 0);
	for (i64 i = 1; i <= N; i++)std::cin >> A[i];
	std::map<array<i64, 3>, i64>dp;
	function<i64(i64, i64, i64)>dfs = [&](i64 i, i64 j, i64 k) {
		if (i == 0) {
			if (j == 0 and k == 1) {
				return dp[ {i, j, k}] = 0;
			} else {
				return dp[ {i, j, k}] = inf;
			}
		}//将无法向下搜索的点全部初始化(i == 0 时)
		if (dp.count({i, j, k}))return dp[ {i, j, k}];
		dp[ {i, j, k}] = inf;
		if (k == 0) {
			i64 v1 = dfs(i - 1, j, 1);
			i64 v2 = dfs(i - 1, j, 0);
			dp[ {i, j, k}] = min(v1 + 1, v2);
		} else {

			if (j >= A[i]) {
				dp[ {i, j, k}] = min(dp[ {i, j, k}], dfs(i - 1, j - A[i], 1));
				dp[ {i, j, k}] = min(dp[ {i, j, k}], dfs(i - 1, j - A[i], 0));
			}
		}
		return dp[ {i, j, k}];
	};
	for (i64 j = 1; j <= M; j++) {
		if (dfs(N, j, 0) == inf and dfs(N, j, 1) == inf) {
			puts("-1");
		} else {
			cout << min(dfs(N, j, 0), dfs(N, j, 1)) << endl;
		}
	}
}
signed main() {
	solve();
}