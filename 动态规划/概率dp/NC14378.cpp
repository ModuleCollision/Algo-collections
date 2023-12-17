/*dp求期望*/
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


i64 n, m, a[maxn], pre[maxn], x;
f64 dp[maxn], f[maxn];
void solve() {
	cin >> n >> m; i64 Max = 0;
	for (i64 i = 1; i <= n; i++) {
		cin >> a[i];
		Max = max(Max, a[i]);
		pre[i] = pre[i - 1] + a[i];
	}
	while (m--) {
		std::cin >> x;
		if (x < Max) {
			puts("YNOI is good OI!");
			continue;
		}
		i64 tot = a[n];
		dp[n] = 1.0; f[n] = 1.0;
		for (i64 i = n - 1, j = n; i >= 1; i--) {
			tot += a[i];
			while (tot > x) {
				tot -= a[j];
				j--;
			}
			dp[i] = (f[i + 1] - f[j + 2]) / (f64)(j - i + 1) + 1;
			f[i] = dp[i] + f[i + 1];
		}
		printf("%.2lf\n", dp[1]);
	}
}
signed main() {
	solve();
}