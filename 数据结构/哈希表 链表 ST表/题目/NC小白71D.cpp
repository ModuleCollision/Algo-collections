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

struct sq {
	i64 u; i64 v; i64 idx;
} t1[maxn], t2[maxn]; i64 tot = 0;
std::set<i64>p;
void solve() {
	i64 n, m;
	std::cin >> n >> m;
	for (i64 i = 1; i <= n; i++) {
		std::cin >> t1[i].u;
		t1[i].idx = i;
	}
	for (i64 i = 1; i <= n; i++) {
		std::cin >> t1[i].v;
	}
	for (i64 i = 1; i <= m; i++) {
		std::cin >> t2[i].u;
		t2[i].idx = i;
	}
	for (i64 i = 1; i <= m; i++) {
		std::cin >> t2[i].v;
	}
	i64 prev = 0;
	std::sort(t1 + 1, t1 + 1 + n, [&](sq a, sq b)->bool{
		return a.u < b.u;
	});
	std::sort(t2 + 1, t2 + 1 + m, [&](sq a, sq b)->bool{
		return a.v < b.v;
	});
	p.clear();
	vector<i64>ans(n + 5, 0);
	for (i64 i = 1, j = 1; i <= n; i++) {
		i64 val = t1[i].u;
		while (t2[j].v <= val and j <= m) {
			p.insert(t2[j].u);
			j++;
		}
		i64 idx = t1[i].idx;
		if (p.size() == 0) {
			ans[idx] = -1; continue;
		}
		auto it = p.end(); it--;
		if (*it >= t1[i].v) {
			ans[idx] = *it;
		} else {
			ans[idx] = -1;
		}
	}
	for (i64 i = 1; i <= n; i++) {
		cout << ans[i] << " ";
	}
}
signed main() {
	solve();
}