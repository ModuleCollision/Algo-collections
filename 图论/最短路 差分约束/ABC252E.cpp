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

i64 N, M;
struct sq {
	i64 u; i64 w; i64 id;
};
struct cmp {
	bool operator()(array<i64, 2>x, array<i64, 2>y) {
		return x[0] >= y[0];
	}
};
i64 u, v, w;
;
void solve() {
	std::cin >> N >> M;
	vector<i64>dis(N + 5, inf); vector<bool>vis(N + 5);
	vector<vector<sq>>tr(N + 5);
	for (i64 i = 1; i <= M; i++) {
		std::cin >> u >> v >> w;
		tr[u].push_back({v, w, i});
		tr[v].push_back({u, w, i});
	}
	priority_queue<array<i64, 2>, vector<array<i64, 2>>, cmp>q;
	q.push({0, 1});
	dis[1] = 0; vector<i64>fa(N + 5);
	while (q.size()) {
		auto [d, u] = q.top();
		q.pop();
		vis[u] = 1;
		for (auto [v, w, idx] : tr[u]) {
			if (dis[v] > w + dis[u]) {
				dis[v] = min(dis[v], w + dis[u]);
				if (not vis[v]) {
					q.push({dis[v], v});
					fa[v] = idx;
				}
			}
		}
	}
	for (i64 i = 2; i <= N; i++) {
		cout << fa[i] << " ";
	}
	cout << endl;
}
signed main() {

	solve();
}
