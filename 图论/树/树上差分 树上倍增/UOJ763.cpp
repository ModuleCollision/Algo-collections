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
	srand(time(0));
	i64 mask = rand() % 1000005;
	auto shift = [&]( i64 x) {
		x ^= mask;
		x ^= (x << 13);
		x ^= (x >> 7);
		x ^= (x << 17);
		x ^= mask;
		return x;
	};
	i64 n; std::cin >> n;
	vector hash(n + 5, 0 i64);
	vector tr(n + 5, vector(0, 0 i64));
	std::set< i64>st;
	for ( i64 i = 1; i <= n - 1; i++) {
		i64 u, v; std::cin >> u >> v;
		tr[u].push_back(v);
		tr[v].push_back(u);
	}
	function<void( i64,  i64)>dfs = [&]( i64 u,  i64 f) {
		hash[u] = 1;
		for (auto v : tr[u]) {
			if (v == f)continue;
			dfs(v, u);
			hash[u] += shift(hash[v]);
		}
		st.insert(hash[u]);
	};
	dfs(1, 0);//判断有多少颗不同子树同构
	//树哈希值相同代表有根树同构
	cout << st.size() << endl;
}
signed main() {
	solve();
}