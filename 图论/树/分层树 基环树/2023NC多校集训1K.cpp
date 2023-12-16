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
	i64 n, m = 0, k = 0; std::cin >> n >> m >> k;
	vector<vector<pair<i64, i64>>>tr(n + 5);
	vector<pair<i64, i64>>e(m + 5); vector<i64>d(n + 5, 0);
	for (i64 i = 1; i <= m; i++) {
		i64 u, v; std::cin >> u >> v;
		d[u]++; d[v]++;
		tr[u].push_back({i, v});
		tr[v].push_back({i, u});
		e[i] = {u, v};
	}
	vector<bool>vis(m + 5, 0);
	queue<i64>q; q.push(1); i64 res = 0;
	vector<i64>dis(n + 5, -1); dis[1] = 0; i64 maxd = 0;
	while (q.size()) {
		auto u = q.front(); q.pop();
		maxd = max(maxd, dis[u]);
		if (dis[u] <= k)res++;
		for (auto [idx, v] : tr[u]) {
			if (dis[v] != -1)continue;
			dis[v] = dis[u] + 1;
			q.push(v);
			vis[idx] = 1;
		}
	}
	std::map<i64, vector<i64>>ws;
	for (i64 i = 1; i <= n; i++) {
		ws[dis[i]].push_back(i);
		//cout << "#" << dis[i] << endl;
	}
	//cout << "#" << dis[2] << endl;
	for (i64 i = 1; i <= min(maxd, k - 1); i++) {
		for (auto u : ws[i]) {
			if (d[u] == 1)res += k - i;
			//continue;
			for (auto [idx, v] : tr[u]) {
				if (vis[idx])continue;
				res += k - i;
			}
		}
	}
	//if (res == 13)res += 2;
	cout << res << endl;
}
signed main() {
	solve();
}