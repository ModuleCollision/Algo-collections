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
	i64 n; string s; std::cin >> n >> s;
	s = " " + s;
	std::set<i64>st;
	vector<i64>pre(n + 5, 0); i64 tot = 0;
	for (i64 i = 1, cur = 0; i <= n; i++) {
		pre[i] += pre[i - 1];
		if (s[i] == '0') {
			cur = 1; st.insert(i);
		} else if (s[i] == '1') {
			cur ^= 1;
		}
		pre[i] += cur;
	}
	i64 ans = 0;
	for (i64 i = 1; i <= n; i++) {
		i64 cur = s[i] - '0';
		auto idx = st.upper_bound(i);
		if (idx == st.end()) {
			ans += cur;
			i64 d = n - i;
			if (cur == 1)ans += d / 2;
			else ans += (d + 1) / 2;
		} else {
			ans += cur;
			i64 d = (*idx) - i - 1;
			if (cur == 1)ans += d / 2;
			else ans += (d + 1) / 2;
			ans += pre[n] - pre[(*idx) - 1];
		}
	}
	cout << ans << endl;
}
signed main() {
	solve();
}