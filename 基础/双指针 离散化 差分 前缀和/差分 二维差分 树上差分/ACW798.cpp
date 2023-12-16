/*二维差分模板*/
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

i64 d[maxn][maxn], a[maxn][maxn];
i64 n, m, q, x, y, s, t, c;
void solve() {
	std::cin >> n >> m >> q;
	for ( i64 i = 1; i <= n; i++) {
		for ( i64 j = 1; j <= m; j++) {
			std::cin >> a[i][j];
		}
	}
	for ( i64 i = 1; i <= n; i++) {
		for ( i64 j = 1; j <= m; j++) {
			d[i][j] = (a[i][j] - a[i - 1][j] - a[i][j - 1] + a[i - 1][j - 1]);
		}
	}
	for ( i64 i = 1; i <= q; i++) {
		std::cin >> x >> y >> s >> t >> c;
		d[x][y] += c;
		d[s + 1][t + 1] += c;
		d[x][t + 1] -= c;
		d[s + 1][y] -= c;
	}
	for ( i64 i = 1; i <= n; i++) {
		for ( i64 j = 1; j <= m; j++) {
			d[i][j] += d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1];
			cout << d[i][j] << " ";
		}
		cout << endl;
	}
}
signed main() {
	solve();
}