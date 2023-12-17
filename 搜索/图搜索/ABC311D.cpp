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
	 i64 n, m; std::cin >> n >> m;
	vector<string>s(n + 5);
	for ( i64 i = 1; i <= n; i++) {
		cin >> s[i]; s[i] = " " + s[i];
	}
	vector vis(n + 5, vector<bool>(m + 5, 0));
	auto vi = vis;
	auto bfs = [&]() {
		queue<pair< i64,  i64>>q;
		q.push({2, 2}); vis[2][2] = 1; vi[2][2] = 1;
		while (not q.empty()) {
			auto [x, y] = q.front(); q.pop();
			for (auto [dx, dy] : dir) {
				 i64 nx = x, ny = y;
				while (s[nx][ny] == '.') {
					vis[nx][ny] = 1;
					nx += dx; ny += dy;
				}
				nx -= dx, ny -= dy;
				if (vi[nx][ny])continue;
				vi[nx][ny] = 1;
				q.push({nx, ny});
			}
		}
	};
	bfs();
	 i64 cnt = 0;
	for ( i64 i = 1; i <= n; i++) {
		for ( i64 j = 1; j <= m; j++)if (vis[i][j])cnt++;
	}
	cout << cnt << endl;
}
signed main() {
	solve();
}