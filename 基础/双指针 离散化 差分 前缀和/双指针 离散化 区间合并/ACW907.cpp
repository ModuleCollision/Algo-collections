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
	i64 s, t; std::cin >> s >> t;
	i64 n; std::cin >> n;
	vector<pair<i64, i64>>k(n + 5);
	for (i64 i = 1; i <= n; i++)cin >> k[i].first >> k[i].second;
	std::sort(k.begin() + 1, k.begin() + 1 + n, [&](pair<i64, i64>x, pair<i64, i64>y)->bool{
		if (x.first != y.first)return x.first < y.first;
		return x.second < y.second;
	});
	bool f = 0;
	i64 ans = 0;
	for (i64 i = 1; i <= n; i++) {
		i64 j = i; i64 r = -inf;
		while (j <= n and k[j].first <= s)r = max(r, k[j].second), j++;
		j--;
		if (r < s) {
			f = 0; break;
		}
		ans++;
		if (r >= t) {
			f = 1;
			break;
		}
		i = j; s = r;
	}
	if (not f) {
		puts("-1");
	} else {
		cout << ans << endl;
	}
}
signed main() {
	solve();
}