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
	i64 n, m, k; string s; std::cin >> n >> m >> k >> s;
	i64 tot = 0;
	s = " " + s;
	vector<i64>idx(n + 5);
	for (i64 i = 1; i <= n; i++) {
		if (s[i] == 'x')idx[++tot] = i;
	}
	idx[++tot] = n + 1;
	i64 cnt = tot - 1;
	auto get = [&](i64 i) {
		if (cnt - i + 1 + (m - 1)*cnt < k)return 0i64;
		i64 tmp = k;
		i64 ret = 0; i64 cur = 0;
		i64 s1 = min(tmp, cnt - i + 1);
		ret += idx[i] - idx[i - 1];
		ret += idx[i + s1] - idx[i] - 1;
		cur += 1; tmp -= s1;
		if (tmp <= 0)return ret;
		i64 mid = max(0ll, tmp / cnt);
		mid = min(mid, m - 1);
		cur += mid;
		ret += mid * n;
		if (cur == m)return ret;
		tmp -= mid * cnt;
		ret += idx[tmp + 1] - 1;
		return ret;
	};
	i64 ans = 0;
	for (i64 i = 1; i <= cnt; i++) {
		ans = max(ans, get(i));
	}
	cout << ans << endl;
}
signed main() {
	solve();
}