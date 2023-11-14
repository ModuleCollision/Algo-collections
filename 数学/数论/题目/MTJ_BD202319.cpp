#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
typedef unsigned long long ull;
const ll maxn = 1e7 + 10;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
bool vis[maxn];  ll cnt = 0;
void solve() {
	ll x; std::cin >> x;
	cout << "f(" << x << ")=";
	for (ll i = 2; i <= x; i++) {
		if (not vis[i]) {
			ll sum = 0;
			sum += (1) * (x - i + 1);
			for (ll j = i + i; j <= x; j += i) {
				vis[j] = 1;
				ll tmp = j; ll c = 0; while (tmp % i == 0) {
					tmp /= i, c++;
				}
				c *= (x - j + 1); sum += c;
			}
			if (i != 2)cout << "*" << "";
			cout << i << "";
			if (sum != 1)cout << "^" << sum << "";
		}
	}
}
signed main() {
	solve();
}

#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
typedef unsigned long long ull;
const ll maxn = 1e7 + 10;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
int prime[maxn]; int cnt = 0; bool vis[maxn];
void solve() {
	ll x; std::cin >> x;
	cout << "f(" << x << ")=";
	for (int i = 2; i <= x; i++) {
		if (not vis[i]) {
			prime[++cnt] = i;
		}
		for (ll j = 1; prime[j]*i <= x and j <= cnt; j++) {
			vis[prime[j]*i] = 1;
			if (i % prime[j] == 0)break;
		}
	}
	for (int i = 1; i <= cnt; i++) {
		ll sum = 0;
		for (ll d = prime[i]; d <= x; d *= prime[i]) {
			ll st = x + 1 - x / d * d, ed = x + 1 - d;
			sum += 1ll * ((ed - st + d) / d ) * (ed + st) / 2;
		}
		if (i != 1)cout << "*" << "";
		cout << prime[i];
		if (sum != 1)cout << "^" << sum << "";
	}
}
signed main() {
	solve();
}