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
	vector<string>s(n + 5);
	for ( i64 i = 1; i <= n; i++) {
		cin >> s[i]; s[i] = " " + s[i];
	}
	vector< i64>p(5 * n + 5, 0), t(5 * n + 5, 0);
	vector cnt(n + 5, vector< i64>(n + 5, 0));
	i64 ans = 0;
	for ( i64 i = 1; i <= n; i++) {
		for ( i64 j = 1; j <= n; j++) {
			cnt[i][j] = (cnt[i][j] + cnt[i - 1][j]) % 2;
			cnt[i][j] = (p[i + j] + cnt[i][j]) % 2; cnt[i][j] = (t[n + j - i] + cnt[i][j]) % 2;
		}
		for ( i64 j = 1; j <= n; j++) {
			i64 cur = s[i][j] - '0';
			if ((cur + cnt[i][j]) % 2 == 1) {
				ans++; cnt[i][j] = (cnt[i][j] + 1) % 2;
				p[i + j] += 1; p[i + j] %= 2; t[n + j - i] += 1; t[n + j - i] %= 2;
			}
		}
	}
	cout << ans << endl;
}
signed main() {
	i64 T; std::cin >> T;
	while (T--)
		solve();
}