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


void solve() {
	i64 n; std::cin >> n;
	vector<i64>p(n + 5, 0);
	for (i64 i = 1; i <= n; i++)cin >> p[i];
	i64 idx = 1;
	while (idx + 1 <= n and p[idx + 1] < p[idx])idx++;
	vector<i64>tr1(n + 5, 0), tr2(n + 5, 0);
	auto add1 = [&](i64 idx, i64 v) {
		for (; idx <= n; idx += (idx & -idx))tr1[idx] += v;
	};
	auto query1 = [&](i64 idx) {
		i64 ret = 0;
		for (; idx >= 1; idx -= (idx & -idx))ret += tr1[idx];
		return ret;
	};
	auto add2 = [&](i64 idx, i64 v) {
		for (; idx <= n; idx += (idx & -idx))tr2[idx] += v;
	};
	auto query2 = [&](i64 idx) {
		i64 ret = 0;
		for (; idx >= 1; idx -= (idx & -idx))ret += tr2[idx];
		return ret;
	};
	std::set<i64>st; st.insert(0);
	vector<bool>w(n + 5, 0);
	for (i64 i = 1; i <= n; i++) {
		auto c = st.lower_bound(p[i]); c--;
		if (c == st.begin()) {
			w[i] = 1;
		}
		st.insert(p[i]);
	}
	i64 cnt = 0;
	/*for (i64 i = 1; i <= n; i++) {
		cout << w[i] << " ";
	}*/
	//cout << endl;
	for (i64 i = 1; i <= n; i++) {
		if (w[i]) {
			add1(p[i], 1); continue;
		}
		auto q1 = query1(p[i] - 1);
		auto q2 = query2(p[i] - 1);
		if (q1 and not q2) {
			add2(p[i], 1); cnt++;
			continue;
		}
	}
	cout << cnt << endl;
}
signed main() {
	i64 T; std::cin >> T;
	while (T--)
		solve();
}