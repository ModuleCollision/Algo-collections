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
constexpr i64 maxn = 60;
constexpr i64 inf = 0x3f3f3f3f3f3f3f3f;

char c[maxn][maxn]; i64 dp[maxn][maxn];
i64 gcd(i64 a, i64 b) {
	return b ? gcd(b, a % b) : a;
}
bool check(int x, int y) {
	return y > 0 && y <= x;
}
int main() {
	int n, m; cin >> n >> m;
	i64 num = pow(2, n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> c[i][j];
		}
	}
	dp[1][1] = num;
	if (c[1][1] == '*') {
		dp[2][1] = dp[2][2] = num >> 1;
	}
	for (int i = 3; i <= n + 1; i++) {
		for (int j = 1; j <= i; j++) {
			i64 ans = 0;
			if (check(i - 1, j - 1) && c[i - 1][j - 1] == '*')
				ans += dp[i - 1][j - 1] >> 1;
			if (check(i - 1, j) && c[i - 1][j] == '*')
				ans += dp[i - 1][j] >> 1;
			if (check(i - 2, j - 1) && c[i - 2][j - 1] == '.')
				ans += dp[i - 2][j - 1];
			dp[i][j] = ans;
		}
	}
	i64 A = dp[n + 1][m + 1];
	i64 B = gcd(A, num);

	if (A == 0) {
		cout << 0 << "/" << 1;
	}
	else {
		cout << A / B << "/" << num / B;
	}
}