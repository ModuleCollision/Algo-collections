#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e6 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
	ll N, X; cin >> N >> X;
	vector<pair<ll, ll>>A;
	A.push_back({0, -(N + 1)});
	A.push_back({X, N + 1});//必须是从 0 --> X的, 可以理解成 0 为 X 的钥匙
	for (ll i = 1; i <= N; i++) {
		ll X; std::cin >> X;
		A.push_back({X, i});//记录坐标和编号
	}
	for (ll i = 1; i <= N; i++) {
		ll Y; std::cin >> Y;
		A.push_back({Y, -i});
	}
	std::sort(A.begin(), A.end());
	vector<ll>key(N + 2);//记录钥匙在坐标系中的先后次序
	ll M = A.size();//离散化操作
	vector dp(M + 1, vector (M + 1, std::array<ll, 2> {inf, inf}));
	ll pos = 0;
	for (ll i = 0; i < M; i++) {
		if (A[i].second < 0) {
			key[-A[i].second] = i;
		}
		if (A[i].second == N + 1) {
			key[0] = i;
		}
	}
	ll ans = inf;
	dp[key[N + 1]][key[N + 1]][0] = dp[key[N + 1]][key[N + 1]][1] = 0;
	for (ll len = 1; len <= M; len++) {
		for (ll i = 0; i + len - 1 <= M - 1; i++) {
			ll j = i + len - 1;
			vector<ll>coor = {A[i].first, A[j].first};
			for (ll k = 0; k < 2; k++) {
				if (dp[i][j][k] == inf)continue;
				if (key[0] >= i and key[0] <= j) {
					ans = min(ans, dp[i][j][k]);
				}
				if (i > 0) {
					ll pos = A[i - 1].first, idx = A[i - 1].second;
					if (idx < 0 or (key[idx] >= i and key[idx] <= j)) {
						//待转移的这一层是钥匙或者是门而且钥匙坐标已经包含于离散化的坐标之中
						dp[i - 1][j][0] = min(dp[i - 1][j][0], dp[i][j][k] + coor[k] - pos);
					}
				}
				if (j + 1 < M) {
					ll pos = A[j + 1].first, idx = A[j + 1].second;
					if (idx < 0 or (key[idx] >= i and key[idx] <= j)) {
						dp[i][j + 1][1] = min(dp[i][j + 1][1], dp[i][j][k] + pos - coor[k]);
					}
				}
			}
		}
	}
	if (ans == inf) {
		puts("-1"); return;
	}
	cout << ans << endl;
}
signed main() {
	solve();
}