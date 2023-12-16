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
	i64 n, p, x, q, y; std::cin >> n >> p >> x >> q >> y;
	i64 tot = 0;
	for (i64 i = 1; i <= n; i++) {
		i64 v; std::cin >> v;
		tot = (tot % n + v) % n;
	}
	priority_queue<pair<i64, i64>, vector<pair<i64, i64>>, greater<pair<i64, i64>>>que;
	vector<vector<pair<i64, i64>>>tr(n + 1);
	for (i64 i = 0; i < n; i++) {
		i64 v = (i + x) % n;
		tr[i + 1].push_back({v + 1, p});
		v = ((i - y) % n + n) % n;
		tr[i + 1].push_back({v + 1, q});
	}
	vector<i64>dis(n + 5, inf);
	auto dij = [&]() {

		que.push({0, tot + 1});
		dis[tot + 1] = 0; vector<bool>vis(n + 5, false);
		while (que.size()) {
			auto [d, u] = que.top();
			que.pop(); vis[u] = 1;
			for (auto [v, w] : tr[u]) {
				if (dis[u] + w < dis[v]) {
					dis[v] = dis[u] + w;
					if (not vis[v]) {
						que.push({vis[v], v});
					}
				}
			}
		}
	};
	dij();
	if (dis[1] == inf) {
		puts("-1");
	} else {
		cout << dis[1] << endl;
	}
}
signed main() {

	solve();
}