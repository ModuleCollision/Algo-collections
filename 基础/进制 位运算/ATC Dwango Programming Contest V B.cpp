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
	i64 n, k; std::cin >> n >> k;
	i64 ans = 0;
	vector<i64>A(n + 1);
	for (i64 i = 1; i <= n; i++) {
		std::cin >> A[i];
		A[i] += A[i - 1];
	}
	vector<i64>w;
	for (i64 l = 1; l <= n; l++) {
		for (i64 r = l; r <= n; r++) {
			w.push_back(A[r] - A[l - 1]);
		}
	}
	i64 sz = w.size(); vector<i64>vis(sz + 1, 0);
	for (i64 i = 40; i >= 0; i--) {
		i64 cnt = 0;
		for (i64 j = 0; j < sz; j++) {
			if (vis[j] == 40 - i and ((w[j] >> i) & 1))cnt++;
		}
		if (cnt >= k) {
			ans |= (1ll << i);
			for (i64 j = 0; j < sz; j++) {
				if (vis[j] == 40 - i and ((w[j] >> i) & 1))vis[j]++;//选中了
			}
		} else { //没必要选择
			for (i64 j = 0; j < sz; j++) {
				if (vis[j] == 40 - i)vis[j]++;//继承上一轮的
			}
		}
	}
	cout << ans << endl;
}
signed main() {
	solve();
}