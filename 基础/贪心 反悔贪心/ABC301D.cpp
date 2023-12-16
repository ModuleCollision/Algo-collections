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
	string s; std::cin >> s;
	i64 N; std::cin >> N;
	reverse(s.begin(), s.end());
	i64 cur = 0;
	i64 ks = s.size();
	vector<i64>idx;
	for (i64 i = 0; i < ks; i++) {
		if (s[i] == '1') {
			cur += (1i64 << i);
		}
	}
	if (cur > N) {
		puts("-1"); return;
	}
	i64 ans = cur;
	for (i64 i = 0; i < ks; i++)if (s[i] == '?')idx.push_back(i);
	i64 len = idx.size();
	for (i64 i = len - 1; i >= 0; i--) {
		i64 t = cur + (1i64 << idx[i]);
		if (t > N)continue;
		for (i64 j = i - 1; j >= 0; j--) {
			if ((t + (1i64 << idx[j])) > N)continue;
			else t += (1i64 << idx[j]);
		}
		ans = max(ans, t);
	}
	cout << ans << endl;
}
signed main() {
	solve();
}