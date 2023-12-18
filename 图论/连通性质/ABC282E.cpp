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
	vector<i64>fa;
	void init(i64 n) {
		fa.resize(n + 5, 0);
		for (i64 i = 1; i <= n; i++)fa[i] = i;
	}
	i64 find(i64 x) {
		while (x != fa[x]) {
			x = fa[x] = fa[fa[x]];
		}
		return x;
	}
	void merge(i64 x, i64 y) {
		i64 a = find(x), b = find(y);
		fa[a] = b;
	}
} dsu;
struct edge {
	i64 u; i64 v; i64 w;
};
void solve() {
	i64 N, M;
	std::cin >> N >> M;
	vector<i64>A(N + 5, 0);
	for (i64 i = 1; i <= N; i++)std::cin >> A[i];
	i64 ans = 0;
	auto ksm = [&](i64 x, i64 y)->i64 {
		i64 ret = 1;
		while (y) {
			if (y & 1)ret = ret * x % M;
			x = x * x % M;
			y >>= 1;
		}
		return ret % M;
	};
	dsu.init(N); vector<edge>e;
	for (i64 i = 1; i <= N; i++) {
		for (i64 j = i + 1; j <= N; j++) {
			i64 tmp = (ksm(A[i], A[j]) % M + ksm(A[j], A[i])) % M;
			e.push_back({i, j, tmp});
		}
	}
	std::sort(e.begin(), e.end(), [&](edge a, edge b)->bool{
		return a.w > b.w;
	});
	for (auto [u, v, w] : e) {
		if (dsu.find(u) == dsu.find(v))continue;
		ans += w;
		dsu.merge(u, v);
	}
	cout << ans << endl;
}
signed main() {
	solve();
}