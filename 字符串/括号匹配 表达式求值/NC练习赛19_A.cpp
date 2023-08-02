#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e6 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 233;
struct sq {
	ll len; ll dep; ll ans;
};
char s[maxn];
void solve() {
	ll ans = 0;
	std::cin >> (s + 1);
	ll len = strlen(s + 1);
	vector<ll>tr[len + 5]; vector<ll>stk(len + 5, 0);
	ll top = 0;
	for (ll i = 1; i <= len; i++) {
		if (s[i] == '(') {
			tr[stk[top]].push_back(i);
			top++;
			stk[top] = i;
		} else if (s[i] == ')')top--;
	}
	function<sq(ll)>dfs = [&](ll id)->sq{
		if (tr[id].size() == 0) {
			auto ret = (sq) {1, 1, 1};
			return ret;
		}
		ll cnt = 0; ll len = 0, dep = 0; ll pre = 0;
		for (auto v : tr[id]) {
			auto k = dfs(v);
			cnt++;
			pre += k.ans;
			len += k.len;
			dep = max(dep, k.dep + 1);
		}
		ll ans = (len + cnt + 1) * dep - pre;
		return (sq) {len + cnt + 1, dep, ans};
	};
	for (auto v : tr[0]) {
		auto k = dfs(v);
		ans += k.ans;
	}
	cout << ans << endl;
}
signed main() {
	ll T; std::cin >> T;
	while (T--)solve();
}