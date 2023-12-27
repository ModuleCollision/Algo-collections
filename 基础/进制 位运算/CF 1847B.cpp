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
	vector<i64>A(n + 5, 0); i64 fsm = 0;
	for (i64 i = 1; i <= n; i++) {
		cin >> A[i];
		for (i64 j = 0; A[i] >> j; j++) {
			fsm = max(fsm, j);
		}
	}
	vector<bool>f(fsm + 5, 0);
	for (i64 i = 1; i <= n; i++) {
		for (i64 j = 0; j <= fsm; j++) {
			if (((A[i] >> j) & 1) == 0) {
				f[j] = 1;
			}
		}
	}

	vector pre(n + 5, vector<i64>(fsm + 5, 0));
	i64 tot = A[1];
	for (i64 i = 2; i <= n; i++) {
		tot &= A[i];
	}
	for (i64 i = 1; i <= n; i++) {
		for (i64 j = 0; j <= fsm; j++) {
			pre[i][j] += pre[i - 1][j];
			if (((A[i] >> j) & 1) == 0)pre[i][j]++;
		}
	}
	if (tot > 0) {
		cout << 1 << endl; return;
	}
	i64 ans = 0;
	for (i64 i = 1; i <= n; i++) {
		i64 l = i; i64 cur = A[i];
		while (i + 1 <= n and cur != tot) {
			cur &= A[i + 1]; i++;
		}
		ans++;
		for (i64 j = 0; j <= fsm; j++) {
			if (f[j] and pre[i][j] == pre[n][j]) {
				cout << ans << endl; return;
			}
		}
	}
	cout << ans << endl;
}
signed main() {
	i64 T; std::cin >> T;
	while (T--)
		solve();
}