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
	i64 n, c, d; std::cin >> n >> c >> d;
	vector<i64>A(n + 5, 0); std::set<i64>st;
	i64 p = 0;
	for (i64 i = 1; i <= n; i++) {
		std::cin >> A[i]; if (st.count(A[i]))p += c;
		else st.insert(A[i]);
	}
	vector<i64>k(n + 5, 0); i64 tot = 0;
	for (auto c : st) {
		k[++tot] = c;
	}
	i64 ans = inf;
	for (i64 i = 1; i <= tot; i++) {
		ans = min(ans, (k[i] - i) * d + (tot - i) * c);
	}
	ans = min(ans, tot * c + d);
	cout << ans + p << endl;
}
signed main() {
	i64 T; std::cin >> T;
	while (T--)solve();
}