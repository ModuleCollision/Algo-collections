/*暴力,Floyd*/
#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 2e2 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
ll d[maxn][maxn], x[maxn], y[maxn], p[maxn];
ll N;
void solve() {
	std::cin >> N;
	for (ll i = 1; i <= N; i++) {
		std::cin >> x[i] >> y[i] >> p[i];
	}
	for (ll i = 1; i <= N; i++) {
		for (ll j = 1; j <= N; j++) {
			ll dis = abs(x[i] - x[j]) + abs(y[j] - y[i]);
			//i == j则初始化为0
			//否则初始化为边或者inf
			d[i][j] = (dis + p[i] - 1) / p[i];//Floyd初始化
		}
	}
	for (ll k = 1; k <= N; k++) {
		for (ll i = 1; i <= N; i++) {
			for (ll j = 1; j <= N; j++) {
				d[i][j] = min(d[i][j], max(d[i][k] , d[k][j]));
			}
		}
	}//先枚举k,再枚举i,最后枚举j
	ll ans = inf;
	for (ll i = 1; i <= N; i++) {//枚举起点
		ll cur = 0;
		for (ll j = 1; j <= N; j++) {
			cur = max(cur, d[i][j]);
		}//保证起点联通的下限
		ans = min(ans, cur);
	}//更新答案
	cout << ans << endl;
}
signed main() {
	solve();
}