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
	vector<i64>p; vector<i64>A(n + 5);
	for (i64 i = 1; i <= n; i++) {
		std::cin >> A[i];
		A[i] ^= A[i - 1];
	}
	i64 ans = 0;
	p.push_back(0); vector<bool>used((1 << 8) + 5, false);
	used[0] = 1;
	for (i64 i = 1; i <= n; i++) {
		for (i64 j = 0; j <= (1 << 8); j++) {
			if (used[j])
				ans = max(ans, j ^ A[i]);
		}
		used[A[i]] = 1;
	}
	cout << ans << endl;
}
signed main() {
	i64 T; std::cin >> T;
	while (T--)
		solve();
}