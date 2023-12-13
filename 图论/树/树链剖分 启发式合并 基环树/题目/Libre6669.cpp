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
constexpr i64 mod = 998244353;
constexpr i64 maxn = 1e7 + 500;
constexpr i64 inf = 0x3f3f3f3f3f3f3f3f;


void solve() {
	i64 n; std::cin >> n;
	std::vector fa(n + 5, 0), dep(n + 5, 0), siz(n + 5, 0), son(n + 5, 0);
	std::vector ch(n + 5, std::vector(2, 0));
	std::vector bot(n + 5, 0), id(n + 5, 0);
	auto query = [&](i64 u, i64 v) {
		std::cout << "? " << u << " " << v << "\n";
		std::cout.flush();
		i64 d; std::cin >> d;
		return d;
	};
	auto setf = [&](i64 u, i64 v) {
		fa[v] = u;
		if (ch[u][0])ch[u][1] = v;
		else ch[u][0] = v;
	};
	std::function<void(i64)>dfs = [&](i64 u) {
		if (ch[u][0])dfs(ch[u][0]);
		if (ch[u][1])dfs(ch[u][1]);
		siz[u] = siz[ch[u][0]] + siz[ch[u][1]] + 1;
		if (ch[u][1]) {
			son[u] = (i64)(siz[ch[u][0]] < siz[ch[u][1]]);
		} else son[u] = 0;
		if (ch[u][son[u]]) {//并非重链的底端
			bot[u] = bot[ch[u][son[u]]];
		} else {
			bot[u] = u;//重链的底端
		}
	};//模拟重链剖分,son记录重链走向

	std::function<void(i64, i64)>tarjan = [&](i64 u, i64 k) {
		if (not ch[u][0]) {
			setf(u, k); return;
		}
		i64 d = query(k, bot[u]);
		i64 v = bot[u];
		while (dep[v] > (dep[k] + dep[bot[u]] - d) / 2)v = fa[v];
		i64 w = ch[v][son[v] ^ 1];//由已知树链的信息定向到k的父亲
		if (w)tarjan(w, k);
		else setf(v, k);
	};
	for (i64 i = 2; i <= n; i++) {
		id[i] = i; dep[i] = query(1, i);
	}
	std::sort(id.begin() + 2, id.begin() + n + 1, [&](i64 x, i64 y)->bool{
		return dep[x] < dep[y];
	});
	for (i64 i = 2; i <= n; i++) {
		dfs(1); tarjan(1, id[i]);
	}
	putchar('!');
	for (i64 i = 2; i <= n; i++) {
		std::cout << " " << fa[i];
	}
	std::cout << "\n";
	std::cout.flush();
}
signed main() {
	solve();
}
