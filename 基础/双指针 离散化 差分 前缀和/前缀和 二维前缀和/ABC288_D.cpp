#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 5e2 + 5;
const ll inf = 0x3f3f3f3f;
const ll mod = 1e9 + 7;
ll n, k, a[maxn], b[maxn], q;
ll sum[15][maxn];//维护的是从l至r下标模k同余的所有数组值的和
void solve() {
	ll l, r;
	std::cin >> l >> r;
	for (ll i = 0; i < k; i++) {
		if (i % k == (r + 1) % k)continue;//d[r + 1] = a[r + 1]可满足
		ll x = sum[i][r] - sum[i][l - 1];
		if (i % k == l % k) {
			if (x != -a[l - 1]) {
				puts("No");
				return;//特判,差分d[l]的值等于-a[l-1],其余为0
			}
		} else {
			if (x) {
				puts("No");
				return;
			}
		}
	}
	puts("Yes");
}
signed main() {
	std::cin >> n >> k;
	for (ll i = 1; i <= n; i++) {
		std::cin >> a[i];
		b[i] = a[i] - a[i - 1];
		for (ll j = 0; j < k; j++) {
			sum[j][i] = sum[j][i - 1];
		}
		sum[i % k][i] += b[i];
	}//维护从l至r模k余i下标的元素的总和
	std::cin >> q;
	while (q--) {
		solve();
	}
}