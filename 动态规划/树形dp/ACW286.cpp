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

vector<i64>tr[maxn];
i64 N, M;
i64 dp[maxn][maxn], w[maxn]; //以u为根的子树选择j个的总个数
/*树形dp可以转化为背包或者组合数问题求解*/
/*往这两方面考虑*/
void solve() {
	std::cin >> N >> M;
	for (i64 i = 1; i <= N; i++) {
		i64 p; std::cin >> p >> w[i];
		tr[p].push_back(i);
	}
	vector<i64>sz(N + 5, 0);
	function<void(i64)>dfs = [&](i64 u) {
		vector<i64>tmp(M + 5, 0);
		for (auto v : tr[u]) {
			dfs(v);//u必选,所以将其拿掉做树形背包
			for (i64 i = 0; i <= min(sz[u], M + 1); i++) {
				for (i64 j = 0; j <= min(sz[v], M + 1 - i); j++) {
					tmp[i + j] = max(tmp[i + j], dp[u][i] + dp[v][j]);
				}
			}
			for (i64 i = 0; i <= M + 1; i++) {
				dp[u][i] = tmp[i];
			}
			sz[u] += sz[v];
		}
		sz[u] += 1;
		for (i64 i = M + 1; i >= 1; i--) {
			dp[u][i] = dp[u][i - 1] + w[u];
		}
	};
	dfs(0);
	cout << dp[0][M + 1] << endl;
}
signed main() {
	solve();
}