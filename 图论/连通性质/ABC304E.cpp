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
	i64 N, M; std::cin >> N >> M;
	vector<i64>fa(N + 5, 0);
	for (i64 i = 1; i <= N; i++)fa[i] = i;
	auto find = [&](i64 x)->i64{
		while (x != fa[x])x = fa[x] = fa[fa[x]];
		return x;
	};
	auto merge = [&](i64 x, i64 y) {
		i64 a = find(x), b = find(y);
		if (a == b)return;
		fa[a] = b;
	};
	auto same = [&](i64 x, i64 y)->bool {
		return find(x) == find(y);
	};
	for (i64 i = 1; i <= M; i++) {
		i64 u, v; std::cin >> u >> v;
		merge(u, v);
	}
	i64 K; std::cin >> K;
	vector<pair<i64, i64>>s(K + 5);
	std::set<pair<i64, i64>>w;
	for (i64 i = 1; i <= K; i++) {
		std::cin >> s[i].first >> s[i].second;
		i64 a = find(s[i].first), b = find(s[i].second);
		if (a > b)swap(a, b);
		w.insert({a, b});
	}
	i64 Q; std::cin >> Q;
	while (Q--) {
		i64 p, q; std::cin >> p >> q;
		i64 a = find(p), b = find(q);
		if (a > b)swap(a, b);
		if (w.count({a, b}))puts("No");
		else puts("Yes");
	}
}
signed main() {
	solve();
}