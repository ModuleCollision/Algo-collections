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

i64 N, w[maxn];
vector<i64>tr[maxn];
i64 dp[maxn][2];
i64 r, d[maxn];
void solve() {
	std::cin >> N;
	for (i64 i = 1; i <= N; i++) {
		std::cin >> w[i];
	}
	for (i64 i = 1; i <= N - 1; i++) {
		i64 u, v; std::cin >> u >> v;
		tr[v].push_back(u);
		d[u]++;
	}
	for (i64 i = 1; i <= N; i++) {
		if (not d[i]) {
			r = i; break;
		}
	}
	function<void(i64, i64)>dfs = [&](i64 u, i64 f) {
		dp[u][1] = w[u];
		for (auto v : tr[u]) {
			if (v == f)continue;
			dfs(v, u);
			dp[u][1] += dp[v][0];
			dp[u][0] += max(dp[v][1], dp[v][0]);
		}
	};
	dfs(r, r);
	cout << max(dp[r][1], dp[r][0]) << endl;
}
signed main() {
	solve();
}