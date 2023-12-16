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

i64 co[maxn]; vector<i64>tr[maxn];
i64 sz[5]; i64 N, M, cnt = 0;
void solve() {
	std::cin >> N >> M;
	for (i64 i = 1; i <= M; i++) {
		i64 u, v;
		std::cin >> u >> v;
		tr[u].push_back(v);
		tr[v].push_back(u);
	}
	bool f = 1;
	function<bool(i64)>dfs = [&](i64 u) {
		cnt += tr[u].size();
		for (auto v : tr[u]) {
			if (co[v]) {
				if (co[v] == co[u]) {
					return false;
				}
			} else {
				co[v] = 3 - co[u];
				sz[co[v]]++;
				bool f = dfs(v); if (not f)return false;
			}
		}
		return true;
	};
	i64 ans1 = 0, ans2 = 0;
	for (i64 i = 1; i <= N; i++) {
		if (not co[i]) {
			cnt = 0; sz[1] = sz[2] = 0;
			co[i] = 1; bool ff = dfs(i);
			sz[co[i]]++;
			if (not ff) {
				puts("0"); return;
			}
			ans1 += sz[1] * sz[2] - cnt / 2;
			ans2 += (sz[1] + sz[2]) * (N - (sz[1] + sz[2]));
		}
	}/*分成不同可以组成二部图的连通块*/
	cout << ans1 + ans2 / 2 << endl;
}
signed main() {
	solve();
}


/*两种判断二分图的方式*/
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

i64 co[maxn];
i64 sz[5]; i64 N, M, cnt = 0;
void solve() {
	std::cin >> N >> M; vector<vector<i64>>tr(N + 5);
	for (i64 i = 1; i <= M; i++) {
		i64 u, v;
		std::cin >> u >> v;
		tr[u].push_back(v);
		tr[v].push_back(u);
	}
	bool f = 1;
	function<void(i64)>dfs = [&](i64 u) {
		cnt += tr[u].size();//边的度数 = 连通块的点数 * 2
		for (auto v : tr[u]) {
			if (co[v]) {
				if (co[v] == co[u]) {
					f = false; return;
				}
			} else {
				co[v] = 3 - co[u];
				sz[co[v]]++;
				dfs(v);
			}
		}
	};
	i64 ans1 = 0, ans2 = 0;
	for (i64 i = 1; i <= N; i++) {
		if (not co[i]) {
			cnt = 0; sz[1] = sz[2] = 0;
			co[i] = 1; dfs(i);
			sz[co[i]]++;
			if (not f) {
				puts("0"); return;
			}
			ans1 += sz[1] * sz[2] - cnt / 2;
			ans2 += (sz[1] + sz[2]) * (N - (sz[1] + sz[2]));
		}
	}/*分成不同可以组成二部图的连通块*/
	cout << ans1 + ans2 / 2 << endl;
}
signed main() {
	solve();
}