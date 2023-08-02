/*AC自动机用于判定多少个下标不同的字符串出现于文本串中*/
#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 7e6 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
ll tot = 0, tr[maxn][26];
ll fail[maxn], e[maxn];
void solve() {
	ll n; std::cin >> n;
	auto insert = [&](string s) {
		ll u = 0;
		for (ll i = 0; i < s.size(); i++) {
			if (not tr[u][s[i] - 'a']) {
				tr[u][s[i] - 'a'] = ++tot;
			}
			u = tr[u][s[i] - 'a'];
		}
		e[u]++;
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
			for (ll j = u; j and e[j] != -1; j = fail[j]) {
				res += e[j]; e[j] = -1;//避免重复计算
			}
		}
		return res;
	};
	for (ll i = 0; i < n; i++) {
		string s; std::cin >> s;
		insert(s);
	}
	build();
	string t; cin >> t;
	cout << query(t) << endl;
}
signed main() {
	solve();
}