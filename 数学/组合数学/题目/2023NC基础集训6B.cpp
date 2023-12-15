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
	i64 n; cin >> n; vector<i64>S(n + 5, 0);
	vector<i64>T(n + 5, 0);
	for (i64 i = 1; i <= n; i++)cin >> S[i];
	for (i64 i = 1; i <= n; i++)cin >> T[i];
	std::sort(S.begin() + 1, S.begin() + 1 + n);
	std::sort(T.begin() + 1, T.begin() + 1 + n);
	i64 ans = 0;
	vector C(n + 1, vector<i64>(n + 1, 0));
	for (i64 i = 0; i <= n; i++) {
		for (i64 j = 0; j <= i; j++) {
			if (not j)C[i][j] = 1;
			else C[i][j] = (C[i - 1][j] % mod + C[i - 1][j - 1]) % mod;
		}
	}
	auto ksm = [&](i64 x, i64 y) {
		i64 ret = 1;
		while (y) {
			if (y & 1)ret = ret * x % mod;
			x = x * x % mod;
			y >>= 1;
		}
		return ret;
	};
	/*for (i64 i = 0; i <= 20; i++) {
		for (i64 j = 0; j <= i; j++) {
			if (not j)C[i][j] = 1;
			else C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
		}
	}
	for (i64 i = 0; i <= 10; i++) {
		for (i64 j = 0; j <= 10; j++) {
			i64 s1 = min(i, j); i64 s2 = max(i, j);
			i64 v = 0;
			for (i64 i = 0; i <= s1; i++) {
				v += C[s1][i] * C[s2][i];
			}
			cout << v << " ";
		}
		cout << endl;
	}*/
	//打表内容, 处理出ΣCis1 * Cis2的值
	vector f(n + 5, vector<i64>(n + 5, 0));
	for (i64 i = 0; i <= n; i++)f[0][i] = 1;
	for (i64 j = 0; j <= n; j++)f[j][0] = 1;
	for (i64 i = 1; i <= n; i++) {
		for (i64 j = 1; j <= n; j++) {
			f[i][j] = (f[i][j - 1] % mod + f[i - 1][j]) % mod;
			//cout << f[i][j] << " ";
		}
	}
	for (i64 i = 1; i <= n; i++) {
		for (i64 j = 1; j <= n; j++) {
			i64 cur1 = S[i], cur2 = T[j];//枚举cur1 , cur2是数列中第几大的
			if (cur1 == cur2)continue;
			i64 p1 = min(n - i, n - j);
			i64 p2 = max(n - i, n - j);
			i64 p3 = min(i - 1, j - 1);
			i64 p4 = max(i - 1, j - 1);
			i64 v = f[p1][p2] % mod * f[p3][p4] % mod;
			ans = (ans % mod + v % mod * abs(cur1 - cur2)) % mod;
		}
	}
	cout << ans << endl;
}
signed main() {
	solve();
}