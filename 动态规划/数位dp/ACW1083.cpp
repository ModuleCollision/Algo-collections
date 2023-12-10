#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 3010;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
int a, b; int dp[1005][15];
void init() {
	for (int i = 0; i <= 9; i++) {
		dp[1][i] = 1;
	}
	//一共有 i 位 ,最高位为 j 的总序列数
	for (int i = 2; i <= 9; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int k = 0; k <= 9; k++) {
				if (abs(k - j) >= 2)dp[i][j] += dp[i - 1][k];
			}
		}
	}
}
void solve() {
	std::cin >> a >> b;
	//00..0 到 99..9 中 以 0 - 9结尾的windy序列
	auto cal = [&](ll x) {
		vector<ll>num;
		while (x) {
			num.push_back(x % 10); x /= 10;
		}
		int res = 0; int pre = -10; int len = num.size() - 1;
		for (ll i = len; i >= 0; i--) {
			int cur = num[i];
			for (int j = (i == len); j < cur; j++) {
				if (abs(j - pre) >= 2)res += dp[i + 1][j];
			}
			if (abs(cur - pre) < 2)break;
			pre = cur;
			if (not i)res++;
		}
		for (int i = 1; i <= len; i++) {
			for (int j = 1; j <= 9; j++) {
				res += dp[i][j];
			}
		}
		return res;
	};
	int ans =  cal(b) - cal(a - 1);
	cout << ans << endl;

}
signed main() {
	init();
	//while (cin >> a >> b)
	solve();
}