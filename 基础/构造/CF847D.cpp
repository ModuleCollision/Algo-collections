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
	vector<i64>A(n + 5, 0);
	std::map<i64, i64>cnt;
	for (i64 i = 1; i <= n; i++) {
		std::cin >> A[i];
		cnt[A[i]]++;
	}
	std::sort(A.begin() + 1, A.begin() + 1 + n);
	i64 len = unique(A.begin() + 1, A.begin() + 1 + n) - A.begin() - 1;
	i64 ans = 0;
	for (i64 i = 1; i <= len; i++) {
		i64 pre = 0;
		while (A[i + 1] == A[i] + 1 and i + 1 <= len) {
			ans += max(0i64, cnt[A[i]] - pre);
			pre = cnt[A[i]]; i++;
		}
		ans += max(0i64, cnt[A[i]] - pre);
	}
	cout << ans << endl;
}
signed main() {
	i64 T; std::cin >> T;
	while (T--)
		solve();
}