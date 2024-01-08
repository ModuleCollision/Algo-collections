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

void solve() {
	i64 n, m, k; std::cin >> n >> m >> k;
	vector<i64>h(n + 5, 0);
	vector<vector<i64>>tr(n + 1);
	vector<i64>d(n + 5, 0), w(n + 5, 0);
	queue<i64>q;
	for (i64 i = 1; i <= n; i++)cin >> h[i];
	for (i64 i = 1; i <= m; i++) {
		i64 u, v; std::cin >> u >> v;
		tr[u].push_back(v); w[v]++;
	}
	vector<pair<i64, i64>>p;
	for (i64 i = 1; i <= n; i++) {
		if (not w[i]) {
			q.push(i); p.push_back({i, h[i]});
		}
	}
	while (q.size()) {
		auto u = q.front(); q.pop();
		for (auto v : tr[u]) {
			w[v]--;
			d[v] = max(d[v], d[u] + (h[u] > h[v]));
			if (not w[v])q.push(v);
		}
	}
	i64 ws = 0;
	for (i64 i = 1; i <= n; i++) {
		ws = max(ws, d[i] * k + h[i]);
	}
	i64 ans = inf;
	function<void(i64)>dfs = [&](i64 x) {
		d[x]++;
		ws = max(ws, d[x] * k + h[x]);
		for (auto v : tr[x]) {
			if (d[v] < (d[x] + (h[x] > h[v])))dfs(v);
		}
	};
	std::sort(p.begin(), p.end(), [&](auto x, auto y)->bool{
		return x.second < y.second;
	});
	for (i64 i = 0; i < p.size(); i++) {
		ans = min(ans, ws - p[i].se);
		dfs(p[i].first);
	}
	cout << ans << endl;
}
signed main() {
	i64 T; std::cin >> T;
	while (T--)
		solve();
}