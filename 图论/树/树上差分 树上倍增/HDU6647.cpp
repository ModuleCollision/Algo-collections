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

const  i64 mask = std::chrono::steady_clock::now().time_since_epoch().count();

 i64 shift( i64 x) {
	x ^= mask;
	x ^= (x << 13);
	x ^= (x >> 7);
	x ^= (x << 17); x ^= mask; return x;
}
 i64 inv( i64 x) {
	 i64 ret = 1, y = mod - 2;
	while (y) {
		if (y & 1) {
			ret = ret * x % mod;
		}
		x = x * x % mod;
		y >>= 1;
	}
	return ret % mod;
}
struct sq {
	 i64 hash, deg, ans;//记录每个节点的子节点同构数,答案,该子树哈希值
	std::map< i64,  i64>son;
	void add(sq &o) {
		 i64 tmp = shift(o.hash);
		hash += tmp;
		ans = (ans) * (++deg) % mod * inv(++son[tmp]) % mod * o.ans % mod;
	}
	void remove(sq &o) {
		 i64 tmp = shift(o.hash);
		hash -= tmp;
		ans = ans * inv(deg--) % mod * (son[tmp]--) % mod * inv(o.ans) % mod;
	}
	void clear() {
		hash = 1;
		deg = 0;
		ans = 1;
		son.clear();
	}
};
void solve() {
	 i64 n; std::cin >> n;
	vector<vector< i64>>tr(n + 5);
	for ( i64 i = 1; i < n; i++) {
		 i64 u, v; std::cin >> u >> v;
		tr[u].push_back(v);
		tr[v].push_back(u);
	}
	vector<sq>sub(n + 5), root(n + 5);
	std::map< i64,  i64>trees;
	function<void( i64 ,  i64)>getSub = [&]( i64 u,  i64 f) {
		sub[u].clear();
		for (auto v : tr[u]) {
			if (v == f)continue;
			getSub(v, u);
			sub[u].add(sub[v]);
		}
	};

	function<void( i64,  i64) >getRoot = [&]( i64 u,  i64 f) {
		for (auto v : tr[u]) {
			if (v == f)continue;
			root[u].remove(sub[v]);
			root[v] = sub[v];
			root[v].add(root[u]);
			root[u].add(sub[v]);
			getRoot(v, u);
		}
		trees[root[u].hash] = root[u].ans;
	};
	getSub(1, 0);
	root[1] = sub[1];
	getRoot(1, 0);
	 i64 ans = 0;
	for (auto [x, y] : trees) {
		ans = (ans % mod + y) % mod;
	}
	cout << ans << endl;
}
signed main() {
	 i64 T; std::cin >> T;
	while (T--)
		solve();
}