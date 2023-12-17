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

i64 k[maxn]; i64 n, m;
i64 a, b, c;
void solve() {
	std::cin >> n >> m;
	for (i64 i = 1; i <= n; i++) {
		std::cin >> k[i];
	}
	std::sort(k + 1, k + 1 + n, [&](db x, db y)->bool{
		return x < y;
	});
	for (i64 i = 1; i <= m; i++) {
		std::cin >> a >> b >> c;
		i64 idx = lower_bound(k + 1, k + 1 + n, b) - k;
		if (idx <= n and (k[idx] - b) * (k[idx] - b) < 4 * a * c) {
			puts("YES");
			cout << (i64)k[idx] << endl; continue;
		}
		if (idx >= 2 and (k[idx - 1] - b) * (k[idx - 1] - b) < 4 * a * c) {
			puts("YES");
			cout << (i64)k[idx - 1] << endl; continue;
		}
		puts("NO");
	}
}
signed main() {
	i64 T; std::cin >> T;
	while (T--)solve();
}