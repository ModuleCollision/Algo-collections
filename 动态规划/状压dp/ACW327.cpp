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

i64 N, M, vis[15][15];
i64 dp[15][(1 << 12) + 5];//第i行为j状态的合法种数
vector<i64>st[15];//维护每行的合法状态
void solve() {
	cin >> N >> M;
	for (i64 i = 1; i <= N; i++) {
		for (i64 j = 0; j < M; j++) {
			cin >> vis[i][j];
		}
	}
	function<void(i64, i64, i64)>dfs = [&](i64 v, i64 idx, i64 l) {
		if (idx >= M) {
			st[l].push_back(v);
			return;
		}
		if (vis[l][idx]) {
			dfs(v + (1 << idx), idx + 2, l);
		}
		dfs(v, idx + 1, l);
	};
	for (i64 i = 1; i <= N; i++) {
		dfs(0, 0, i);
	}
	for (auto c : st[1]) {
		dp[1][c] = 1;
	}
	i64 ans = 0;
	for (i64 i = 2; i <= N; i++) {
		for (auto st1 : st[i - 1]) {
			for (auto st2 : st[i]) {
				if (not(st1 & st2)) {
					dp[i][st2] += dp[i - 1][st1] % mod;
				}
			}
		}
	}
	for (auto s : st[N]) {
		ans = (ans % mod + dp[N][s]) % mod;
	}
	cout << ans << endl;
}
signed main() {
	solve();
}