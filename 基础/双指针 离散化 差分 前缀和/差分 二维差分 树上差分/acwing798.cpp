/*二维差分模板*/
#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 3e2 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
ll d[maxn][maxn], a[maxn][maxn];
ll n, m, q, x, y, s, t, c;
void solve() {
	std::cin >> n >> m >> q;
	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j <= m; j++) {
			std::cin >> a[i][j];
		}
	}
	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j <= m; j++) {
			d[i][j] = (a[i][j] - a[i - 1][j] - a[i][j - 1] + a[i - 1][j - 1]);
		}
	}
	for (ll i = 1; i <= q; i++) {
		std::cin >> x >> y >> s >> t >> c;
		d[x][y] += c;
		d[s + 1][t + 1] += c;
		d[x][t + 1] -= c;
		d[s + 1][y] -= c;
	}
	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j <= m; j++) {
			d[i][j] += d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1];
			cout << d[i][j] << " ";
		}
		cout << endl;
	}
}
signed main() {
	solve();
}