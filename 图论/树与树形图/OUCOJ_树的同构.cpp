#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 3e3 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
/*String Hash & dfs*/
ll son1[maxn][2], son2[maxn][2], d1, d2;
vector<ll>pre1(maxn + 5, 0), suf1(maxn + 5, 0), val1(maxn + 5, 0), pos1(maxn + 5, 0);
vector<ll>pre2(maxn + 5, 0), suf2(maxn + 5, 0), val2(maxn + 5, 0), pos2(maxn + 5, 0);
vector<ll>H1, H2;
void solve() {
	ll N;
	std::cin >> N;
	if (not N) {
		puts("Yes");
		cout << 0 << endl;
		return;
	}
	ll p = 23;
	for (ll i = 1; i <= N; i++) {
		std::cin >> pre1[i];
	}
	for (ll i = 1; i <= N; i++)std::cin >> val1[pre1[i]];
	for (ll i = 1; i <= N; i++)std::cin >> suf1[i], pos1[suf1[i]] = i;
	for (ll i = 1; i <= N; i++) {
		std::cin >> pre2[i];
	}
	//根据两序遍历序列确定唯一二叉树
	for (ll i = 1; i <= N; i++)std::cin >> val2[pre2[i]];
	for (ll i = 1; i <= N; i++)std::cin >> suf2[i], pos2[suf2[i]] = i;
	function<void(ll, ll, ll, ll, ll)>dfs = [&](ll cur, ll l1, ll r1, ll l2, ll r2) {
		ll p = pos1[pre1[cur]];
		//cout << cur << endl;
		ll len1 = p - l2, len2 = r2 - p;
		if (not len1 and not len2)return;
		ll lch = cur + 1, rch = cur + 1 + len1;
		if (len1) {
			son1[pre1[cur]][0] = pre1[lch];
			dfs(lch, cur + 1, cur + len1, l2, p - 1);
		}
		if (len2) {
			son1[pre1[cur]][1] = pre1[rch];
			dfs(rch, cur + 1 + len1, cur + len1 + len2, p + 1, r2);
		}
	};

	function<void(ll, ll, ll, ll, ll)>dfs2 = [&](ll cur, ll l1, ll r1, ll l2, ll r2) {
		ll p = pos2[pre2[cur]];
		//cout << cur << endl;
		ll len1 = p - l2, len2 = r2 - p;
		if (not len1 and not len2)return;
		ll lch = cur + 1, rch = cur + 1 + len1;
		if (len1) {
			son2[pre2[cur]][0] = pre2[lch];
			dfs2(lch, l1 + 1, l1 + len1, l2, p - 1);
		}
		if (len2) {
			son2[pre2[cur]][1] = pre2[rch];
			dfs2(rch, l1 + 1 + len1, l1 + len1 + len2, p + 1, r2);
		}
	};
	dfs(1, 1, N, 1, N);  dfs2(1, 1, N, 1, N);
	function<void(ll, ll, ll)>tarjan = [&](ll cur, ll dep, ll Has1) {
		d1 = max(dep, d1);
		Has1 = Has1 * p + val1[cur];
		H1.push_back(Has1);
		//cout << val1[cur] << endl;
		if (son1[cur][0]) {
			tarjan(son1[cur][0], dep + 1, Has1);
		}
		if (son1[cur][1]) {
			tarjan(son1[cur][1], dep + 1, Has1);
		}
	};
	function<void(ll, ll, ll)>tarjan2 = [&](ll cur, ll dep, ll Has1) {
		d2 = max(dep, d2);
		Has1 = Has1 * p + val2[cur];
		//cout << val2[cur] << endl;
		H2.push_back(Has1);
		if (son2[cur][0]) {
			tarjan2(son2[cur][0], dep + 1, Has1);
		}
		if (son2[cur][1]) {
			tarjan2(son2[cur][1], dep + 1, Has1);
		}
	};
	tarjan(pre1[1], 1, 0);
	tarjan2(pre2[1], 1, 0);
	std::sort(H1.begin(), H1.end());
	std::sort(H2.begin(), H2.end());
	ll len = H1.size(), len2 = H2.size(); bool f = 1;
	if (len != len2)f = 0;
	for (ll i = 0; i < len; i++) {
		if (H1[i] != H2[i]) {
			f = 0; break;
		}
	}
	if (not f)puts("No");
	else puts("Yes");
	cout << d1 << endl;
}
signed main() {
	solve();
}