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
	i64 n; std::cin >> n;
	vector<i64>fa(n + 5, 0), sz(n + 5, 0);
	vector<array<i64, 3>>e(n + 5);
	vector<i64>A(n + 5, 0);
	vector<i64>c(n + 5, 0);
	for (i64 i = 1; i <= n; i++) {
		cin >> A[i]; fa[i] = i;
		sz[i] = 1;
	}
	for (i64 i = 1; i <= n; i++) {
		std::cin >> c[i];
	}
	vector dp(n + 5, vector<i64>(n + 5, 0));//某点子树下有几个黑子/白子所需的earning-cost最小值
	for (i64 i = 1; i <= n - 1; i++) {
		std::cin >> e[i][0] >> e[i][1] >> e[i][2];
	}
	std::sort(e.begin() + 1, e.begin() + n, [&](array<i64, 3>x, array<i64, 3>y)->bool{
		return x[2] < y[2];
	});
	auto find = [&](i64 x) {
		while (x != fa[x])x = fa[x] = fa[fa[x]];
		return x;
	};
	for (i64 i = 1; i <= n; i++) {
		dp[i][A[i]] = 0;
		dp[i][A[i] ^ 1] = -c[i];
	}
	for (i64 s = 1;  s < n; s++) {
		auto [u, v, w] = e[s];
		u = find(u), v = find(v);
		vector<i64>tmp(sz[u] + sz[v] + 5, -inf);
		for (i64 i = 0; i <= sz[u]; i++) {
			for (i64 j = 0; j <= sz[v]; j++) {
				tmp[i + j] = max(tmp[i + j], dp[u][i] + dp[v][j] + (sz[u] - i) * j * w + (sz[v] - j) * i * w);
			}
		}
		fa[v] = u;
		sz[u] += sz[v];
		for (i64 j = 0; j <= sz[u]; j++)dp[u][j] = tmp[j];
	}
	i64 cur = find(1); i64 ans = 0;
	for (i64 i = 0; i <= n; i++)ans = max(ans, dp[cur][i]);
	cout << ans << endl;
}
signed main() {
	solve();
}