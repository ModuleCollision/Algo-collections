/*300兆字节 1- 2 秒*/

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


vector<i64>tr[maxn]; bool vis[maxn];
i64 N, M, S, K = 1e6;
void solve() {
	/*典型的路径搜索题,按照枚举的思路dfs搜索即可*/
	function<void(i64, i64)>dfs = [&](i64 u, i64 fa) {
		S++;
		if (S > K)return;
		for (auto v : tr[u]) {
			if (v == fa or vis[v])continue;
			if (S > K)return;//注意按照题意剪枝
			vis[v] = 1;
			dfs(v, u);
			vis[v] = 0;
		}
	};
	std::cin >> N >> M;
	while (M--) {
		i64 u, v; std::cin >> u >> v;
		tr[u].push_back(v);
		tr[v].push_back(u);
	}
	vis[1] = 1;
	dfs(1, 0);
	cout << min(S, K) << endl;
}
signed main() {
	solve();
}