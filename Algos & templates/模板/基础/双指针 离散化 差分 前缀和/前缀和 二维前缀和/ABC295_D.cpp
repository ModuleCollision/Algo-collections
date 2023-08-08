#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e6 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
std::map<ll, ll>k;
char s[maxn];
void solve() {
	std::cin >> (s + 1);
	ll n = strlen(s + 1);
	ll cur = 0, ans = 0; k[cur]++;
	for (ll i = 1; i <= n; i++) {
		cur ^= (1 << (s[i] - '0'));
		ans += k[cur];
		k[cur]++;
	}
	cout << ans << endl;
}
signed main() {
	solve();
}