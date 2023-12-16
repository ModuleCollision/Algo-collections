/*前缀和*/
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
	i64 L, N1, N2;
	std::cin >> L >> N1 >> N2;
	vector<i64>v1(N1 + 5, 0), v2(N2 + 5, 0);
	i64 l;
	vector<pair<i64, i64>>p1(N1 + 5), p2(N2 + 5);
	i64 pre = 0;
	for (i64 i = 1; i <= N1; i++) {
		std::cin >> v1[i] >> l;
		p1[i] = {pre + 1, pre + l};
		pre += l;
	}
	pre = 0;
	for (i64 i = 1; i <= N2; i++) {
		std::cin >> v2[i] >> l;
		p2[i] = {pre + 1, pre + l};
		pre += l;
	}
	i64 sp = 1, fp = 1, ans = 0;
	while (sp <= N1 and fp <= N2) {
		if (p1[sp].second < p2[fp].second) {
			if (v1[sp] == v2[fp]) {
				ans += min(p1[sp].second, p2[fp].second) - max(p1[sp].first, p2[fp].first) + 1;
			}
			sp++;
		} else if (p1[sp].second > p2[fp].second) {
			if (v1[sp] == v2[fp]) {
				ans += min(p1[sp].second, p2[fp].second) - max(p1[sp].first, p2[fp].first) + 1;
			}
			fp++;
		} else {
			if (v1[sp] == v2[fp]) {
				ans += min(p1[sp].second, p2[fp].second) - max(p1[sp].first, p2[fp].first) + 1;
			}
			sp++; fp++;
		}
	}
	cout << ans << endl;
}
signed main() {
	solve();
}