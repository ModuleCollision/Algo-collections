#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e6 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 233;
//后缀数组裸题, rk:后缀编号 --> 字典序排名 sa:字典序排名 --> 后缀编号
ll sa[maxn], rk[maxn], oldrk[maxn << 1], id[maxn], key1[maxn], cnt[maxn];
void solve() {
	string s; std::cin >> s;
	ll n = s.size();
	auto cmp = [&](ll x, ll y, ll w) {
		return oldrk[x] == oldrk[y] and oldrk[x + w] == oldrk[y + w];
	};
	s = " " + s;
	ll m = 127, p, w, i;
	for (i = 1; i <= n; i++)++cnt[rk[i] = s[i]];
	for (i = 1; i <= m; i++)cnt[i] += cnt[i - 1];
	for (i = n; i >= 1; i--)sa[cnt[rk[i]]--] = i;//计数排序
	for (w = 1;; w <<= 1, m = p) {
		for (p = 0, i = n; i > n - w; --i)id[++p] = i;
		for (i = 1; i <= n; i++) {
			if (sa[i] > w)id[++p] = sa[i] - w;
		}
		memset(cnt, 0, sizeof(cnt));
		for (i = 1; i <= n; i++) {
			++cnt[key1[i] = rk[id[i]]];
		}
		for (i = 1; i <= m; i++)cnt[i] += cnt[i - 1];
		for (i = n; i >= 1; i--)sa[cnt[key1[i]]--] = id[i];
		for (i = 1; i <= n; i++) {
			oldrk[i] = rk[i];
		}
		for (p = 0, i = 1; i <= n; i++) {
			rk[sa[i]] = cmp(sa[i], sa[i - 1], w) ? p : ++p;
		}
		if (p == n) {
			for (i = 1; i <= n; i++)sa[rk[i]] = i;
			break;
		}
	}
	for (i = 1; i <= n; i++)cout << sa[i] << " ";
	cout << endl;
}
signed main() {
	solve();
}
