#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 3e5 + 5;
const ll inf = 0x3f3f3f3f;
const ll mod = 998244353;
char s[maxn];//树状数组 + 前缀和
void solve() {
	ll n;
	cin >> (s + 1);
	n = strlen(s + 1);
	//n = (ll)st.size() - 1;
	//cout << st << endl;
	vector<ll>tr(n + 5, 0), c1(n + 5, 0), c2(n + 5, 0);
	for (ll i = 1; i <= n; i++) {
		c1[i] = c1[i - 1] + (s[i] == 'd');
		c2[i] = c2[i - 1] + (s[i] == 'u');
	}//前缀和
	auto lowbit = [&](ll x)->ll{
		return x & -x;
	};
	auto add = [&](ll id, ll v) {
		for (; id <= n; id += lowbit(id)) {
			tr[id] += v;
		}
	};
	auto query = [&](ll id)->ll{
		ll ret = 0;
		for (; id > 0; id -= lowbit(id)) {
			ret += tr[id];
		}
		return ret;
	};
	for (ll i = 1; i <= n; i++) {
		if (s[i] == 'd') {
			//if (c2[i - 1] and c2[n] - c2[i]) {
			add(1, c2[n] - c2[i]);
			add(i, c2[i] - c2[n]);
			add(i + 1, c2[i - 1]);
			add(n + 1, -c2[i - 1]);//这里用到了差分的思想
			//}
		}
	}
	ll id = 0, vs = -inf;
	for (ll i = 1; i <= n; i++) {
		if (s[i] == 'd') {

			ll t = c2[i - 1] * (c2[n] - c2[i]);
			//cout << t << endl;
			if (t > vs) {
				id = i;
				vs = t;
			}
		} else if (s[i] == 'u') {
			ll t = query(i);
			//cout << t << endl;
			if (t > vs) {
				id = i;
				vs = t;
			}
		}
	}
	s[id] = 'k';
	cout << (s + 1) << endl;
}
signed main() {
	solve();
}