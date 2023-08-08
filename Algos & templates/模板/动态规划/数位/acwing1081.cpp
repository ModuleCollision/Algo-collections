#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 3010;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
	ll x, y, k, b; std::cin >> x >> y >> k >> b;
	vector<ll>p(35, 0); p[0] = 1;
	for (ll i = 1; i <= 10; i++) {
		p[i] = p[i - 1] * i;
	}
	vector c(35, vector<ll>(35, 0));
	for (ll i = 0; i <= 32; i++) {
		for (ll j = 0; j <= i; j++) {
			if (not j)c[i][j] = 1;
			else c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
		}
	}
	/*递推组合数(防止 爆 long long int)*/
	auto dp = [&](ll n) {
		if (not n)return 0ll;
		ll ret = 0 ;
		vector<ll>s;
		while (n) {
			s.push_back(n % b); n /= b;
		}
		ll w = s.size();
		for (ll i = w - 1, las = 0; i >= 0; i--) {
			ll cur = s[i];
			if (cur) {
				ret += c[i][k - las];
				if (cur > 1) {
					if (k - las - 1 >= 0)ret += c[i][k - las - 1];
					break;
				} else {
					las++;
					if (las > k)break;
				}
			}
			if (i == 0 and las == k)ret++;
		}
		return ret;
	};
	cout << dp(y) - dp(x - 1) << endl;
}
signed main() {
	solve();
}