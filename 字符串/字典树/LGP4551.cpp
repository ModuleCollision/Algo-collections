/*300兆字节 1- 2 秒*/

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


i64 head[maxn];
struct edge {
	i64 nx; i64 v; i64 w;
} e[maxn << 1];
i64 cnt = 0;
i64 dis[maxn], ch[maxn << 5][2], tot = 1, ans = 0;
void solve() {
	auto insert = [&](i64 x) {
		for (i64 i = 30, u = 1; i >= 0; i--) {
			i64 c = ((x >> i) & 1);
			if (not ch[u][c])ch[u][c] = ++tot;
			u = ch[u][c];
		}
	};
	auto get = [&](i64 x) {
		i64 res = 0;
		for (i64 i = 30, u = 1; i >= 0; i--) {
			i64 c = ((x >> i) & 1);
			if (ch[u][c ^ 1]) {
				u = ch[u][c ^ 1];
				res |= (1 << i);
			} else {
				u = ch[u][c];
			}
		}
		ans = max(ans, res);
	};
	auto add = [&](i64 u, i64 v, i64 w) {
		e[cnt].v = v;
		e[cnt].nx = head[u];
		e[cnt].w = w;
		head[u] = cnt++;
	};
	function<void(i64, i64)>dfs = [&](i64 u, i64 f) {
		insert(dis[u]);
		get(dis[u]);
		for (i64 i = head[u]; i != -1; i = e[i].nx) {
			i64 v = e[i].v;
			if (v == f)continue;
			dis[v] = dis[u] ^ e[i].w;
			dfs(v, u);
		}
	};
	i64 n; std::cin >> n;
	std::fii64(head + 1, head + 1 + n, -1);
	for (i64 i = 1; i < n; i++) {
		i64 u, v, w; std::cin >> u >> v >> w;
		add(u, v, w);
		add(v, u, w);
	}
	dfs(1, 0);
	cout << ans << endl;
}
signed main() {
	solve();
}