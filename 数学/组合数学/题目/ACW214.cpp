/*计数dp*/
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
	vector dp(n + 5, vector<i64>(m + 5, 0));
	dp[0][0] = 1;
	vector<i64>A(n + 5, 0);
	for (i64 i = 1; i <= n; i++)cin >> A[i];
	for (i64 i = 1; i <= n; i++) {
		for (i64 j = 0; j <= m; j++) {
			for (i64 k = 0; k <= min(j, A[i]); k++) {
				dp[i][j] = (dp[i][j] % mod + dp[i - 1][j - k]) % mod;
			}
		}
	}
	cout << dp[n][m] % mod << endl;
}
signed main() {
	solve();
}


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

i64 fac[maxn];
void init() {
	fac[0] = 1;
	for (i64 i = 1; i <= 1e6; i++)fac[i] = (fac[i - 1] % mod * i) % mod;
}
i64 ksm(i64 x, i64 y) {
	i64 ret = 1;
	while (y) {
		if (y & 1)ret = ret * x % mod;
		x = x * x % mod;
		y >>= 1;
	}
	return ret % mod;
}
i64 inv(i64 x) {
	return ksm(x, mod - 2) % mod;
}
i64 comb(i64 n, i64 m) {
	if (n < m)return 0i64;
	return fac[n] % mod * inv(fac[m] % mod * fac[n - m] % mod) % mod;
}
void solve() {
	init();
	i64 n, m; std::cin >> n >> m; vector<i64>A(n + 1, 0);
	for (i64 i = 0; i < n; i++)cin >> A[i];
	i64 res = comb(n + m - 1, n - 1) % mod; i64 d = 0;
	for (i64 i = 1; i < (1 << n); i++) {
		vector<i64>s; i64 cnt = 0;
		for (i64 j = 0; j < n; j++)if ((i >> j) & 1)s.push_back(j), cnt++;
		i64 p = n + m - 1;
		for (auto c : s) {
			p -= (A[c] + 1);
		}
		i64 v = comb(p, n - 1) % mod;
		if (cnt & 1)d = (d % mod + v) % mod;
		else d = ((d - v) % mod + mod) % mod;
	}
	res = ((res - d) % mod + mod) % mod;
	cout << res << endl;
}
signed main() {
	solve();
}