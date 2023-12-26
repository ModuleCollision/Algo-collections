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

struct sq {
	i64 v[2]; i64 cnt = 0;
};
vector<sq>tr;
void add(i64 x) {
	i64 u = 0;
	for (i64 i = 29; i >= 0; i--) {
		i64 b = (x >> i) & 1;
		if (not tr[u].v[b]) {
			tr[u].v[b] = tr.size();
			tr.push_back(sq());
		}
		u = tr[u].v[b];
	}
	++tr[u].cnt;
}
void dfs1(i64 u) {
	for (i64 i = 0; i < 2; i++) {
		if (tr[u].v[i]) {
			dfs1(tr[u].v[i]);
			i64 v = tr[u].v[i];
			tr[u].cnt += tr[v].cnt;
		}
	}
}
i64 ksm(i64 x, i64 y) {
	i64 ret = 1;
	while (y) {
		if (y & 1)ret = ret * x % mod;
		x = x * x % mod;
		y >>= 1;
	}
	return ret % mod;
}
i64 ans = 0;
void dfs2(i64 x, i64 k) {
	if (tr[x].v[0] and tr[x].v[1]) {
		i64 i = k + 1;
		i64 f1 = (i + 1) - (i % 2 == 1);
		i64 f2 = i + (i % 2 == 1);
		ans = (ans % mod + (f1 + f2) % mod * tr[tr[x].v[0]].cnt % mod * tr[tr[x].v[1]].cnt) % mod;
	}
	if (not tr[x].v[0] and not tr[x].v[1]) {
		i64 i = k + 1;
		ans = (ans % mod + i * tr[x].cnt % mod * tr[x].cnt % mod) % mod;
	}
	if (tr[x].v[0])dfs2(tr[x].v[0], k);
	if (tr[x].v[1])dfs2(tr[x].v[1], k + 1);
}
void solve() {
	tr.clear(); tr.push_back(sq());
	i64 n; std::cin >> n;
	for (i64 i = 1; i <= n; i++) {
		i64 x; cin >> x; add(x);
	}
	ans = 0;
	dfs1(0); dfs2(0, 0);
	cout << ans % mod*ksm(n, mod - 2) % mod*ksm(n, mod - 2) % mod << endl;
}
signed main() {
	i64 T; std::cin >> T;
	while (T--)solve();
}