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

i64 dp[5005];
void solve() {
	i64 n; std::cin >> n;
	vector<vector<i64>>tr(n + 1);
	for (i64 i = 2; i <= n; i++) {
		i64 v; std::cin >> v; tr[i].push_back(v);
		tr[v].push_back(i);
	}
	vector<i64>sz(n + 1);
	function<void(i64, i64)>dfs = [&](i64 u, i64 f) {
		sz[u] = 1;
		for (auto v : tr[u]) {
			if (v == f)continue;
			dfs(v, u);
			sz[u] += sz[v];
		}
	};
	i64 ret = 0;
	function<void(i64, i64, i64)>dfs2 = [&](i64 u, i64 f, i64 len) {
		vector<i64>pr; i64 tot = 0;
		for (auto v : tr[u]) {
			if (v == f)continue; pr.push_back(sz[v]);
			tot += sz[v];
		}
		if (len == 1) {
			return;
		}
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		for (auto v : pr) {
			for (i64 j = tot; j >= v; j--)dp[j] |= dp[j - v];
		}
		i64 ans = 0;
		for (i64 j = 0; j <= tot; j++)if (dp[j])ans = max(ans, j * (tot - j));
		ret += ans;
		for (auto v : tr[u]) {
			if (v == f)continue;
			dfs2(v, u, sz[v]);
		}
	};
	dfs(1, 0); dfs2(1, 0, n);
	//for (i64 i = 1; i <= n; i++)cout << a[i] << " ";
	cout << ret << endl;
}
signed main() {
	solve();
}