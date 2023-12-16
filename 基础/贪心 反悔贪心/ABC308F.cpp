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
	i64 n, m; std::cin >> n >> m;
	vector<i64>p(n + 5);
	vector<pair<i64, i64>>w(m + 5);
	std::map<i64, i64>ks;
	i64 res = 0;
	for (i64 i = 1; i <= n; i++)cin >> p[i], ks[p[i]]++, res += p[i];
	for (i64 i = 1; i <= m; i++)cin >> w[i].first;
	for (i64 i = 1; i <= m; i++)cin >> w[i].second;
	std::sort(w.begin() + 1, w.begin() + 1 + m, [&](auto c, auto d)->bool{
		return c.second > d.second;
	});
	for (i64 i = 1; i <= m; i++) {
		auto [l, d] = w[i];
		auto idx = ks.lower_bound(l);
		if (idx == ks.end())continue;
		idx->second--;
		res -= d;
		if (idx->second == 0)ks.erase(idx->first);
	}
	cout << res << endl;
}
signed main() {
	solve();
}