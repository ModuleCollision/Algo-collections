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




std::map<i64, i64>son; i64 T;
void solve() {
	i64 n; std::cin >> n;
	std::map<i64, i64>k; i64 tot = 0;
	vector<i64>a(n + 5, 0);
	for (i64 i = 1; i <= n; i++) {
		std::cin >> a[i];
		i64 v = a[i];
		for (i64 j = 2; j <= sqrt(v); j++) {
			if (v % j == 0) {
				i64 cnt = 0;
				while (v % j == 0)v /= j, cnt++;
				k[j] += cnt;
			}
		}
		if (v >= 2) {
			k[v] += 1;
		}
	}
	i64 ans = 0, tmp = 0;
	for (auto [x, y] : k) {
		ans += y / 2;
		tmp += y % 2;//素因子个数为m,则m>=3时,显然满足要求
		//故贪心处理即可
	}
	cout << ans + tmp / 3 << endl;
}
signed main() {
	//init();
	std::cin >> T;
	while (T--)solve();
}