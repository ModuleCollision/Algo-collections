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

i64 tr[maxn][3]; i64 tot = 0;
void insert(i64 s) {
	i64 u = 0;
	for (i64 i = 31; i >= 0; i--) {
		i64 cur = ((s >> i) & 1);
		if (not tr[u][cur])tr[u][cur] = ++tot;
		u = tr[u][cur];
	}
}
i64 ans = 0;
void dfs(i64 s) {
	i64 u = 0;
	i64 res = 0;
	for (i64 i = 31; i >= 0; i--) {
		i64 cur = ((s >> i) & 1);
		if (i == 31) {
			if (tr[u][cur])u = tr[u][cur];
			else u = tr[u][cur ^ 1], res |= (1 << i);
		} else {
			if (tr[u][cur ^ 1])u = tr[u][cur ^ 1], res |= (1 << i);
			else u = tr[u][cur];
		}
	}
	ans = max(res, ans);
}
void solve() {
	i64 n; std::cin >> n;
	vector<i64>A(n + 5, 0);
	insert(0);
	for (i64 i = 1; i <= n; i++)cin >> A[i];
	dfs(0);
	for (i64 i = 1; i <= n; i++) {
		A[i] ^= A[i - 1];
		dfs(A[i]);
		insert(A[i]);
	}
	cout << ans << endl;
}
signed main() {
	solve();
}