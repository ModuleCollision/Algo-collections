/*先序遍历序列(dfn)序列 遵从 rot + lch + rch*/
/*中序遍历序列遵从 lch + rot + rch*/
/*后序遍历序列遵从 lch + rch + rot*/
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

 i64 dfn[maxn], siz[maxn], n;
vector<pair< i64,  i64>>ans;
void solve() {
	std::cin >> n;
	for ( i64 i = 1; i <= n; i++) {
		cin >> dfn[i];
	}
	for ( i64 i = 1; i <= n; i++) {
		std::cin >> siz[i];
	}
	function<void( i64)>dfs = [&]( i64 id) {
		 i64 cur = dfn[id], k = id + 1, t = siz[cur];
		if (t == 1) {
			return;
		}
		t -= 1;
		while (t and k <= n) {
			t -= siz[dfn[k]]; dfs(k);
			 i64 a = max(cur, dfn[k]), b = min(cur, dfn[k]);
			ans.push_back({b, a});
			k += siz[dfn[k]];
		}
	};
	//根据一颗树的dfn序和每个子树的siz值唯一确定一颗树
	dfs(1);
	std::sort(ans.begin(), ans.end(), [&](pair< i64,  i64>a, pair< i64,  i64>b)->bool{
		return a.first == b.first ? a.second < b.second : a.first < b.first;
	});
	for (auto [x, y] : ans) {
		cout << x << " " << y << "\n";
	}
}
/*Fuck you,bitch!*/
signed main() {
	solve();
}

