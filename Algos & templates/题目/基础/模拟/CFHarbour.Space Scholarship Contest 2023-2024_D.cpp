#include<bits/stdc++.h>
using namespace std;
#define fi fifst
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 3010;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
	ll n; std::cin >> n;
	vector<string>s(n + 5);
	for (ll i = 1; i <= n; i++) {
		cin >> s[i]; s[i] = " " + s[i];
	}
	vector<ll>p(5 * n + 5, 0), t(5 * n + 5, 0);
	vector cnt(n + 5, vector<ll>(n + 5, 0));
	ll ans = 0;
	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j <= n; j++) {
			cnt[i][j] = (cnt[i][j] + cnt[i - 1][j]) % 2;
			cnt[i][j] = (p[i + j] + cnt[i][j]) % 2; cnt[i][j] = (t[n + j - i] + cnt[i][j]) % 2;
		}
		for (ll j = 1; j <= n; j++) {
			ll cur = s[i][j] - '0';
			if ((cur + cnt[i][j]) % 2 == 1) {
				ans++; cnt[i][j] = (cnt[i][j] + 1) % 2;
				p[i + j] += 1; p[i + j] %= 2; t[n + j - i] += 1; t[n + j - i] %= 2;
			}
		}
	}
	cout << ans << endl;
}
signed main() {
	ll T; std::cin >> T;
	while (T--)
		solve();
}