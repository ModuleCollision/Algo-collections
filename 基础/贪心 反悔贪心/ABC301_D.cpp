#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 5e3 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
	string s; std::cin >> s;
	ll N; std::cin >> N;
	reverse(s.begin(), s.end());
	ll cur = 0;
	ll ks = s.size();
	vector<ll>idx;
	for (ll i = 0; i < ks; i++) {
		if (s[i] == '1') {
			cur += (1ll << i);
		}
	}
	if (cur > N) {
		puts("-1"); return;
	}
	ll ans = cur;
	for (ll i = 0; i < ks; i++)if (s[i] == '?')idx.push_back(i);
	ll len = idx.size();
	for (ll i = len - 1; i >= 0; i--) {
		ll t = cur + (1ll << idx[i]);
		if (t > N)continue;
		for (ll j = i - 1; j >= 0; j--) {
			if ((t + (1ll << idx[j])) > N)continue;
			else t += (1ll << idx[j]);
		}
		ans = max(ans, t);
	}
	cout << ans << endl;
}
signed main() {
	solve();
}