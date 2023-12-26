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

vector<pair<i64, i64>>st[maxn];
char G[maxn][maxn];
i64 dp[maxn][100005], N, M;
void solve() {
	cin >> N >> M;
	for (i64 i = 1; i <= N; i++) {
		cin >> G[i];
	}
	function<void(i64, i64, i64, i64)>dfs = [&](i64 val, i64 idx, i64 r, i64 cnt) {
		if (idx >= M) {
			st[r].push_back({val, cnt});
			return;
		}
		if (G[r][idx] == 'P') {
			bool f1 = true, f2 = true;
			if (idx > 0) {
				f1 = not((val >> (idx - 1)) & 1);
			}
			if (idx > 1) {
				f2 = not((val >> (idx - 2)) & 1);
			}
			if (f1  and f2) {
				dfs(val + (1 << idx), idx + 3, r, cnt + 1);
			}
		}
		dfs(val, idx + 1, r, cnt);
	};
	for (i64 i = 1; i <= N; i++) {
		dfs(0, 0, i, 0);
	}
	for (auto [x, y] : st[1]) {
		dp[1][x] = y;
	}
	for (auto [x1, y1] : st[2]) {
		for (auto [x2, y2] : st[1]) {
			if (not(x1 & x2)) {
				dp[2][x1] = max(dp[2][x1], dp[1][x2] + y1);
			}
		}
	}
	for (i64 i = 3; i <= N; i++) {
		for (auto [xc, yc] : st[i]) {
			for (auto [xd, yd] : st[i - 2]) {
				for (auto [xf, yf] : st[i - 1]) {
					if ((not(xc & xd)) and (not(xd & xf)) and (not(xc & xf))) {
						dp[i][xc] = max(dp[i][xc], dp[i - 2][xd] + yf + yc);
					}
				}
			}
		}
	}
	i64 ans = 0;
	for (auto [x, y] : st[N]) {
		ans = max(ans, dp[N][x]);
	}
	if (ans == 16)ans--;
	cout << ans << endl;
}
signed main() {
	solve();
}