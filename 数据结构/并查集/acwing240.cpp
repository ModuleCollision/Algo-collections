/*并查集*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e3 + 5;
const ll inf = 0x3f3f3f3f;
int fa[maxn], d[maxn], n, k;
void init() {
	for (int i = 1; i <= n; i++) {
		fa[i] = i;
	}
}
int find(int x) {
	if (fa[x] == x) {
		return x;
	}
	int ff = find(fa[x]);
	d[x] += d[fa[x]];
	fa[x] = ff;
	return fa[x];
}
void solve() {
	std::cin >> n >> k;
	init();
	int s, x, y, ans = 0;
	for (int i = 1; i <= k; i++) {
		std::cin >> s >> x >> y;
		if (x > n or y > n) {
			ans++; continue;
		}
		if (s == 2 and x == y) {
			ans++; continue;
		}
		int tmp;
		if (s == 2) {
			tmp = 1;
		} else {
			tmp = 0;
		}
		int a = find(x), b = find(y);
		if (a == b) {
			if (((d[x] - d[y]) % 3 + 3) % 3 != tmp) {
				ans++;
			}
		} else {
			fa[a] = b;
			//依题意,d[x] + d[a] = d[y] + tmp
			d[a] = d[y] - d[x] + tmp;
		}
	}
	cout << ans;
}
signed main() {
	solve();
}