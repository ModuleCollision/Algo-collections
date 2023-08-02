#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 5e2 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
/*我们这里开三个维度来记录图上的距离以及访问等状态*/
char G[maxn][maxn];
ll N, M;
vector<pair<ll, ll>>dir = {{1, 0}, { -1, 0}, {0, 1}, {0, -1}};
bool vis[maxn][maxn][2]; ll dis[maxn][maxn][2];
struct Node {
	ll x; ll y; bool f;
};
void solve() {
	std::cin >> N >> M;
	for (ll i = 1; i <= N; i++) {
		std::cin >> (G[i] + 1);
	}
	memset(dis, 0x3f, sizeof(dis));
	auto check = [&](ll x, ll y) {
		return x >= 1 and x <= N and y >= 1 and y <= M and G[x][y] != 'W';
	};
	queue<Node>q;
	ll sx, sy, tx, ty;
	for (ll i = 1; i <= N; i++) {
		for (ll j = 1; j <= M; j++) {
			if (G[i][j] == 'S') {
				sx = i; sy = j;
			} else if (G[i][j] == 'E') {
				tx = i; ty = j;
			}
		}
	}
	q.push({sx, sy, 0});
	dis[sx][sy][0] = 0; vis[sx][sy][0] = 1;
	while (not q.empty()) {
		auto cur = q.front(); q.pop();
		bool f = cur.f; ll x = cur.x, y = cur.y;
		for (auto d : dir) {
			ll dx = d.first, dy = d.second;
			ll xx = x + dx, yy = y + dy;
			if (not check(xx, yy))continue;
			if (vis[xx][yy][f])continue;
			if (G[xx][yy] == 'D') {
				if (not f)continue;
				else q.push({xx, yy, f}), vis[xx][yy][f] = 1, dis[xx][yy][f] = dis[x][y][f] + 1;
			} else if (G[xx][yy] == 'K') {
				q.push({xx, yy, 1}), vis[xx][yy][1] = 1, dis[xx][yy][1] = dis[x][y][f] + 1;
			} else {
				q.push({xx, yy, f}), vis[xx][yy][f] = 1, dis[xx][yy][f] = dis[x][y][f] + 1;
			}
		}
	}
	cout << min(dis[tx][ty][0], dis[tx][ty][1]) << endl;
}
signed main() {
	solve();
}