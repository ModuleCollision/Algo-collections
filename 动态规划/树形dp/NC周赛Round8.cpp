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

i64 n, A[maxn], sz[maxn];
i64 dp[maxn][2];
void solve() {
	auto check = [&](i64 x) {
		i64 q = (i64)sqrt(x);
		return q * q == x;
	};
	cin >> n;
	for (i64 i = 1; i <= n; i++)cin >> A[i];
	vector<vector<i64>>tr(n + 1);
	for (i64 i = 1; i <= n - 1; i++) {
		i64 u, v; std::cin >> u >> v;
		tr[u].push_back(v); tr[v].push_back(u);
	}
	function<void(i64, i64)>dfs = [&](i64 u, i64 f) {
		sz[u] = 1;
		i64 cs = 0;
		vector<bool>tmp(tr[u].size() + 1, 0);
		for (i64 i = 0; i < tr[u].size(); i++) {
			i64 v = tr[u][i];
			if (v == f)continue;
			dfs(v, u);
			dp[u][0] += max(dp[v][1], dp[v][0]);
			if (dp[v][1] >= dp[v][0]) {
				tmp[i] = true; cs += dp[v][1];
			} else {
				tmp[i] = false; cs += dp[v][0];
			}
			sz[u] += sz[v];
		}
		for (i64 i = 0; i < tr[u].size(); i++) {
			if (tr[u][i] == f)continue;
			i64 v = tr[u][i]; i64 t = cs;
			if (check(A[u] * A[v])) {
				t -= dp[v][tmp[i]];
				t += dp[v][0];
				dp[u][1] = max(dp[u][1], t + 2);
			}
		}
	};
	dfs(1, 0);
	cout << max(dp[1][0], dp[1][1]) << endl;
}
signed main() {
	solve();
}