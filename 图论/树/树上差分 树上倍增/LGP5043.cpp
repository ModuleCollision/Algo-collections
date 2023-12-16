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
	 i64 mask = std::chrono::steady_clock::now().time_since_epoch().count();
	auto shift = [&]( i64 x) {
		x ^= mask;
		x ^= (x << 13);
		x ^= (x >> 7);
		x ^= (x << 17); x ^= mask; return x;
	};
	std::map< i64,  i64>trees;
	 i64 m; std::cin >> m;
	for ( i64 t = 1; t <= m; t++) {
		 i64 n; std::cin >> n;
		vector<vector< i64>>tr(n + 5);
		vector< i64>sub(n + 5), root(n + 5);
		 i64 rt = 0;
		for ( i64 i = 1; i <= n; i++) {
			 i64 f; std::cin >> f;
			if (f)tr[f].push_back(i);
			else rt = i;
		}
		function<void( i64 u)>getsub = [&]( i64 u) {
			sub[u] = 1;
			for (auto v : tr[u]) {
				getsub(v);
				sub[u] += shift(sub[v]);
			}
		};
		function<void( i64 u)>getRoot = [&]( i64 u) {
			for (auto v : tr[u]) {
				root[v] = sub[v] + shift(root[u] - shift(sub[v]));
				getRoot(v);
			}
		};
		getsub(rt); root[rt] = sub[rt];
		getRoot(rt);
		 i64 hash = 1;
		for ( i64 i = 1; i <= n; i++) {
			hash += shift(root[i]);
		}
		if (not trees.count(hash)) {
			trees[hash] = t;
		}
		cout << trees[hash] << endl;
	}
}//无根树的同构判断:求出每个树的真正
signed main() {
	solve();
}