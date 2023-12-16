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
	vector<i64>pre(n + 5, 0), suf(n + 5, 0);
	vector<i64>lf(n + 5, 0);
	for (i64 i = 1; i <= n; i++)cin >> A[i];
	std::map<i64, i64>cnt;
	for (i64 l = 1, r = 1; r <= n; r++) {
		cnt[A[r]]++;
		if (cnt[A[r]] > 1) {
			while (cnt[A[r]] > 1) {
				cnt[A[l]]--; l++;
			}
		}
		lf[r] = l;
	}
	for (i64 i = 1; i <= n; i++) {
		i64 l = i;
		while (i + 1 <= n and A[i + 1] <= A[i])i++;
		for (i64 j = l; j <= i; j++)pre[j] = l;
	}
	for (i64 i = n; i >= 1; i--) {
		i64 l = i;
		while (i - 1 >= 1 and A[i - 1] <= A[i])i--;
		for (i64 j = i; j <= l; j++)suf[j] = i;
	}
	i64 ans = 0;
	vector<i64>w(n + 5, 0);
	for (i64 i = 1; i <= n; i++) {
		cin >> w[i]; w[i] += w[i - 1];
	}
	for (i64 i = 1; i <= n; i++) {
		i64 l1 = lf[i], l2 = suf[pre[i]];
		i64 l = max(l1, l2);
		//cout << pre[i] << " " << suf[i] << endl;
		ans = max(ans, w[i] - w[l - 1]);
	}
	cout << ans << endl;
}
signed main() {
	i64 T; std::cin >> T;
	while (T--)
		solve();
}