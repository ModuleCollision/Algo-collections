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
	vector<i64>A(n + 5, 0);
	i64 ans = 0;
	for (i64 i = 1; i <= n; i++)cin >> A[i], A[i] += A[i - 1];
	std::map<i64, i64>cnt; cnt[0]++;
	for (i64 i = 1; i <= n; i++) {
		ans += cnt[A[i] - k]; cnt[A[i]]++;
	}
	cout << ans << endl;
}
signed main() {
	solve();
}