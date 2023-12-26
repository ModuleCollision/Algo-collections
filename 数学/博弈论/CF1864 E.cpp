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

i64 tr[4 * maxn][2]; i64 tot = 0; i64  cnt[maxn];
void insert(i64 x) {
	i64 u = 0;
	for (i64 i = 29; i >= 0; i--) {
		i64 cur = (x >> i) & 1;
		cnt[u]++;
		if (not tr[u][cur])tr[u][cur] = ++tot;
		u = tr[u][cur];
	}
	cnt[u]++;
}
i64 ans = 0;
void dfs2(i64 x, i64 k) {
	if (tr[x][0] and tr[x][1]) {
		i64 i = k + 1;
		i64 f1 = (i + 1) - (i % 2 == 1);
		i64 f2 = i + (i % 2 == 1);
		ans = (ans % mod + (f1 + f2) % mod * cnt[tr[x][0]] % mod * cnt[tr[x][1]]) % mod;
	}
	if (not tr[x][0] and not tr[x][1]) {
		i64 i = k + 1;
		ans = (ans % mod + i * cnt[x] % mod * cnt[x] % mod) % mod;
	}
	if (tr[x][0])dfs2(tr[x][0], k);
	if (tr[x][1])dfs2(tr[x][1], k + 1);
}
i64 inv(i64 x) {
	i64 b = mod - 2; i64 ret = 1;
	while (b) {
		if (b & 1)ret = ret * x % mod;
		x = x * x % mod;
		b >>= 1;
	}
	return ret;
}
void solve() {
	memset(tr, 0, sizeof(tr)); memset(cnt, 0, sizeof(cnt));
	tot = 0; ans = 0;
	i64 n; std::cin >> n;
	for (i64 i = 1; i <= n; i++) {
		i64 x; std::cin >> x; insert(x);
	}
	dfs2(0, 0);
	cout << ans *inv(n) % mod*inv(n) % mod << endl;
}
signed main() {
	i64 T; std::cin >> T;
	while (T--)
		solve();
}