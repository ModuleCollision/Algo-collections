/*也可以通过模拟 + 贪心解决*/
/*每次拿出最大的重合对数最大的两个字母*/
#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e5 + 5;
const ll inf = 0x3f3f3f3f;
const ll mod = 1e9 + 7;
ll n; char s[maxn];
struct sq {
	ll v; ll idx;
	bool operator<(const sq &b)const {
		return v < b.v;
	}
};
void solve() {
	std::cin >> n >> (s + 1);
	vector<ll>cnt(30, 0); ll k[30][30];
	memset(k, 0, sizeof(k));
	if (n & 1) {
		puts("-1"); return;
	}
	for (ll i = 1; i <= n / 2; i++) {
		ll l = s[i] - 'a' + 1, r = s[n - i + 1] - 'a' + 1;
		k[l][r]++;
		if (l == r) {
			cnt[l]++;
		}
	}
	priority_queue<sq>q;
	for (ll i = 0; i < 26; i++) {
		if (cnt[i])
			q.push({cnt[i], i});
	}
	ll ans = 0;
	while (q.size() >= 2) {
		auto it1 = q.top(); q.pop();
		auto it2 = q.top(); q.pop();
		ll v1 = it1.v, idx1 = it1.idx;
		ll v2 = it2.v, idx2 = it2.idx;
		it1.v--; it2.v--;
		ans++;
		k[idx1][idx2]++;
		k[idx2][idx1]++;
		if (it1.v)q.push(it1);
		if (it2.v)q.push(it2);
	}
	if (not q.size()) {
		cout << ans << endl;
		return;
	}
	ll v = q.top().v, idx = q.top().idx;
	for (ll i = 0; i < 26; i++) {
		for (ll j = 0; j < 26; j++) {
			if (i == idx or j == idx or i == j)continue;
			ll ks = min(v, k[i][j]);
			k[i][j] -= ks; v -= ks;
			ans += ks;
			if (not v) {
				cout << ans << endl; return;
			}
		}
	}
	puts("-1"); return;
}
ll T;
signed main() {
	std::cin >> T;
	while (T--)
		solve();
}
