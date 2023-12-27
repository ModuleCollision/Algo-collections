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

//拓扑求环
void solve() {
	i64 n; std::cin >> n;
	i64 ans = 0; bool f = 0;
	vector<i64>p(n + 5, 0);
	for (i64 i = 1; i <= n; i++)cin >> p[i];
	vector<i64>c; vector<bool>vis(n + 5, 0);
	for (i64 i = 1; i <= n; i++) {
		if (not vis[i]) {
			i64 cur = i; vis[i] = 1;
			c.clear(); c.push_back(cur);
			while (1) {
				cur = p[cur];
				if (vis[cur])break;
				c.push_back(cur);
				vis[cur] = 1;
			}
			std::sort(c.begin(), c.end());
			ans += c.size() - 1; if (f)continue;
			for (i64 i = 0; i < c.size() - 1; i++) {
				if (c[i] + 1 == c[i + 1]) {
					f = 1; break;
				}
			}
		}
	}
	if (not ans) {
		cout << 1 << endl;
	} else if (f) {
		cout << ans - 1 << endl;
	} else {
		cout <<	ans + 1 << endl;
	}
}
signed main() {
	i64 T; std::cin >> T;
	while (T--) {
		solve();
	}
}