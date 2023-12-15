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

//矩阵快速幂
void solve() {
	i64 n, k; std::cin >> n >> k;
	vector<i64>A(n + 5, 0);
	for (i64 i = 1; i <= n; i++)cin >> A[i];
	vector ans(n + 5, vector<i64>(n + 5, 0));
	for (i64 i = 1; i <= n; i++) {
		for (i64 j = 1; j <= i; j++)ans[i][j] = 1;
	}
	auto mul = [&](vector<vector<i64>>x, vector<vector<i64>>y) {
		vector ret(n + 5, vector<i64>(n + 5, 0));
		for (i64 i = 1; i <= n; i++) {
			for (i64 j = 1; j <= n; j++) {
				for (i64 k = 1; k <= n; k++) {
					ret[i][j] = (ret[i][j] % mod + x[i][k] % mod * y[k][j]) % mod;
				}
			}
		}
		return ret;
	};
	vector ff(n + 5, vector<i64>(n + 5, 0));
	for (i64 i = 1; i <= n; i++)ff[i][i] = 1;
	auto mat_ksm = [&](i64 b) {
		while (b) {
			if (b & 1)ff = mul(ff, ans);
			ans = mul(ans, ans);
			b >>= 1;
		}
	};
	mat_ksm(k);
	vector<i64>res(n + 5);
	for (i64 i = 1; i <= n; i++) {
		for (i64 j = 1; j <= i; j++) {
			res[i] = (res[i] % mod + ff[i][j] % mod * A[j] % mod) % mod;
		}
	}
	for (i64 i = 1; i <= n; i++) {
		cout << res[i] << " ";
	}
	cout << endl;
}
signed main() {
	solve();
}