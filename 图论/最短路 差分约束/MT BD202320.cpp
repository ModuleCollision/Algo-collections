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

i64 trans1[405][405]; i64 trans2[405][405];
void solve() {
	i64 n, m; std::cin >> n >> m;
	vector<i64>s(n + 1, 0), t(n + 1, 0); i64 w = 0;
	for (i64 i = 1; i <= n; i++)cin >> s[i], w = max(w, s[i]);
	for (i64 i = 1; i <= n; i++)cin >> t[i], w = max(w, t[i]);
	for (i64 i = 1; i <= w; i++) {
		for (i64 j = 1; j <= w; j++) {
			if (i == j)continue;
			trans1[i][j] = trans2[i][j] = inf;
		}
	}
	for (i64 i = 1; i <= m; i++) {
		i64 u, v, q; std::cin >> u >> v >> q;
		trans1[u][v] = min(trans1[u][v], q);
		trans2[u][v] = min(trans2[u][v], q);
	}
	for (i64 k = 1; k <= w; k++) {
		for (i64 i = 1; i <= w; i++) {
			for (i64 j = 1; j <= w; j++) {
				trans1[i][j] = min(trans1[i][j], trans1[i][k] + trans1[k][j]);
			}
		}
	}
	for (i64 k = 1; k <= w; k++) {
		for (i64 i = 1; i <= w; i++) {
			for (i64 j = 1; j <= w; j++) {
				trans2[i][j] = min(trans2[i][j], trans2[i][k] + trans2[j][k]);
			}
		}
	}
	std::unordered_map<i64, i64>cnt1, cnt2;
	for (i64 i = 1; i <= n; i++)cnt1[s[i]]++, cnt2[t[i]]++;
	f64 ans = 0;
	for (auto [x1, y1] : cnt1) {
		i64 c = 0;
		for (auto [x2, y2] : cnt2) {
			i64 cur = min({trans1[x1][x2], trans1[x2][x1], trans2[x1][x2], trans2[x2][x1]});
			c += cur * y2;
		}
		c *= y1; ans += c;
	}
	printf("%.2lf\n", ans / (n));
}
signed main() {
	solve();
}