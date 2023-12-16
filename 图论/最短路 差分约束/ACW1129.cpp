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

struct sq {
	i64 u; i64 d;
	bool operator<(const sq &b)const {
		return d > b.d;
	}
};
priority_queue<sq>q;
vector<pair<i64, i64>>tr[maxn];
vector<i64>dis(maxn, inf);
vector<bool>vis(maxn, false);
i64 n, m, s, t, u, v, w;
void solve() {
	cin >> n >> m >> s >> t;
	for (i64 i = 1; i <= m; i++) {
		cin >> u >> v >> w;
		tr[u].push_back({v, w});
		tr[v].push_back({u, w});
	}
	dis[s] = 0;
	q.push({s, 0});
	auto dijkstra = [&]() {
		while (!q.empty()) {
			auto [u, d] = q.top();
			q.pop();
			vis[u] = true;
			for (auto [v, w] : tr[u]) {
				if (dis[v] > dis[u] + w) {
					dis[v] = min(dis[v], dis[u] + w);
					if (not vis[v]) {
						q.push({v, dis[v]});
					}
				}
			}
		}
	};
	dijkstra();
	cout << dis[t] << endl;
}
signed main() {
	solve();
}

