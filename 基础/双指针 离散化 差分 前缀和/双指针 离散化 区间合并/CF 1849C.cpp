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
	std::set<pair<i64, i64>>st;
	i64 n, m; std::cin >> n >> m;
	std::string s; cin >> s;
	s = " " + s;
	vector<i64>l(n + 5), r(n + 5); r[n + 1] = n + 1;
	for (i64 i = 1; i <= n; i++) {
		if (s[i] == '0')s[i] = i;
		else s[i] = s[i - 1];
	}
	for (i64 i = n; i >= 1; i--) {
		if (s[i] == '1')r[i] = i;
		else r[i] = r[i + 1];
	}
	for (i64 i = 1; i <= m; i++) {
		i64 x, y; cin >> x >> y;
		x = l[x], y = r[y];
		if (x >= y)st.insert({0, 0});
		else st.insert({x, y});
	}
	cout << st.size() << endl;
}
signed main() {
	i64 T; std::cin >> T;
	while (T--)
		solve();
}