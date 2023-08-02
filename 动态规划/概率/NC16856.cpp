#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const int N = 60;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
char c[N][N]; ll dp[N][N];
ll gcd(ll a, ll b) {
	return b ? gcd(b, a % b) : a;
}
bool check(int x, int y) {
	return y > 0 && y <= x;
}
signed main() {
	int n, m;
	cin >> n >> m;
	ll num = pow(2, n);
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
			ll ans = 0;
			if (check(i - 1, j - 1) && c[i - 1][j - 1] == '*')
				ans += dp[i - 1][j - 1] >> 1;
			if (check(i - 1, j) && c[i - 1][j] == '*')
				ans += dp[i - 1][j] >> 1;
			if (check(i - 2, j - 1) && c[i - 2][j - 1] == '.')
				ans += dp[i - 2][j - 1];
			dp[i][j] = ans;
		}
	}
	ll A = dp[n + 1][m + 1];
	ll B = gcd(A, num);

	if (A == 0)
		cout << 0 << "/" << 1;
	else
		cout << A / B << "/" << num / B;
}