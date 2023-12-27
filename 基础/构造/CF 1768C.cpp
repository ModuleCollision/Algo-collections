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

//dp i , j表示在前i个数中使用状态为j的最大获得数
void solve() {
	i64 n; std::cin >> n;
	vector<pair<i64, i64>>p(n + 5);
	vector<i64>ans1(n + 5), ans2(n + 5);
	vector<bool>vis1(n + 5, 0), vis2(n + 5, 0);
	for (i64 i = 1; i <= n; i++) {
		cin >> p[i].second; p[i].first = i;
	}
	std::sort(p.begin() + 1, p.begin() + 1 + n, [&](pair<i64, i64>x, pair<i64, i64>y)->bool{
		return x.second > y.second;
	});
	for (i64 i = 1; i <= n; i++) {
		if (not vis1[p[i].second]) {
			vis1[p[i].second] = 1;
			ans1[p[i].first] = p[i].second;
		} else if (not vis2[p[i].second]) {
			vis2[p[i].second] = 1;
			ans2[p[i].first] = p[i].second;
		}
	}
	i64 r1 = n; i64 r2 = n;
	for (i64 i = 1; i <= n; i++) {
		if (not ans1[p[i].first]) {
			while (vis1[r1])r1--;
			vis1[r1] = 1;
			if (r1 > ans2[p[i].first]) {
				puts("NO"); return;
			}
			ans1[p[i].first] = r1; r1--;
		} else if (not ans2[p[i].first]) {
			while (vis2[r2])r2--;
			vis2[r2] = 1;
			if (r2 > ans1[p[i].first]) {
				puts("NO"); return;
			}
			ans2[p[i].first] = r2; r2--;
		}
	}
	puts("YES");
	for (i64 i = 1; i <= n; i++) {
		cout << ans1[i] << " ";
	}
	cout << endl;
	for (i64 i = 1; i <= n; i++) {
		cout << ans2[i] << " ";
	}
	cout << endl;
}
signed main() {
	i64 T; std::cin >> T;
	while (T--) {
		solve();
	}
}