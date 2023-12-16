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

i64 n, m, q, t, s;
vector<i64>tr[maxn];
i64 dis[maxn], vis[maxn];
void solve() {
	std::cin >> n >> m >> q;

	for (i64 i = 1; i <= m; i++) {
		i64 u, v; std::cin >> u >> v;
		tr[u].push_back(v);
		tr[v].push_back(u);
	}
	while (q--) {
		std::cin >> t >> s;
		std::priority_queue<pair<i64, i64>, vector<pair<i64, i64>>, greater<pair<i64, i64>>>pq;
		memset(dis, 0x3f, sizeof(dis));
		memset(vis, 0, sizeof(vis));
		for (i64 i = 1; i <= t; i++) {
			i64 v; std::cin >> v; pq.push({0, v});
			dis[v] = 0;
		}
		while (pq.size()) {
			auto cur = pq.top();
			pq.pop();
			i64 u = cur.second, d = cur.first; vis[u] = 1;
			for (auto v : tr[u]) {
				if (dis[v] > dis[u] + 1) {
					dis[v] = min(dis[v], dis[u] + 1);
					if (not vis[v]) {
						pq.push({dis[v], v});
					}
				}
			}
		}
		i64 ans = 0;
		for (i64 i = 1; i <= n; i++) {
			if (dis[i] and dis[i] <= s) {
				ans++;
			}
		}
		cout << ans << endl;
	}
}
signed main() {
	solve();
}