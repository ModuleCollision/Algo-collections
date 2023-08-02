/*字典树+拓扑排序*/
/*一个字符串用于确立大小关系,如果出现了环即为自相矛盾,这里采用拓扑排序判环*/
/*显然,字典树用于确立前缀关系*/
#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 5e2 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
bool ed[maxn];
ll tr[maxn][30], tot = 0;
ll d[30]; vector<ll>G[30];
vector<string>ans;
bool top_sort() {
	ll cnt = 0;
	queue<ll>q;
	for (ll i = 0; i < 26; i++) {
		if (d[i] == 0) {
			q.push(i);
		}
	}
	while (q.size()) {
		auto cur = q.front(); q.pop();
		cnt++;
		for (auto c : G[cur]) {
			d[c]--;
			if (d[c] == 0) {
				q.push(c);
			}
		}
	}
	return cnt == 26;
}
void insert(string s) {
	ll u = 0;
	for (auto c : s) {
		ll cur = c - 'a';
		if (not tr[u][cur]) {
			tr[u][cur] = ++tot;
		}
		u = tr[u][cur];
	}
	ed[u] = true;
}
bool check(string s) {
	ll u = 0;
	for (ll i = 0; i < s.size(); i++) {
		for (ll j = 0; j < 26; j++) {
			if (j == s[i] - 'a') {
				continue;
			}
			if (tr[u][j]) {
				G[s[i] - 'a'].push_back(j);
				d[j]++;
			}//同一前缀在本位的不同字母
		}
		/*字典序最小则说明对于这个字符串,对于任意重合前缀的字符串,我们的该位置字符字典序必然小*/
		u = tr[u][s[i] - 'a'];
		if (ed[u] and i != s.size() - 1)return false;
	}
	return top_sort();
}
ll N; string s[maxn];
void solve() {
	std::cin >> N;
	for (ll i = 1; i <= N; i++) {
		std::cin >> s[i];
		insert(s[i]);
	}
	for (ll i = 1; i <= N; i++) {
		memset(d, 0, sizeof(d));
		for (ll j = 0; j < 26; j++)G[j].clear();
		if (check(s[i])) {
			ans.push_back(s[i]);
		}
	}
	cout << ans.size() << endl;
	for (auto v : ans) {
		cout << v << endl;
	}
}
signed main() {
	solve();
}