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

i64 N, a, b;
i64 sz[maxn];
i64 dp[maxn][maxn][2];//i子树j个联通分量,i节点选不选的方案数
vector<i64>tr[maxn];
void solve() {
	std::cin >> N;
	for (i64 i = 1; i <= N - 1; i++) {
		std::cin >> a >> b;
		tr[a].push_back(b);
		tr[b].push_back(a);
	}
	function<void(i64, i64)>dfs = [&](i64 u, i64 f) {
		dp[u][1][1] = dp[u][0][0] = 1;
		sz[u] = 1;
		for (auto v : tr[u]) {
			if (v == f)continue;
			dfs(v, u);
			vector<i64>tmp1(sz[u] + sz[v] + 5, 0), tmp2(sz[u] + sz[v] + 5, 0);
			for (i64 j = 0; j <= sz[u]; j++) {
				for (i64 k = 0; k <= sz[v]; k++) {
					tmp1[j + k] = (tmp1[j + k] % mod + dp[u][j][1] % mod * dp[v][k][0] % mod);
					if (j + k) {
						tmp1[j + k - 1] = (tmp1[j + k - 1] % mod + dp[u][j][1] % mod * dp[v][k][1]) % mod;
					}
					tmp2[j + k] = (tmp2[j + k] % mod + dp[u][j][0] % mod * dp[v][k][1]) % mod;
					tmp2[j + k] = (tmp2[j + k] % mod + dp[u][j][0] % mod * dp[v][k][0]) % mod;
				}
			}
			for (i64 i = 0; i <= sz[u] + sz[v]; i++) {
				dp[u][i][1] = tmp1[i];
				dp[u][i][0] = tmp2[i];
			}
			sz[u] += sz[v];
		}
	};
	dfs(1, 1);
	for (i64 i = 1; i <= N; i++) {
		cout << (dp[1][i][0] % mod + dp[1][i][1]) % mod << endl;
	}
}
signed main() {
	solve();
}