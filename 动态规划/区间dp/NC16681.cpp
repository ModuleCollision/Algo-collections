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

i64 n, w[maxn], dp[maxn][maxn], ro[maxn][maxn];
void solve() {
	cin >> n;
	for (i64 i = 1; i <= n; i++) {
		cin >> w[i];
	}
	for (i64 i = 1; i <= n; i++) {
		dp[i][i] = w[i]; ro[i][i] = i;
	}
	for (i64 len = 2; len <= n; len++) {
		for (i64 l = 1; l + len - 1 <= n; l++) {
			i64 r = l + len - 1;
			for (i64 k = l; k <= r; k++) {
				i64 x = (l == k) ? 1 : dp[l][k - 1];
				i64 y = (r == k) ? 1 : dp[k + 1][r];
				i64 res = (x * y) + w[k];
				if (res > dp[l][r]) {
					dp[l][r] = res;
					ro[l][r] = k;
				}
			}
		}
	}
	cout << dp[1][n] << endl;
	function<void(i64, i64)>dfs = [&](i64 l, i64 r) {
		if (l > r) {
			return;
		}
		i64 k = ro[l][r];
		cout << k << " ";
		dfs(l, k - 1);
		dfs(k + 1, r);
	};
	dfs(1, n);
}
signed main() {
	solve();
}
