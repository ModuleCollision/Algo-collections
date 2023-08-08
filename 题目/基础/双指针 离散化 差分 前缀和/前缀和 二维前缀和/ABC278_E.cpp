#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 3e2 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
ll A[maxn][maxn], sum[maxn][maxn][maxn];
ll H, W, N, h, w;
std::map<ll, ll>cnt;
//二维前缀和
void solve() {
	set<ll>x;
	std::cin >> H >> W >> N >> h >> w;
	for (ll i = 1; i <= H; i++) {
		for (ll j = 1; j <= W; j++) {
			std::cin >> A[i][j];
			x.insert(A[i][j]);
			cnt[A[i][j]]++;
			sum[i][j][A[i][j]]++;
			for (ll k = 1; k <= N; k++) {
				sum[i][j][k] += sum[i - 1][j][k] + sum[i][j - 1][k] - sum[i - 1][j - 1][k];
			}//二维关于某数的前缀和
		}
	}
	for (ll i = h; i <= H; i++) {
		for (ll j = w; j <= W; j++) {
			ll ans = x.size();
			for (ll k = 1; k <= N; k++) {
				ll res = sum[i][j][k] - sum[i - h][j][k] - sum[i][j - w][k] + sum[i - h][j - w][k];
				if (res == cnt[k]) {
					ans--;
				}
			}
			cout << ans << endl;
		}
	}
}
signed main() {
	solve();
}