#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 3e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
struct edge {
	int u; int v; int nx;
} e[maxn];
int n, m;
int head[maxn]; int cnt = 0;
int vis[maxn];
void pre() {
	memset(vis, 0, sizeof(vis));
	memset(head, 0xff, sizeof(head));
}
void add_edge(int u, int v) {
	e[cnt].u = u; e[cnt].v = v;
	e[cnt].nx = head[u]; head[u] = cnt++;
}
int c[maxn], sz[maxn], idx = 0;
int b_cnt = 0;
int dfs(int u, int f) {
	int s = 1;
	b_cnt += c[u]; vis[u] = 1;
	for (int eg = head[u]; eg != -1; eg = e[eg].nx) {
		int v = e[eg].v;
		if (v == f) {
			continue;
		}
		s += dfs(v, u);
	}
	return s;
}
signed main() {
	std::cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v; std::cin >> u >> v;
		add_edge(u, v); add_edge(v, u);
	}
	for (int i = 1; i <= n; i++) {
		std::cin >> c[i];
	}
	int ned = 0; int id = 0;
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			b_cnt = 0;
			++idx; sz[idx] = dfs(i, 0);
			ned += (b_cnt != 0);
			if (b_cnt) {
				id = idx;
			}
		}
	}
	if (ned == 0) {
		int ans = 0;
		for (int j = 1; j <= idx; j++) {
			ans += sz[j] * sz[j];
		}
		cout << ans << endl;
	} else if (ned == 1) {
		int ans = 0;
		ans = sz[id] * sz[id];
		cout << ans << endl;
	} else {
		cout << 0 << endl;
	}
	return 0;
}
