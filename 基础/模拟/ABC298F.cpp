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
	std::multiset< i64>st;
	vector<array< i64, 3>>A(n + 5);
	vector<map< i64,  i64>>vv(2);
	map< i64, std::set< i64>>re;
	for ( i64 i = 1; i <= n; i++) {
		cin >> A[i][0] >> A[i][1] >> A[i][2];
		vv[0][A[i][0]] += A[i][2];
		re[A[i][0]].insert(A[i][1]);
		vv[1][A[i][1]] += A[i][2];
	}
	 i64 ans = 0;
	for ( i64 i = 1; i <= n; i++) {
		ans = max(ans, vv[0][A[i][0]] + vv[1][A[i][1]] - A[i][2]);
	}

	for (auto [r, v] : vv[1]) {
		st.insert(v);
	}
	st.insert(0);
	for (auto [l, v] : vv[0]) {
		for (auto r : re[l]) {
			 i64 v = vv[1][r];
			if (st.count(v))st.erase(st.find(v));
		}
		 i64 k = *(--st.end());
		for (auto r : re[l])st.insert(vv[1][r]);
		ans = max(ans, v + k);
	}
	cout << ans << endl;
}
signed main() {
	solve();
}