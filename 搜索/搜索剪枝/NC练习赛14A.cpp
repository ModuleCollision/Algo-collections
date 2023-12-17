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

i64 n;
i64 prime[maxn], cnt = 0, vis[maxn];
void init() {
	for (i64 i = 2; i <= 1e6; i++) {
		if (not vis[i]) {
			prime[++cnt] = i;
		}
		for (i64 j = 1; i * prime[j] <= 1e6 and j <= cnt; j++) {
			vis[prime[j]*i] = 1;
		}
	}
}
i64 ans = 0;
void solve() {
	std::cin >> n;
	function<void(i64, i64, i64, i64)>dfs = [&](i64 k, i64 sum, i64 cur, i64 len) {
		if (k >= 14)return;
		ans = max(ans, cur);
		for (i64 i = 1; i <= len; i++) {
			if (sum <= n / prime[k]) {
				sum *= prime[k];//搜索,枚举每个素数的幂次即可
				dfs(k + 1, sum, cur * (i + 1), i);
			}
		}
	};
	ans = 1;
	dfs(1, 1, 1, 15);
	cout << ans << endl;
}
signed main() {
	i64 T; std::cin >> T;
	init();
	while (T--)solve();
}