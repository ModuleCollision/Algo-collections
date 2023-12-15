/*300兆字节 1- 2 秒*/

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


vector<pair<int, int>>dir1{{0, 1}, {0, -1}, { -1, 0}, {1, 0}};
map<char, pair<int, int>>dir2;
bool vis[maxn][maxn];
int dis[maxn][maxn];
char G[maxn][maxn]; int xs, ys, n, m, Q;
bool check1(int x, int y) {
	return x >= 1 and x <= n and y >= 1 and y <= m and G[x][y] != '#' and not vis[x][y];
}
void bfs1() {
	queue<pair<int, int>>q;
	memset(dis, 0x3f, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	xs++; ys++;
	q.push({xs, ys});
	dis[xs][ys] = 0;
	vis[xs][ys] = 1;
	while (q.size()) {
		auto [x, y] = q.front();
		q.pop();
		for (auto [dx, dy] : dir1) {
			int xx = x + dx, yy = y + dy;
			if (not check1(xx, yy)) {
				continue;
			}
			vis[xx][yy] = 1; dis[xx][yy] = min(dis[xx][yy], dis[x][y] + 1);
			q.push({xx, yy});
		}
	}
}
int query(int x, int y) {
	int ret; int res = 1;
	while (1) {
		int lx = x, ly = y;
		auto [dx, dy] = dir2[G[x][y]];
		if (check1(x + dx, y + dy)) {
			x += dx; y += dy;
		}
		if (lx == x and ly == y) {
			if (not vis[x][y]) {
				return -1;
			}
		}
		if (dis[x][y] <= res) {
			ret = max(dis[x][y], res);
		}
		res++;
	}
	return ret;
}
void solve() {
	cin >> n >> m >> xs >> ys >> Q;
	for (i64 i = 1; i <= n; i++) {
		cin >> (G[i] + 1);
	}
	dir2['L'] = {0, -1}; dir2['R'] = {0, 1};
	dir2['D'] = {1, 0}; dir2['U'] = { -1, 0};
	bfs1();
	while (Q--) {
		int qx, qy; cin >> qx >> qy; qx++; qy++;
		cout << query(qx, qy) << endl;
		//cout << query(xx, yy) << endl;
	}
}
signed main() {
	solve();
}