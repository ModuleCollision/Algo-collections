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

i64 lg[maxn], st[maxn][30];

i64 query(i64 l, i64 r) {
	int x = lg[r - l + 1];
	return min(st[l][x], st[r - (1 << x) + 1][x]);
}
void solve() {
	i64 n, m; cin >> n >> m;
	vector<i64>A(n + 5, 0); auto C = A;
	vector<bool>vis(n + 5, false);
	vector dp(n + 5, vector<i64>(n + 5, inf));
	for (i64 i = 1; i <= n; i++)cin >> A[i];
	for (i64 i = 1; i <= n; i++)cin >> C[i];
	for (i64 i = 1; i <= m; i++) {
		i64 v; std::cin >> v;
		vis[v] = 1;
	}
	for (i64 i = 0; i <= n; i++) {
		for (i64 j = 0; j <= n; j++)dp[i][j] = inf;
	}
	auto init = [&]() {
		for (i64 i = 1; i <= n; i++) st[i][0] = C[i];
		for (i64 i = 2; i <= 5000; i++)lg[i] = (lg[i >> 1] + 1);
		for (i64 len = 1; (1 << len) <= n; len++) {
			for (i64 i = 1; (i + (1 << len) - 1) <= n; i++) {
				st[i][len] = min(st[i][len - 1], st[i + (1 << (len - 1))][len - 1]);
			}
		}
	};
	init();
	dp[0][0] = 0;
	for (i64 i = 1; i <= n; i++) {
		for (i64 j = 0; j <= i; j++) {
			if (j) {
				dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + A[i] + query(i - j + 1, i));
			}
			if (not vis[i]) {
				dp[i][j] = min(dp[i][j], dp[i - 1][j]);
			}
		}
	}
	i64 ans = inf;
	for (i64 i = m; i <= n; i++)ans = min(ans, dp[n][i]);
	cout << ans << endl;
}
signed main() {
	solve();
}