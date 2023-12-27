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
	vector< i64>w(n + 5);
	vector<vector< i64>>tr(n + 1);
	for ( i64 i = 1; i <= n; i++)cin >> w[i];
	for ( i64 i = 1; i < n; i++) {
		 i64 u, v; std::cin >> u >> v;
		tr[u].push_back(v); tr[v].push_back(u);
	}
	std::multiset< i64>st;
	function<void( i64,  i64,  i64)>dfs = [&]( i64 u,  i64 f,  i64 dep) {
		//if (dep == 0)
		st.insert(w[u]);
		//else if (dep == 1)st.insert(w[u] + 1);
		//else st.insert(w[u] + 2);
		for (auto v : tr[u]) {
			if (v == f)continue;
			dfs(v, u, dep + 1);
		}
	};
	//利用了换根的思想
	dfs(1, 0, 0);  i64 ans = inf;
	function<void( i64,  i64)>dfs2 = [&]( i64 u,  i64 f) {
		 i64 t = -inf;
		t = max(t, w[u]);
		st.erase(st.find(w[u]));
		for (auto v : tr[u]) {
			t = max(t, w[v] + 1);
			st.erase(st.find(w[v]));
		}
		if (st.size() >= 1)
			t = max(t, *(--st.end()) + 2);
		ans = min(ans, t);
		for (auto v : tr[u]) {
			st.insert(w[v]);
		}
		st.insert(w[u]);
		for (auto v : tr[u]) {
			if (v == f)continue;
			dfs2(v, u);
		}
	};
	dfs2(1, 0);
	cout << ans << endl;
}
signed main() {
	solve();
}