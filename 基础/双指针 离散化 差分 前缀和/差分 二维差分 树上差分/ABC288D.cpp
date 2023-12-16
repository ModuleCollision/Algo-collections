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
	i64 n, k; std::cin >> n >> k;
	vector< i64>a(n + 5, 0); for ( i64 i = 1; i <= n; i++)cin >> a[i];
	i64 q; std::cin >> q;
	vector sum(n + 5, vector< i64>(k + 5, 0));
	for ( i64 i = 1; i <= n; i++) {
		for ( i64 j = 0; j < k; j++) {
			sum[i][j] += sum[i - 1][j];
		}
		sum[i][i % k] += a[i];
	}
	vector<bool>ans(q + 5, 0);
	while (q--) {
		i64 l, r; std::cin >> l >> r;
		std::set< i64>tes;
		for ( i64 i = 0; i < k; i++)tes.insert(sum[r][i] - sum[l - 1][i]);
		puts((tes.size() == 1) ? "Yes" : "No");
	}
}
signed main() {
	solve();
}