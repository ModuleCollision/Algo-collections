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

struct DSU {
	vector<i64>fa; vector<i64>siz;
	void init(i64 n) {
		fa.resize(n + 5); siz.resize(n + 5, 1);
		for (i64 i = 1; i <= n; i++) {
			fa[i] = i;
		}
	}
	i64 find(i64 x) {
		while (x != fa[x]) {
			x = fa[x] = fa[fa[x]];
		}
		return x;
	}
} dsu;
i64 N, M, Q, E;
pair<i64, i64>e[maxn];
i64 qd[maxn]; i64 ed[maxn], ans[maxn];
void solve() {
	std::cin >> N >> M >> E;
	for (i64 i = 1; i <= E; i++) {
		std::cin >> e[i].first >> e[i].second;
	}
	std::cin >> Q;
	for (i64 i = 1; i <= Q; i++) {
		std::cin >> ed[i];
		qd[ed[i]] = 1;
	}
	dsu.init(N + M + 5);
	i64 tot = 0;
	auto check = [&](i64 mid) ->bool {
		return mid >= N + 1 and mid <= N + M;
	};
	for (i64 i = 1; i <= E; i++) {
		if (not qd[i]) {
			i64 a = dsu.find(e[i].first);
			i64 b = dsu.find(e[i].second);
			if (a != b) {
				if (a > b)swap(a, b);
				dsu.fa[a] = b;
				if ((not check(a)) and check(b)) {
					tot += dsu.siz[a];
				}
				dsu.siz[b] += dsu.siz[a];
			}
		}
	}
	for (i64 i = Q; i >= 1; i--) {
		i64 x = e[ed[i]].first, y = e[ed[i]].second;
		i64 a = dsu.find(x), b = dsu.find(y);
		if (a != b) {
			if (a > b)swap(a, b);
			dsu.fa[a] = b;
			dsu.siz[b] += dsu.siz[a];
			if ((not check(a)) and check(b)) {
				tot += dsu.siz[a];
			}
		}
		ans[i] = tot;
	}
	for (i64 i = 1; i <= Q; i++) {
		cout << ans[i] << endl;
	}
}
signed main() {
	solve();
}