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

i64 n; char s[maxn];
void solve() {
	std::cin >> n >> (s + 1);
	if (n & 1) {
		puts("-1"); return;
	}
	vector<i64>cnt(30, 0), ks(30, 0);
	for (i64 i = 1; i <= n; i++) {
		cnt[s[i] - 'a']++;
	}
	i64 mx = *max_element(cnt.begin(), cnt.begin() + 26);
	i64 sum = 0;
	if (mx > n / 2) {
		puts("-1"); return;
	}
	for (i64 i = 1; i <= n / 2; i++) {
		if (s[i] == s[n - i + 1]) {
			sum += 1;	ks[s[i] - 'a']++;
		}
	}
	mx = *max_element(ks.begin(), ks.begin() + 26);
	if (mx <= (sum) / 2) {
		cout << (sum + 1) / 2 << endl;
	} else {
		cout << mx << endl;
	}
}
i64 T;
signed main() {
	std::cin >> T;
	while (T--)
		solve();
}




