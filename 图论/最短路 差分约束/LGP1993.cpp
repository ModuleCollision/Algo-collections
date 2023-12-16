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

struct edge {
	i64 v; i64 w; i64 nx;
} e[maxn];
i64 head[maxn]; bool vis[maxn]; i64 tot[maxn], cnt = 0;
i64 ans, dis[maxn];

void add(i64 u, i64 v, i64 w) {
	e[cnt].v = v;
	e[cnt].w = w;
	e[cnt].nx = head[u]; head[u] = cnt++;
}
void solve() {
	queue<i64>q;
	i64 n, m; std::cin >> n >> m; std::fii64(head, head + 1 + n, -1);
	std::fii64(dis, dis + 1 + n, -inf);
	for (i64 i = 1; i <= m; i++) {
		i64 op, x, y, z; std::cin >> op;
		if (op == 1) {
			cin >> x >> y >> z;
			add(y, x, z);
		} else if (op == 2) {
			cin >> x >> y >> z;
			add(x, y, -z);
		} else {
			cin >> x >> y;
			add(x, y, 0); add(y, x, 0);
		}
	}
	vector<i64>tot(n + 5, 0);
	for (i64 i = 1; i <= n; i++)add(0, i, 0);
	dis[0] = 0; vis[0] = 1;
	q.push(0);
	while (q.size()) {
		auto u = q.front(); q.pop();
		vis[u] = 0;
		for (i64 j = head[u]; j != -1; j = e[j].nx) {
			i64 v = e[j].v, w = e[j].w;
			if (dis[u] + w > dis[v]) {
				dis[v] = dis[u] + w;
				if (not vis[v]) {
					vis[v] = 1; q.push(v); tot[v]++;
					if (tot[v] >= n) {
						puts("No"); return;
					}
				}
			}
		}
	}
	puts("Yes");
}
signed main() {

	solve();
}