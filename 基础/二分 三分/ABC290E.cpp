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
	i64 n; std::cin >> n;
	vector<i64>A(n + 5, 0), B;
	for (i64 i = 1; i <= n; i++)cin >> A[i];
	vector<vector<i64>>k(n + 1);
	vector<vector<i64>>pre(n + 1);
	for (i64 i = 1; i <= n; i++)k[A[i]].push_back(i);
	for (i64 i = 1; i <= n; i++) {
		if (not k[i].size())continue;
		pre[i].resize(k[i].size() + 5);
		pre[i][k[i].size() - 1] = n + 1 - k[i].back();
		for (i64 j = k[i].size() - 2; j >= 0; j--)pre[i][j] = pre[i][j + 1] + n + 1 - k[i][j];
	}
	i64 ans = 0;
	for (i64 i = 1; i <= n; i++) {
		ans += (n - i + 1) * (i / 2);
	}
	//cout << ans << endl;
	for (i64 i = 1; i <= n; i++) {
		if (not k[i].size())continue;
		//cout << i << ": " << endl;
		for (i64 j = 0; j < k[i].size(); j++) {
			i64 sz1 = upper_bound(k[i].begin() + j + 1, k[i].end(), n + 1 - k[i][j]) - (k[i].begin() + j) - 1;
			i64 idx = j + 1 + sz1;
			//cout << idx << endl;
			ans -= max(0i64, (sz1)) * k[i][j];
			if (idx >= k[i].size())continue;
			ans -= pre[i][idx];
			//cout << pre[i][idx + 1] << endl;
			//cout << ans << endl;
		}
	}
	cout << ans << endl;
}
signed main() {
	solve();
}