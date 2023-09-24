#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 2e3 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
	string s; std::cin >> s; ll len = s.size();
	s = " " + s;
	ll n; std::cin >> n;
	vector dp1(len + 5, vector (n + 5, array<ll, 2> { -inf, -inf})); //在某坐标, 修改了几次, 朝向哪里的最大值
	vector dp2(len + 5, vector(n + 5, array<ll, 2> { inf, inf}));//在某坐标, 修改了几次, 朝向哪里的最小值
	dp1[0][0][0] = dp2[0][0][0] = 0;
	for (ll i = 1; i <= len; i++) {
		for (ll j = 0; j <= n; j++) {
			if (s[i] == 'T') {
				if (dp1[i - 1][j][1] != -inf)
					dp1[i][j][0] = max(dp1[i][j][0], dp1[i - 1][j][1]);
				if (dp1[i - 1][j][0] != -inf)
					dp1[i][j][1] = max(dp1[i][j][1], dp1[i - 1][j][0]);//不修改
				if (j >= 1) {
					if (dp1[i - 1][j - 1][0] != -inf)
						dp1[i][j][0] = max(dp1[i][j][0], dp1[i - 1][j - 1][0] + 1);
					if (dp1[i - 1][j - 1][1] != -inf)
						dp1[i][j][1] = max(dp1[i][j][1], dp1[i - 1][j - 1][1] - 1);//修改
				}
			} else {
				if (dp1[i - 1][j][0] != -inf)
					dp1[i][j][0] = max(dp1[i][j][0], dp1[i - 1][j][0] + 1);
				if (dp1[i - 1][j][1] != -inf)
					dp1[i][j][1] = max(dp1[i][j][1], dp1[i - 1][j][1] - 1);
				if (j >= 1) {
					if (dp1[i - 1][j - 1][1] != -inf)
						dp1[i][j][0] = max(dp1[i][j][0], dp1[i - 1][j - 1][1]);
					if (dp1[i - 1][j - 1][0] != -inf)
						dp1[i][j][1] = max(dp1[i][j][1], dp1[i - 1][j - 1][0]);
				}
			}
		}
	}
	for (ll i = 1; i <= len; i++) {
		for (ll j = 0; j <= n; j++) {
			if (s[i] == 'T') {
				if (dp2[i - 1][j][1] != inf)
					dp2[i][j][0] = min(dp2[i][j][0], dp2[i - 1][j][1]);
				if (dp2[i - 1][j][0] != inf)
					dp2[i][j][1] = min(dp2[i][j][1], dp2[i - 1][j][0]);//不修改
				if (j >= 1) {
					if (dp2[i - 1][j - 1][0] != inf)
						dp2[i][j][0] = min(dp2[i][j][0], dp2[i - 1][j - 1][0] + 1);
					if (dp2[i - 1][j - 1][1] != inf)
						dp2[i][j][1] = min(dp2[i][j][1], dp2[i - 1][j - 1][1] - 1);//修改
				}
			} else {
				if (dp2[i - 1][j][0] != inf)
					dp2[i][j][0] = min(dp2[i][j][0], dp2[i - 1][j][0] + 1);
				if (dp2[i - 1][j][1] != inf)
					dp2[i][j][1] = min(dp2[i][j][1], dp2[i - 1][j][1] - 1);
				if (j >= 1) {
					if (dp2[i - 1][j - 1][1] != inf)
						dp2[i][j][0] = min(dp2[i][j][0], dp2[i - 1][j - 1][1]);
					if (dp2[i - 1][j - 1][0] != inf)
						dp2[i][j][1] = min(dp2[i][j][1], dp2[i - 1][j - 1][0]);
				}
			}
		}
	}
	ll res = 0;
	if (dp1[len][n][0] != -inf)res = max(res, abs(dp1[len][n][0]));
	if (dp1[len][n][1] != -inf)res = max(res, abs(dp1[len][n][1]));
	if (dp2[len][n][0] != inf)res = max(res, abs(dp2[len][n][0]));
	if (dp2[len][n][1] != inf)res = max(res, abs(dp2[len][n][1]));
	cout << res << endl;
}
signed main() {
	solve();
}