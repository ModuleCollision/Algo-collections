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
	for (i64 i = 1; i <= n; i++)cin >> A[i];
	vector<i64>pre1(33), pre2(33);//前缀为 0 的个数，前缀为1的个数
	vector<i64>cnt(33);
	for (i64 i = 30; i >= 0; i--)pre1[i]++;
	vector<i64>w(n + 1);
	for (i64 i = 1; i <= n; i++) {
		w[i] = w[i - 1] ^ A[i];
	}
	for (i64 i = 1; i <= n; i++) {
		for (i64 j = 30; j >= 0; j--) {
			if (((w[i] >> j) & 1)) {
				cnt[j] += pre1[j];
				pre2[j]++;
			} else {
				cnt[j] += pre2[j]; pre1[j]++;
			}
		}
	}
	i64 ans = 0;
	for (i64 i = 0; i <= 30; i++) {
		ans += (1 << i) * cnt[i];
	}
	cout << ans << endl;
}
signed main() {
	solve();
}