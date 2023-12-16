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

struct cmp {
	bool operator()(const pair< i64,  i64>&x, const pair< i64,  i64>&y)const {
		return x.se < y.se;
	}
};
void solve() {
	i64 n, m; std::cin >> n >> m;
	vector< i64>T(m + 1), W(m + 1), S(m + 1);
	for ( i64 i = 1; i <= m; i++) {
		cin >> T[i] >> W[i] >> S[i];
	}
	std::multiset< i64>st; std::multiset<pair< i64,  i64>, cmp>st2;
	for ( i64 i = 1; i <= n; i++)st.insert(i);
	vector< i64>ans(n + 1);
	for ( i64 i = 1; i <= m; i++) {
		while (st2.size() and st2.begin()->se <= T[i]) {
			st.insert(st2.begin()->fi);
			st2.erase(st2.begin());
		}
		if (not st.size())continue;
		auto idx = *st.begin(); st.erase(st.begin());
		ans[idx] += W[i]; st2.insert({idx, T[i] + S[i]});
	}
	for ( i64 i = 1; i <= n; i++) {
		cout << ans[i] << endl;
	}
}
signed main() {
	solve();
}