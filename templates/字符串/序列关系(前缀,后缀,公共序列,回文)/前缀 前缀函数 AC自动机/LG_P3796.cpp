/*AC自动机用于判定字符串中出现最多的文本串*/
#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 2e6 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
ll tot = 0, tr[maxn][26];
ll fail[maxn], idx[maxn], val[maxn];
ll cnt[maxn];
ll n;
void solve() {
	memset(tr, 0, sizeof(tr));
	memset(fail, 0, sizeof(fail));
	memset(idx, 0, sizeof(idx));
	memset(val, 0, sizeof(val));
	memset(cnt, 0, sizeof(cnt));
	tot = 0;
	auto insert = [&](string s, ll id) {
		ll u = 0;
		for (ll i = 0; i < s.size(); i++) {
			if (not tr[u][s[i] - 'a']) {
				tr[u][s[i] - 'a'] = ++tot;
			}
			u = tr[u][s[i] - 'a'];
		}
		idx[u] = id;
	};
	auto build = [&]() {
		queue<ll>q;
		for (ll i = 0; i < 26; i++) {
			if (tr[0][i])q.push(tr[0][i]);
		}
		while (q.size()) {
			ll u = q.front();
			q.pop();
			for (ll i = 0; i < 26; i++) {
				if (tr[u][i]) {
					fail[tr[u][i]] = tr[fail[u]][i];
					q.push(tr[u][i]);
				} else {
					tr[u][i] = tr[fail[u]][i];
				}
			}
		}
	};
	auto query = [&](string t) {//代表
		ll u = 0; ll res = 0;
		for (ll i = 0; i < t.size(); i++) {
			u = tr[u][t[i] - 'a'];
			for (ll j = u; j; j = fail[j]) {
				val[j]++;
			}
		}
		for (int i = 0; i <= tot; i++) {
			if (idx[i]) {
				res = max(res, val[i]);
				cnt[idx[i]] = val[i];
			}
		}
		return res;
	};
	vector<string>s(n + 5);
	for (ll i = 1; i <= n; i++) {
		std::cin >> s[i];
		insert(s[i], i);
	}
	build();
	string t; cin >> t;
	ll x = query(t); cout << x << endl;
	for (ll i = 1; i <= n; i++) {
		if (cnt[i] == x) {
			cout << s[i] << endl;
		}
	}
}
signed main() {
	while (cin >> n and n) {
		solve();
	}
}