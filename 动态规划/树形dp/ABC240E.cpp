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

vector<i64>tr[maxn];
i64 l[maxn], r[maxn], n, tot = 0;
void solve() {
	memset(l, 0x3f, sizeof(l));
	std::cin >> n;
	for (i64 i = 1; i < n; i++) {
		i64 u, v;
		std::cin >> u >> v;
		tr[u].push_back(v);
		tr[v].push_back(u);
	}
	function<void(i64, i64)>dfs = [&](i64 u, i64 f) {
		if (tr[u].size() == 1 and u != 1) {
			++tot; l[u] = tot, r[u] = tot;
			return;
		}
		for (auto c : tr[u]) {
			if (c == f)continue;
			dfs(c, u);
			l[u] = min(l[u], l[c]);
			r[u] = max(r[u], r[c]);
		}
	};
	dfs(1, 0);
	for (i64 i = 1; i <= n; i++) {
		cout << l[i] << " " << r[i] << endl;
	}
}
//实际上相当于将父子关系抽象为子集关系,尽量压缩子集
//贪心+dfs
signed main() {
	solve();
}