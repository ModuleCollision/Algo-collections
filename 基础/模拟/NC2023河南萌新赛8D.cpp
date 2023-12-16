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

i64 d1[maxn], d2[maxn];
void solve() {
	i64 x, y; std::cin >> x >> y;
	i64 tx = 0, ty = 0;
	i64 n; std::cin >> n;
	string s; std::cin >> s;  i64 k = s.size(); s = " " + s;
	if (not x and not y) {
		puts("Yes"); return;
	}
	for ( i64 i = 1; i <= k; i++) {
		if (s[i] == 'U')ty++;
		else if (s[i] == 'D')ty--;
		else if (s[i] == 'R')tx++;
		else tx--;
		if (tx == x and ty == y) {
			puts("Yes"); return;
		}
	}
	if (not tx and not ty) {
		puts("No"); return;
	}
	i64 xx = 0, yy = 0;
	for ( i64 i = 1; i <= k; i++) {
		if (s[i] == 'U')yy++;
		else if (s[i] == 'D')yy--;
		else if (s[i] == 'R')xx++;
		else xx--;
		i64 dx = x - xx;  i64 dy = y - yy;
		if (dx and (not tx or dx % tx)) {
			continue;
		}
		if (dy and (not ty or dy % ty))continue;
		i64 wx = tx ? dx / tx : 0;
		i64 wy = ty ? dy / ty : 0;
		if (not wx or not wy or (wx == wy) and wx >= 0 and wx < n and wy >= 0 and wy < n) {
			puts("Yes"); return;
		}
	}
	puts("No");
}
signed main() {
	i64 T; std::cin >> T;
	while (T--)
		solve();
}