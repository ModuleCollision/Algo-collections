/*三分找最低点, 模板题*/
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
	i64 A, B, C; std::cin >> A >> B >> C;
	i64 n, m; std::cin >> n >> m;
	vector<i64>t(n + 5, 0); vector<i64>b(m + 5, 0);
	for (i64 i = 1; i <= n; i++)cin >> t[i];
	for (i64 i = 1; i <= m; i++)cin >> b[i];
	std::sort(b.begin() + 1, b.begin() + 1 + m);
	vector<i64>pre(m + 5, 0);
	for (i64 i = 1; i <= m; i++) {
		pre[i] = pre[i - 1] + b[i];
	}
	auto check = [&](i64 mid)->i64 {
		i64 s = 0, p = 0; i64 ret = 0;
		i64 idx = upper_bound(b.begin() + 1, b.begin() + 1 + m, mid) - b.begin();
		idx--; s += idx * mid - pre[idx];
		if (idx <= m)
			p += pre[m] - pre[idx] - (m - idx) * mid;
		if (B <= A) {
			ret += p * B;
		} else{
			if (s >= p) {
				ret += p * A;
			} else{
				ret += s * A + (p - s) * B;
			}
		}
		for (i64 i = 1; i <= n; i++)ret += max(0i64, mid - t[i]) * C;
		return ret;
	};
	i64 l = 1, r = *max_element(b.begin() + 1, b.begin() + 1 + m);
	while (l <= r) {
		i64 midl = (l + (r - l) / 3);
		i64 midr = (r - (r - l) / 3);
		if (check(midl) <= check(midr))r = midr - 1;
		else l = midl + 1;
	}
	cout << check(l) << endl;
}
signed main() {
	solve();
}