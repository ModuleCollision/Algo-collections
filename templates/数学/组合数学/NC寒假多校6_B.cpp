#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef long double lb;
const ll maxn = 2e5 + 5;
const ll inf = 0x3f3f3f3f;
const ll mod = 998244353;
void solve() {
	ll n; cin >> n; vector<ll>S(n + 5, 0);
	vector<ll>T(n + 5, 0);
	for (ll i = 1; i <= n; i++)cin >> S[i];
	for (ll i = 1; i <= n; i++)cin >> T[i];
	std::sort(S.begin() + 1, S.begin() + 1 + n);
	std::sort(T.begin() + 1, T.begin() + 1 + n);
	ll ans = 0;
	vector C(n + 1, vector<ll>(n + 1, 0));
	for (ll i = 0; i <= n; i++) {
		for (ll j = 0; j <= i; j++) {
			if (not j)C[i][j] = 1;
			else C[i][j] = (C[i - 1][j] % mod + C[i - 1][j - 1]) % mod;
		}
	}
	auto ksm = [&](ll x, ll y) {
		ll ret = 1;
		while (y) {
			if (y & 1)ret = ret * x % mod;
			x = x * x % mod;
			y >>= 1;
		}
		return ret;
	};
	/*for (ll i = 0; i <= 20; i++) {
		for (ll j = 0; j <= i; j++) {
			if (not j)C[i][j] = 1;
			else C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
		}
	}
	for (ll i = 0; i <= 10; i++) {
		for (ll j = 0; j <= 10; j++) {
			ll s1 = min(i, j); ll s2 = max(i, j);
			ll v = 0;
			for (ll i = 0; i <= s1; i++) {
				v += C[s1][i] * C[s2][i];
			}
			cout << v << " ";
		}
		cout << endl;
	}*/
	//打表内容, 处理出ΣCis1 * Cis2的值
	vector f(n + 5, vector<ll>(n + 5, 0));
	for (ll i = 0; i <= n; i++)f[0][i] = 1;
	for (ll j = 0; j <= n; j++)f[j][0] = 1;
	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j <= n; j++) {
			f[i][j] = (f[i][j - 1] % mod + f[i - 1][j]) % mod;
			//cout << f[i][j] << " ";
		}
	}
	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j <= n; j++) {
			ll cur1 = S[i], cur2 = T[j];//枚举cur1 , cur2是数列中第几大的
			if (cur1 == cur2)continue;
			ll p1 = min(n - i, n - j);
			ll p2 = max(n - i, n - j);
			ll p3 = min(i - 1, j - 1);
			ll p4 = max(i - 1, j - 1);
			ll v = f[p1][p2] % mod * f[p3][p4] % mod;
			ans = (ans % mod + v % mod * abs(cur1 - cur2)) % mod;
		}
	}
	cout << ans << endl;
}
signed main() {
	solve();
}