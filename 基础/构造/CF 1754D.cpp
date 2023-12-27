/*构造题*/
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

int n;
void solve() {
	std::cin >> n;
	vector<int>a(n + 5);
	int cnt1 = 0, cnt2 = 0; //cnt1,1 cnt2,-1;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
		if (a[i] == 1) {
			cnt1++;
		} else if (a[i] == -1) {
			cnt2++;
		}
	}
	if ((cnt1 + cnt2) & 1) {
		puts("-1");
		return;
	}
	vector<pair<int, int>>ans;
	if (cnt1 == cnt2) {
		for (int i = 1; i <= n; i++) {
			ans.push_back({i, i});
		}
		cout << n << endl;
		for (auto [x, y] : ans) {
			cout << x << " " << y << endl;
		}
		return;
	}
	if (cnt1 > cnt2) {
		swap(cnt1, cnt2);
		for (int i = 1; i <= n; i++) {
			a[i] *= -1;
		}
	}
	// cnt2 为 -1 数量,cnt1 为 1 数量,cnt2 > cnt1
	for (int i = 1; i <= n;) {
		if (cnt1 < cnt2) {
			if (a[i] == 0 and a[i + 1] == -1) {
				ans.push_back({i, i + 1});
				cnt1++; cnt2--;
				i += 2;
			} else if (a[i] == -1 and a[i + 1] == -1) {
				ans.push_back({i, i + 1});
				cnt2 -= 2;
				i += 2;
			} else {
				ans.push_back({i, i});
				i++;
			}
		} else {
			ans.push_back({i, i});
			i++;
		}
	}
	if (cnt1 != cnt2) {
		puts("-1");
		return;
	}
	cout << ans.size() << endl;
	for (auto [x, y] : ans) {
		cout << x << " " << y << endl;
	}
}
signed main() {
	int T; std::cin >> T;
	while (T--) {
		solve();
	}
}
