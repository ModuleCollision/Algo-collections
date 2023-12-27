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
	string s; i64 pos;
	cin >> s >> pos;
	i64 n = s.size();
	s = " " + s; vector<i64>l(n + 5), r(n + 5);
	for (i64 i = 0; i <= n; i++)r[i] = i + 1;
	for (i64 i = 1; i <= n + 1; i++)l[i] = i - 1;
	std::set<i64>st;
	auto del = [&](i64 x) {
		st.erase(x);
		r[l[x]] = r[x];
		l[r[x]] = l[x];
		if (l[x] >= 1 and r[x] <= n and s[l[x]] > s[r[x]])st.insert(l[x]);
	};
	for (i64 i = 1; i <= n - 1; i++) {
		if (s[i] > s[i + 1]) {
			st.insert(i);
		}
	}
	for (i64 i = n; i >= 1; i--) {
		if (pos <= i) {
			i64 t = 0;
			for (i64 j = 0; j < pos; j++)t = r[t];
			cout << s[t];
			break;
		}
		pos -= i;
		if (st.size()) {
			del(*st.begin());
		} else {
			del(l[n + 1]);
		}
	}
}
signed main() {
	i64 T; std::cin >> T;
	while (T--)
		solve();
}