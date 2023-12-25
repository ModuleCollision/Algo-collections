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

int main() {
	i64 n, m, k, w; std::cin >> n >> m >> k >> w;
	vector<vector<i64>>tr(n + 5);
	vector<i64>p(n + 5, 0), x(n + 5, 0);
	for (i64 i = 1; i <= n; i++)cin >> p[i];
	for (i64 i = 1; i <= n; i++)cin >> x[i];
	for (i64 i = 1; i <= m; i++) {
		i64 u, v; std::cin >> u >> v;
		tr[u].push_back(v);
		tr[v].push_back(u);
	}
	vector<i64>f;
	vector<bool>vis(n + 5, 0);
	auto bfs = [&](i64 idx) {
		i64 tot = 0;
		queue<i64>q; q.push(idx); vis[idx] = 1;
		while (q.size()) {
			auto u = q.front(); q.pop();
			tot += p[u];
			for (auto v : tr[u]) {
				if (x[v] != 1 or vis[v])continue;
				vis[v] = 1; q.push(v);
			}
		}
		return tot;
	};
	for (i64 i = 1; i <= n; i++) {
		if (vis[i] or x[i] != 1)continue;
		f.push_back(bfs(i));
	}
	std::sort(f.begin(), f.end(), [&](i64 x, i64 y)->bool{
		return x > y;
	});
	i64 ans = 0;
	for (i64 i = 0; i < min(k, (i64)f.size()); i++)ans += f[i];
	std::cout << ans << "\n";
}