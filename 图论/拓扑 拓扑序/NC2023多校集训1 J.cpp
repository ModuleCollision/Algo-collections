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
	i64 n, m; std::cin >> n >> m;
	vector<vector<i64>>tr(n + 1);
	vector<pair<i64, i64>>edge(m + 5);
	vector<i64>d(n + 1, 0);
	for (i64 i = 1; i <= m; i++) {
		i64 u, v; std::cin >> u >> v; tr[u].push_back(v);
		d[v]++;
		edge[i] = {u, v};
	}
	queue<i64>q;
	for (i64 i = 1; i <= n; i++) {
		if (not d[i])q.push(i);
	}
	vector<i64>ans; i64 tot = 0;
	while (q.size()) {
		auto u = q.front(); q.pop();
		ans.push_back(u);
		for (auto v : tr[u]) {
			d[v]--;
			if (not d[v]) {
				q.push(v);
			}
		}
	}
	if (ans.size() == n) {
		cout << 1 << endl;
		for (auto c : ans) {
			cout << c << " ";
		}
		cout << endl;
	} else {
		cout << 2 << endl;
		for (i64 i = 1; i <= n; i++) {
			cout << i << " ";
		}
		cout << endl;
		for (i64 i = n; i >= 1; i--) {
			cout << i << " ";
		}
		cout << endl;
	}
}
signed main() {
	solve();
}