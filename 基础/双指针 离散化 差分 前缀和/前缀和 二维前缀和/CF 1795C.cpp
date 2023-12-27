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

/*差分 + 前缀和 + 二分*/
void solve() {
	i64 n; std::cin >> n;
	vector<i64>a(n + 5, 0), b(n + 5, 0), pre(n + 5, 0), ans(n + 5, 0);
	vector<i64>cnt(n + 5, 0), d(n + 5, 0);//差分数组 + tag数组
	for (i64 i = 1; i <= n; i++)std::cin >> a[i];
	for (i64 i = 1; i <= n; i++)std::cin >> b[i];
	for (i64 i = 1; i <= n; i++) {
		pre[i] += b[i] + pre[i - 1];
	}
	for (i64 i = 1; i <= n; i++) {
		i64 l = i;
		i64 r = lower_bound(pre.begin() + 1, pre.begin() + 1 + n, pre[l - 1] + a[i]) - pre.begin();
		cnt[l] += 1; cnt[r] -= 1;
		i64 t = a[i] - (pre[r - 1] - pre[l - 1]);
		d[r] = t;
	}
	for (i64 i = 1; i <= n; i++)cnt[i] += cnt[i - 1];
	for (i64 i = 1; i <= n; i++) {
		ans[i] = cnt[i] * b[i] + d[i];
	}
	for (i64 i = 1; i <= n; i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
}
signed main() {
	i64 T; std::cin >> T;
	while (T--)solve();
}