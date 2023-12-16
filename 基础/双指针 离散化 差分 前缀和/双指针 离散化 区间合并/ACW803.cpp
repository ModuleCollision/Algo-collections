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
	i64 n; std::cin >> n;
	vector<pair<i64, i64>>w(n + 5);
	for (i64 i = 1; i <= n; i++)cin >> w[i].first >> w[i].second;
	std::sort(w.begin() + 1, w.begin() + 1 + n, [&](pair<i64, i64> s, pair<i64, i64> t)->bool{
		if (s.first != t.first)return s.first < t.first;
		return s.second < t.second;
	});
	i64 cnt = 1;
	i64 Maxr = w[1].second;
	for (i64 i = 2; i <= n; i++) {
		if (w[i].first <= Maxr) {
			Maxr = max(Maxr, w[i].second);
		} else {
			cnt++;
			Maxr = w[i].second;
		}
	}
	cout << cnt << endl;
}
signed main() {
	solve();
}