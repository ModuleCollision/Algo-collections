/*状压dp:*/
#include<bits/stdc++.h>
using namespace std;
typedef  long long ll;
const int maxn = 2005;
const ll inf = 1e6 + 5;
ll N, M;
void solve() {
	//std::cin >> N >> M;
	vector<vector<ll>>dp(M + 5, vector<ll>((1 << N), 0));
	vector<bool>st((1 << N), false);
	std::map<ll, vector<ll>>tr;
	for (ll i = 0; i < (1 << N); i++) {
		ll cnt = 0; bool is_valid = true;
		for (ll j = 1; j <= N; j++) {
			if ((i >> (j - 1)) & 1) {
				if (cnt & 1) {
					is_valid = false;
					break;
				} else {
					cnt = 0;
				}
			} else {
				cnt++;
			}//统计状态中奇数个空白的个数
		}
		if (cnt & 1) {
			is_valid = false;
		}//不能出现奇数个连续的空白
		st[i] = is_valid;
	}
	for (ll i = 0; i < (1 << N); i++) {
		for (ll j = 0; (j < (1 << N)); j++) {
			if (st[i | j] and not(i & j)) {
				tr[i].push_back(j);
			}
		}
	}
	for (ll i = 0; i < (1 << N); i++) {
		if (st[i]) {
			dp[1][i]++;
		}
	}
	for (ll i = 2; i <= M; i++) {
		for (ll j = 0; j < (1 << N); j++) {
			for (auto k : tr[j]) {
				dp[i][j] += dp[i - 1][k];
			}
		}
	}
	cout << dp[M][0] << endl;
}
signed main() {
	while (std::cin >> N >> M and N and M)
		solve();
}