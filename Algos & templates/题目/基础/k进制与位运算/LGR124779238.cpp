#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 3010;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
ll tr1[20000005]; ll tr2[20000005];
void solve() {
	ll n; std::cin >> n;
	vector<ll>A(n + 5, 0);
	for (ll i = 1; i <= n; i++)cin >> A[i];
	for (ll i = 1; i <= n; i++)A[i] += A[i - 1];
	auto add1 = [&](ll idx, ll v) {
		for (; idx <= 2e7; idx += (idx & -idx))tr1[idx] += v;
	};
	auto query1 = [&](ll idx) {
		ll ret = 0;
		for (; idx >= 1; idx -= (idx & -idx))ret += tr1[idx];
		return ret;
	};
	auto add2 = [&](ll idx, ll v) {
		for (; idx <= 2e7; idx += (idx & -idx))tr2[idx] += v;
	};
	//统计高位 1 的个数
	auto query2 = [&](ll idx) {
		ll ret = 0;
		for (; idx >= 1; idx -= (idx & -idx))ret += tr2[idx];
		return ret;
	}; ll ans = 0;//统计高位 0 的个数
	for (ll j = 0; j <= 25; j++) {
		ll msk = (1 << j); ll cnt = 0;
		memset(tr1, 0, sizeof(tr1));
		memset(tr2, 0, sizeof(tr2));
		for (ll i = 0; i <= n; i++) {
			ll md = (A[i]) % msk; md += 1;
			if (A[i] & (1 << j)) {
				//递增： 同为 1 可以借位补 1
				cnt += query1(2e7) - query1(md);
				//递增 该位不是 1
				cnt += query2(md);
				add1(md, 1);
			} else {
				cnt += query2(2e7) - query2(md);
				cnt += query1(md);
				add2(md, 1);
			}
		}
		if (cnt & 1)ans += (1 << j);
	}
	cout << ans << endl;
}
signed main() {
	solve();
}