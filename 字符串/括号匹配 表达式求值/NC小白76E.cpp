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
	string s; std::cin >> s;
	s = " " + s;
	std::set<i64>st; i64 k1 = 0, k2 = 0;
	for (i64 i = 1; i <= n; i++) {
		if (s[i] == '(')k1++; else k2++;
	}
	if (k1 != k2) {
		puts("-1"); return;
	}
	i64 ans = 0;
	for (i64 i = 1; i <= n; i++) {
		if (s[i] == '(')st.insert(i);
	}
	for (i64 i = 1; i <= n; i++) {
		if (s[i] == ')') {
			i64 cur = *st.begin();
			if (cur < i) {
				st.erase(st.begin());
			} else {
				ans += cur - i;
				swap(s[cur], s[i]);
				st.erase(st.begin());
				st.insert(i);
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