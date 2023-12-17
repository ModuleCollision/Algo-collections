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

vector<pair< i64,  i64>>dir = {{1, 0}, { -1, 0}, {0, 1}, {0, -1}};
void solve() {
	 i64 n, m, r1, r2;
	std::cin >> n >> m >> r1 >> r2;
	vector<string>G(n + 5);
	for ( i64 i = 1; i <= n; i++) {
		std::cin >> G[i];
		G[i] = " " + G[i];
	}
	 i64 ex, ey, sx, sy;
	for ( i64 i = 1; i <= n; i++) {
		for ( i64 j = 1; j <= m; j++) {
			if (G[i][j] == 'P') {
				ex = i; ey = j;
			} else if (G[i][j] == 'M') {
				sx = i; sy = j;
			}
		}
	}
	auto check = [&]( i64 x,  i64 y) {
		return x >= 1 and x <= n and y >= 1 and y <= m;
	};
	vector<vector< i64>>dis1(n + 5, vector< i64>(m + 5, inf));
	vector<vector<bool>>vis1(n + 5, vector<bool>(m + 5, 0));
	auto dis2 = dis1; auto vis2 = vis1;
	auto bfs1 = [&]() {
		queue<pair< i64,  i64>>q;
		q.push({ex, ey});
		vis1[ex][ey] = 1;
		dis1[ex][ey] = 0;
		while (q.size()) {
			auto [x, y] = q.front();
			q.pop();
			for (auto [dx, dy] : dir) {
				 i64 xx = x + dx;  i64 yy = y + dy;
				if ((not check(xx, yy)) or vis1[xx][yy] or G[xx][yy] == '*') {
					continue;
				}
				dis1[xx][yy] = dis1[x][y] + 1;
				vis1[xx][yy] = 1; q.push({xx, yy});
			}
		}
	};
	auto bfs2 = [&]() {
		queue<pair< i64,  i64>>q;
		q.push({sx, sy});
		vis2[sx][sy] = 1;
		dis2[sx][sy] = 0;
		while (q.size()) {
			auto [x, y] = q.front();
			q.pop();
			for (auto [dx, dy] : dir) {
				 i64 xx = x + dx;  i64 yy = y + dy;
				if ((not check(xx, yy)) or vis2[xx][yy] or G[xx][yy] == '*') {
					continue;
				}
				dis2[xx][yy] = dis2[x][y] + 1;
				vis2[xx][yy] = 1; q.push({xx, yy});
			}
		}
	};
	bfs1(); bfs2();  i64 ans = inf;
	for ( i64 i = 1; i <= n; i++) {
		for ( i64 j = 1; j <= m; j++) {
			if (vis1[i][j] and vis2[i][j] and (abs(i - ex) + abs(j - ey) <= r1) and abs(i - sx) + abs(j - sy) <= r2) {
				ans = min(ans, dis1[i][j] + dis2[i][j]);
			}
		}
	}
	if (ans == inf) {
		puts("-1"); return;
	}
	cout << ans << endl;
}
signed main() {
	solve();
}