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
	vector<i64>A(n + 5, 0), B(n + 5, 0);
	for (i64 i = 1; i <= n; i++)cin >> A[i];
	for (i64 j = 1; j <= n; j++)cin >> B[j];
	i64 ans = 0;
	vector<i64>a(n + 5), b(n + 5);
	for (i64 i = 0; i <= 28; i++) {
		i64 msk = (1 << (i + 1));
		for (i64 j = 1; j <= n; j++)a[j] = A[j] % msk;
		for (i64 j = 1; j <= n; j++)b[j] = B[j] % msk;
		sort(a.begin() + 1, a.begin() + 1 + n);
		sort(b.begin() + 1, b.begin() + 1 + n);
		i64 cnt = 0;
		i64 l1 = (1 << i), r1 = (1 << (i + 1)) - 1, l2 = (3 << i), r2 = (1 << (i + 2)) - 1;
		for (i64 j = 1; j <= n; j++) {
			i64 idx1 = lower_bound(b.begin() + 1, b.begin() + 1 + n, l1 - a[j]) - b.begin();
			i64 idx2 = upper_bound(b.begin() + 1, b.begin() + 1 + n, r1 - a[j]) - b.begin();
			i64 idx3 = lower_bound(b.begin() + 1, b.begin() + 1 + n, l2 - a[j]) - b.begin();
			i64 idx4 = upper_bound(b.begin() + 1, b.begin() + 1 + n, r2 - a[j]) - b.begin();
			cnt += idx2 - idx1 + idx4 - idx3;
		}
		if (cnt & 1)ans |= (1 << i);
	}
	cout << ans << endl;
}
signed main() {
	solve();
}