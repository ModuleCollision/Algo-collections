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
	i64 n, m; std::cin >> n >> m;
	vector<i64>dp((1 << n) + 1, 0);
	vector<i64>pr(n + 5, 0); i64 tot = 0;
	for (i64 i = 1; i <= n; i++)cin >> pr[i], tot += pr[i];
	std::sort(pr.begin() + 1, pr.begin() + 1 + n, [&](i64 a, i64 b)->bool{
		return a > b;
	});
	dp[0] = 0; vector<i64>vis((1 << n) + 5, 0);
	for (i64 i = 1; i <= m; i++) {
		i64 k; std::cin >> k; i64 cur = 0;
		for (i64 j = 1; j <= k; j++) {
			i64 v; cin >> v;
			cur |= (1 << (v - 1));
		}
		vis[cur] = 1;
	}
	auto count = [&](i64 x) {
		i64 ret = 0;
		for (i64 i = 0; i <= 16; i++) {
			if ((x >> i) & 1)ret++;
		}
		return ret;
	};
	i64 ans = inf;
	for (i64 i = 1; i < (1 << n); i++) {
		for (i64 j = i; j; j = i & (j - 1)) {
			if (vis[j]) {
				dp[i] = max(dp[i], dp[i ^ j] + pr[count(i)]);
			}
		}
		ans = min(ans, tot - dp[i]);
	}
	cout << ans << endl;
}
signed main() {
	solve();
}