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

/*此题可抽象为在二维平面进行搜索*/
void solve() {
	i64 N, M; std::cin >> N >> M;
	vector<i64>C(N + 5);
	for (i64 i = 1; i <= N; i++)std::cin >> C[i];
	vector<i64>tr[N + 5]; i64 u, v;
	for (i64 i = 1; i <= M; i++) {
		std::cin >> u >> v;
		tr[u].push_back(v);
		tr[v].push_back(u);
	}
	i64 dis[N + 5][N + 5]; bool vis[N + 5][N + 5];
	memset(vis, 0, sizeof(vis));
	memset(dis, 0x3f, sizeof(dis));
	dis[1][N] = 0; vis[1][N] = 1;
	queue<pair<i64, i64>>q;
	q.push({1, N});
	while (not q.empty()) {
		auto cur = q.front(); q.pop();
		i64 u = cur.first, v = cur.second;
		for (auto uu : tr[u]) {
			for (auto vv : tr[v]) {
				if (C[uu]^C[vv] and not vis[uu][vv]) {
					dis[uu][vv] = min(dis[uu][vv], dis[u][v] + 1);
					q.push({uu, vv});
					vis[uu][vv] = 1;
				}
			}
		}
	}
	if (not vis[N][1]) {
		puts("-1");
	} else {
		cout << dis[N][1] << endl;
	}
}
i64 T;
signed main() {
	std::cin >> T;
	while (T--)
		solve();
}