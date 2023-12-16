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
	vector<i64>B(n + 5, 0), pre(n + 5, 0);
	for (i64 i = 1; i <= n - 1; i++) {
		std::cin >> B[i];
		pre[i] = pre[i - 1] ^ B[i];
	}
	vector<i64>vis(31, -1); bool f = 1;
	for (i64 i = 0; i < n - 1; i++) {
		i64 t1 = pre[i], t2 = pre[i + 1];
		if (not f)break;
		for (i64 j = 29; j >= 0; j--) {
			i64 cur1 = ((t1 >> j) & 1); i64 cur2 = ((t2 >> j) & 1);
			if (cur1 == cur2)continue;
			else {
				if (vis[j] != -1) {
					if (vis[j] != cur1)//发生了矛盾
						f = 0;
				} else {
					vis[j] = cur1;
				}
				break;
			}
		}
	}
	i64 cnt = 0;
	if (not f) {
		puts("-1"); return;
	}
	for (i64 i = 0; i <= 29; i++) {
		if (vis[i] == -1)cnt++;
	}
	k--;
	if ((1ll << cnt) - 1 < k) {
		puts("-1"); return;
	}
	for (i64 j = 0, i = 0; j <= 29 and i <= 29 and (k >> j); j++) {
		i64 cur = ((k >> j) & 1ll);
		while (vis[i] != -1 and i <= 29)i++;
		vis[i] = cur;
	}
	vector<i64>ans(n + 5, 0);
	for (i64 i = 0; i <= 29; i++) {
		if (vis[i] == 1)
			ans[1] += (vis[i] << i);
	}
	for (i64 i = 2; i <= n; i++) {
		ans[i] = (ans[i - 1] ^ B[i - 1]);
		if (ans[i] < ans[i - 1]) {
			puts("-1"); return;
		}
	}
	for (i64 i = 1; i <= n; i++)cout << ans[i] << " ";
	cout << endl;
}
signed main() {
	i64 T; std::cin >> T;
	while (T--)
		solve();
}
