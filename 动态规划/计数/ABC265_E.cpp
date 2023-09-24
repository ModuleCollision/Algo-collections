#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 3e2 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
ll dp[maxn][maxn][maxn];
ll N, M, A, B, C, D, E, F;
std::map<pair<ll, ll>, ll>vis;
void solve() {
	std::cin >> N >> M;
	for (ll i = 1; i <= M; i++) {
		ll X, Y;
		std::cin >> X >> Y;
		vis[ {X, Y}] = 1;

	}
	dp[0][0][0] = 1; ll ans = 0;
	for (ll i = 0; i <= N; i++) {
		for (ll j = 0; j <= N - i; j++) {
			for (ll k = 0; k <= N - i - j; k++) {
				ll nx = i * A + j * C + k * E;
				ll ny = i * B + j * D + k * F;
				if (vis[ {nx, ny}])continue;
				if (i)dp[i][j][k] = (dp[i][j][k] % mod + dp[i - 1][j][k]) % mod;
				if (j)dp[i][j][k] = (dp[i][j][k] % mod + dp[i][j - 1][k]) % mod;
				if (k)dp[i][j][k] = (dp[i][j][k] % mod + dp[i][j][k - 1]) % mod;
				if (i + j + k == N) {
					ans = ans % mod + dp[i][j][k] % mod;
				}
			}
		}
	}
	cout << ans << endl;
}
signed main() {
	solve();
}