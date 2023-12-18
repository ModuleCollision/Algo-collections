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

/*我们这里开三个维度来记录图上的距离以及访问等状态*/
char G[maxn][maxn];
 i64 N, M;
vector<pair< i64,  i64>>dir = {{1, 0}, { -1, 0}, {0, 1}, {0, -1}};
bool vis[maxn][maxn][2];  i64 dis[maxn][maxn][2];
struct Node {
	 i64 x;  i64 y; bool f;
};
void solve() {
	std::cin >> N >> M;
	for ( i64 i = 1; i <= N; i++) {
		std::cin >> (G[i] + 1);
	}
	memset(dis, 0x3f, sizeof(dis));
	auto check = [&]( i64 x,  i64 y) {
		return x >= 1 and x <= N and y >= 1 and y <= M and G[x][y] != 'W';
	};
	queue<Node>q;
	 i64 sx, sy, tx, ty;
	for ( i64 i = 1; i <= N; i++) {
		for ( i64 j = 1; j <= M; j++) {
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
		bool f = cur.f;  i64 x = cur.x, y = cur.y;
		for (auto d : dir) {
			 i64 dx = d.first, dy = d.second;
			 i64 xx = x + dx, yy = y + dy;
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