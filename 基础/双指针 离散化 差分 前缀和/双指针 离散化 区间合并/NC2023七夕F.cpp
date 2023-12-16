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
	i64 n; cin >> n;
	vector<i64>A(n + 5, 0), pre(n + 5, 0);
	for (i64 i = 1; i <= n; i++) {
		cin >> A[i];
		A[i] ^= 13543;
		A[i] *= 2233;
		A[i] *= 1133;
		A[i] ^= 458646541;
		pre[i] = pre[i - 1] ^ A[i];
	}
	i64 ans = 0;
	std::map<i64, i64>cnt1, cnt2; cnt2[0]++;
	for (i64 r = 1, l = 1; r <= n; r++) {
		cnt1[A[r]]++;
		while (cnt1[A[r]] == 3) {
			cnt1[A[l]]--;
			cnt2[pre[l - 1]]--;
			l++;
		}
		ans += cnt2[pre[r]];
		cnt2[pre[r]]++;
	}
	cout << ans << endl;
}
signed main() {
	i64 T; std::cin >> T;
	while (T--)
		solve();
}
