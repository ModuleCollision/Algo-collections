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
	std::priority_queue< i64>q1, q2, q3;
	i64 n, m; std::cin >> n >> m;
	vector< i64>X(n + 5), Y(n + 5);
	for ( i64 i = 1; i <= n; i++) {
		i64 t, x; std::cin >> t >> x;
		if (t == 0) {
			q1.push(x);
		} else if (t == 1)q2.push(x);
		else q3.push(x);
	}
	for ( i64 i = 1; i <= n; i++) {
		if (not q1.size())continue;
		X[i] = X[i - 1] + q1.top(); q1.pop();
	}
	i64 cur = 0;
	for ( i64 i = 1; i <= n; i++) {
		Y[i] += Y[i - 1];
		if (not cur and q3.empty())continue;
		else if (not cur and not q3.empty()) {
			cur += q3.top(); q3.pop(); continue;
		} else if (cur and q2.size()) {
			Y[i] += q2.top(); q2.pop(); cur--;
		}
	}
	i64 ans = 0;
	for ( i64 i = 0; i <= m; i++) {
		ans = max(ans, X[i] + Y[m - i]);
	}
	cout << ans << endl;
}
signed main() {
	solve();
}