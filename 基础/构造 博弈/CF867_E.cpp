#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e5 + 5;
const ll inf = 0x3f3f3f3f;
const ll mod = 1e9 + 7;
ll n; char s[maxn];
void solve() {
	std::cin >> n >> (s + 1);
	if (n & 1) {
		puts("-1"); return;
	}
	vector<ll>cnt(30, 0), ks(30, 0);
	for (ll i = 1; i <= n; i++) {
		cnt[s[i] - 'a']++;
	}
	ll mx = *max_element(cnt.begin(), cnt.begin() + 26);
	ll sum = 0;
	if (mx > n / 2) {
		puts("-1"); return;
	}
	for (ll i = 1; i <= n / 2; i++) {
		if (s[i] == s[n - i + 1]) {
			sum += 1;	ks[s[i] - 'a']++;
		}
	}
	mx = *max_element(ks.begin(), ks.begin() + 26);
	if (mx <= (sum) / 2) {
		cout << (sum + 1) / 2 << endl;
	} else {
		cout << mx << endl;
	}
}
ll T;
signed main() {
	std::cin >> T;
	while (T--)
		solve();
}




