/*双指针维护一个定值*/
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

int n, m;
void solve() {
	std::cin >> n >> m;
	vector<int>a(n + 5, 0), cnt(m + 5, 0);
	int sum = 0;
	auto add = [&](int a) {
		for (int i = 1; i * i <= a; i++) {
			if (a % i == 0) {
				if (i <= m) {
					++cnt[i];
				}
				if (cnt[i] == 1) {
					sum++;
				}
			}
			if (a / i <= m and i != a / i) {
				++cnt[a / i]; if (cnt[a / i] == 1) {
					sum++;
				}
			}
		}
	};
	auto del = [&](int a) {
		for (int i = 1; i * i <= a; i++) {
			if (a % i == 0) {
				if (i <= m) {
					--cnt[i];
					if (cnt[i] == 0) {
						sum--;
					}
				}
			} if (a / i <= m and i != a / i) {
				--cnt[a / i]; if (cnt[a / i] == 0) {
					sum--;
				}
			}
		}
	};
	int ans = inf; for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	std::sort(a.begin() + 1, a.begin() + 1 + n);
	for (int i = 1, j = 0; i <= n; i++) {
		del(a[i - 1]);
		while (j + 1 <= n and sum < m) {
			add(a[++j]);
		}
		if (sum == m) {
			ans = min(ans, a[j] - a[i]);
		}
	}
	if (ans == inf) {
		puts("-1");
	} else {
		cout << ans << endl;
	}
}
signed main() {
	int T; cin >> T;
	while (T--) {
		solve();
	}
}