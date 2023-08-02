#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 2e3 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
char op[maxn];
ll dp1[maxn][maxn][2], dp2[maxn][maxn][2], N;
void solve() {
	memset(dp1, -0x3f, sizeof(dp1));
	memset(dp2, 0x3f, sizeof(dp2));
	dp1[0][0][0] = dp2[0][0][0] = 0;
	std::cin >> (op + 1);
	std::cin >> N;
	ll len = strlen(op + 1);//右为正方向
	for (ll i = 1; i <= len; i++) {
		dp1[i][0][0] = dp2[i][0][0] = dp1[i][0][1] = dp2[i][0][1] = 0;
	}
	for (ll i = 1; i <= len; i++) {
		for (ll j = 0; j <= min(i, N); j++) {
			if (j) {
				if (op[i] == 'T') {
					dp1[i][j][1] = max(dp1[i][j][1], dp1[i - 1][j][0]);
					dp1[i][j][0] = max(dp1[i][j][0], dp1[i - 1][j][1]);//不修改
					dp1[i][j][1] = max(dp1[i][j][1], dp1[i - 1][j - 1][1] - 1);
					dp1[i][j][0] = max(dp1[i][j][0], dp1[i - 1][j - 1][0] + 1);//修改
				} else if (op[i] == 'F') {
					dp1[i][j][1] = max(dp1[i][j][1], dp1[i - 1][j][1] - 1);
					dp1[i][j][0] = max(dp1[i][j][0], dp1[i - 1][j][0] + 1);
					dp1[i][j][1] = max(dp1[i][j][1], dp1[i - 1][j - 1][0]);
					dp1[i][j][0] = max(dp1[i][j][0], dp1[i - 1][j - 1][1]);
				}
			} else {
				if (op[i] == 'T') {
					dp1[i][j][1] = max(dp1[i][j][1], dp1[i - 1][j][0]);
					dp1[i][j][0] = max(dp1[i][j][0], dp1[i - 1][j][1]);//不修改
				} else if (op[i] == 'F') {
					dp1[i][j][1] = max(dp1[i][j][1], dp1[i - 1][j][1] - 1);
					dp1[i][j][0] = max(dp1[i][j][0], dp1[i - 1][j][0] + 1);
				}
			}
		}
	}
	for (ll i = 1; i <= len; i++) {
		for (ll j = 0; j <= min(i, N); j++) {
			if (j) {
				if (op[i] == 'T') {
					dp2[i][j][1] = min(dp2[i][j][1], dp2[i - 1][j][0]);
					dp2[i][j][0] = min(dp2[i][j][0], dp2[i - 1][j][1]);//不修改
					dp2[i][j][1] = min(dp2[i][j][1], dp2[i - 1][j - 1][1] - 1);
					dp2[i][j][0] = min(dp2[i][j][0], dp2[i - 1][j - 1][0] + 1);//修改
				} else if (op[i] == 'F') {
					dp2[i][j][1] = min(dp2[i][j][1], dp2[i - 1][j][1] - 1);
					dp2[i][j][0] = min(dp2[i][j][0], dp2[i - 1][j][0] + 1);
					dp2[i][j][1] = min(dp2[i][j][1], dp2[i - 1][j - 1][0]);
					dp2[i][j][0] = min(dp2[i][j][0], dp2[i - 1][j - 1][1]);
				}
			} else {
				if (op[i] == 'T') {
					dp2[i][j][1] = min(dp2[i][j][1], dp2[i - 1][j][0]);
					dp2[i][j][0] = min(dp2[i][j][0], dp2[i - 1][j][1]);//不修改
				} else if (op[i] == 'F') {
					dp2[i][j][1] = min(dp2[i][j][1], dp2[i - 1][j][1] - 1);
					dp2[i][j][0] = min(dp2[i][j][0], dp2[i - 1][j][0] + 1);
				}
			}
		}
	}
	cout << max({abs(dp1[len][N][0]), abs(dp1[len][N][1]), abs(dp2[len][N][0]),
	             abs(dp2[len][N][1])
	            }) << endl;
}
signed main() {
	solve();
}