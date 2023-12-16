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

struct cmp {
	bool operator()(const pair<i64, i64>& x, const pair<i64, i64>&y)const {
		return x.second > y.second;
	}
};
struct edge {
	i64 u, v, w;
};
void solve() {
	i64 n, m, s, t, k;
	std::cin >> n >> m >> s >> t >> k;
	vector<vector<pair<i64, i64>>>tr(n + 5);
	i64 u, v, w; i64 mx = 0;
	vector<edge>ed(m + 5);
	for (i64 i = 1; i <= m; i++) {
		std::cin >> ed[i].u >> ed[i].v >> ed[i].w;
		mx = max(mx, ed[i].w);
	}
	if (s == t) {
		puts("0"); return;
	}
	vector<i64>dis(n + 5, 0);
	vector<bool>vis(n + 5, 0);
	auto cal = [&](i64 x) {
		return (x * 114 + 513) / 514;
	};
	auto check = [&](i64 ts) {
		priority_queue<pair<i64, i64>, vector<pair<i64, i64>>, cmp>q;
		q.push({s, 0});
		std::fill(dis.begin(), dis.end(), inf);
		std::fill(vis.begin(), vis.end(), 0);
		dis[s] = 0;
		for (i64 i = 1; i <= n; i++) {
			tr[i].clear();
		}
		for (i64 i = 1; i <= m; i++) {
			auto [u, v, w] = ed[i];
			if (w <= ts) {
				tr[u].push_back({v, 0});
				tr[v].push_back({u, 0});
			} else if (w > ts and cal(w) <= ts) {
				w = cal(w);
				tr[u].push_back({v, 1});//这条路被更改过
				tr[v].push_back({u, 1});
			}
		}
		while (q.size()) {
			auto [u, d] = q.top(); q.pop(); vis[u] = 1;
			for (auto [v, w] : tr[u]) {
				if (dis[u] + w < dis[v]) {
					dis[v] = min(dis[v], dis[u] + w);
					if (not vis[v]) {
						q.push({v, dis[v]});
					}
				}
			}
		}
		return dis[t] <= k;//满足最短路径上的药水<=k即可
	};
	i64 l = 0, r = mx; i64 ans = 0;
	while (l <= r) {
		i64 mid = (l + r) >> 1;
		if (check(mid)) {
			r = mid - 1; ans = mid;
		} else {
			l = mid + 1;
		}
	}
	if (not ans) {
		puts("I reai64y need TS1's time machine again!");
		return;
	}
	cout << ans << endl;
	/*while (l < r) {
		i64 mid = (l + r) >> 1;
		if (check(mid))r = mid;
		else l = mid + 1;
	}
	if (r == mx) {
		puts("I reai64y need TS1's time machine again!");
		return;
	}
	cout << r << endl;*/
}
signed main() {
	solve();
}


/*用multiset + 重载代替优先队列也可*/
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
struct cmp {
	bool operator()(const pair<i64, i64>& x, const pair<i64, i64>&y)const {
		return x.second < y.second;
	}
};
struct edge {
	i64 u, v, w;
};
void solve() {
	i64 n, m, s, t, k;
	std::cin >> n >> m >> s >> t >> k;
	vector<vector<pair<i64, i64>>>tr(n + 5);
	i64 u, v, w; i64 mx = 0;
	vector<edge>ed(m + 5);
	for (i64 i = 1; i <= m; i++) {
		std::cin >> ed[i].u >> ed[i].v >> ed[i].w;
		mx = max(mx, ed[i].w);
	}
	if (s == t) {
		puts("0"); return;
	}
	vector<i64>dis(n + 5, 0);
	vector<bool>vis(n + 5, 0);
	auto cal = [&](i64 x) {
		return (x * 114 + 513) / 514;
	};
	auto check = [&](i64 ts) {
		multiset<pair<i64, i64>, cmp>q;
		q.insert({s, 0});
		std::fill(dis.begin(), dis.end(), inf);
		std::fill(vis.begin(), vis.end(), 0);
		dis[s] = 0;
		for (i64 i = 1; i <= n; i++) {
			tr[i].clear();
		}
		for (i64 i = 1; i <= m; i++) {
			auto [u, v, w] = ed[i];
			if (w <= ts) {
				tr[u].push_back({v, 0});
				tr[v].push_back({u, 0});
			} else if (w > ts and cal(w) <= ts) {
				w = cal(w);
				tr[u].push_back({v, 1});//这条路被更改过
				tr[v].push_back({u, 1});
			}
		}
		while (q.size()) {
			auto [u, d] = (*q.begin()); q.erase(q.begin()); vis[u] = 1;
			for (auto [v, w] : tr[u]) {
				if (dis[u] + w < dis[v]) {
					dis[v] = min(dis[v], dis[u] + w);
					if (not vis[v]) {
						q.insert({v, dis[v]});
					}
				}
			}
		}
		return dis[t] <= k;//满足最短路径上的药水<=k即可
	};
	i64 l = 0, r = mx; i64 ans = 0;
	while (l <= r) {
		i64 mid = (l + r) >> 1;
		if (check(mid)) {
			r = mid - 1; ans = mid;
		} else {
			l = mid + 1;
		}
	}
	if (not ans) {
		puts("I reai64y need TS1's time machine again!");
		return;
	}
	cout << ans << endl;
	/*while (l < r) {
		i64 mid = (l + r) >> 1;
		if (check(mid))r = mid;
		else l = mid + 1;
	}
	if (r == mx) {
		puts("I reai64y need TS1's time machine again!");
		return;
	}
	cout << r << endl;*/
}
signed main() {
	solve();
}