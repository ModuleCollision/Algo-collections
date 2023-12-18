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

constexpr i64 p = 13331;
void solve() {
	i64 n, m, k; std::cin >> n >> m >> k;
	string s; std::cin >> s; s = " " + s;
	vector<i64>Hash(n + 5, 0);
	for (i64 i = 1; i <= n; i++) {
		Hash[i] = Hash[i - 1] * p  + s[i];
	}
	auto ksm = [&](i64 x, i64 y) {
		i64 ret = 1;
		while (y) {
			if (y & 1)ret = ret * x;
			x = x * x;
			y >>= 1;
		}
		return ret;
	};
	auto get = [&](i64 l, i64 r) {
		return (Hash[r] - Hash[l - 1] * ksm(p, r - l + 1));
	};
	std::map<i64, i64>cnt, pre;
	for (i64 i = 1; i <= n - m + 1; i++) {
		ui64 cur = get(i, i + m - 1);
		if (not pre.count(cur) or pre[cur] < i - m + 1) {
			pre[cur] = i; cnt[cur]++;
		}
	}
	i64 ret = 0;
	for (auto [x, y] : cnt) {
		if (y == k)ret++;
	}
	cout << ret << endl;
}
signed main() {
	solve();
}