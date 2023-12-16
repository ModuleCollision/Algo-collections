/*非实时查询的模拟, 可以离线后考虑简化处理*/
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
	i64 n, m, q; std::cin >> n >> m >> q;
	vector<string>op1(q + 5); vector<string>op2(q + 5);
	vector< i64>v(q + 5, 0);
	for ( i64 i = 1; i <= q; i++) {
		std::cin >> op1[i] >> v[i] >> op2[i];
	}
	i64 cnt1 = 0, cnt2 = 0;
	i64 ans = 0;
	vector<bool>vis1(n + 5, false), vis2(m + 5, false);
	for ( i64 i = q; i >= 1; i--) {
		if (op1[i] == "row") {
			if (not vis1[v[i]]) {
				vis1[v[i]] = 1;
				if (op2[i] == "on")ans += max(0 i64, m - cnt2);
				cnt1++;
			}
		} else {
			if (not vis2[v[i]]) {
				vis2[v[i]] = 1;
				if (op2[i] == "on")ans += max(0 i64, n - cnt1);
				cnt2++;
			}
		}
	}
	cout << ans << endl;
}
signed main() {
	solve();
}