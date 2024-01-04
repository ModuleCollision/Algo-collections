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
	auto fac = [&](i64 x) {
		i64 ret = 1;
		for (i64 i = 1; i <= x; i++) {
			ret = ret * i; if (ret > m)return m + 1;
		}
		return ret;
	};
	auto getax = [&](i64 idx) {
		i64 rk = m;
		i64 k = 1;//求出第m大的排列中第idx位的数
		while (fac(k) < m)k++;
		vector<bool>st(20, 0);
		if (idx <= n - k)return idx;//贪心的找, 枚举后 k 位 , 前 n - k 位为对应的数
		for (i64 i = n - k + 1; i <= n; i++) {
			for (i64 j = 1; i <= k; j++) {//第i位的数找到了
				if (not st[j]) {
					i64 t = fac(n - i);
					if (t < rk) {
						rk -= t;
					} else {
						if (i == idx)return j + n - k;
						st[j] = true;
						break;
					}
				}
			}
		}
		return -1ll;
	};
	auto check = [&](i64 x) {
		string t = to_string(x);
		for (auto c : t) {
			if (c != '4' and c != '7')return false;
		}
		return true;
	};
	i64 ans = 0;
	function<void(i64)>dfs = [&](i64 x) {
		if (x > n)return;
		if (x and check(getax(x)))ans++;
		dfs(10 * x + 4);
		dfs(10 * x + 7);
	};
	if (fac(n) < m) {
		puts("-1"); return;
	}
	dfs(0); cout << (ans ? ans : -1) << endl;
}
signed main() {
	solve();
}