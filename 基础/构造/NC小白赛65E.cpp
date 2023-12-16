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

int a[maxn], b[maxn];
i64 lg[maxn], f[maxn], f_sum[maxn], n, k;
signed main() {
	lg[0] = 0;
	lg[1] = 0;
	std::cin >> n >> k;
	i64 sum = 0;
	for (i64 i = 2; i <= 1e6; i++) {
		lg[i] = lg[i >> 1] + 1;
	}
	//cout << lg[33] << endl;
	for (i64 i = 2; i <= n; i++) {
		f[i] = lg[i - 1] + 1;
	}
	for (i64 i = 2; i <= n; i++) {
		sum += (lg[i - 1] + 1);
	}
	if (sum < k) {
		cout << -1;
		return 0;
	}
	vector<i64>ans1, ans2;
	for (i64 i = n; i >= 1; i--) {
		if (k >= f[i]) {
			ans1.push_back(i);
			k -= f[i];
		} else {
			ans2.push_back(i);
		}
	}
	reverse(ans2.begin(), ans2.end());
	for (auto c : ans1) {
		cout << c << " ";
	}
	for (auto c : ans2) {
		cout << c << " ";
	}
	return 0;
}