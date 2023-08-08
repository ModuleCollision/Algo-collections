/*二分经典问题,由于维护区间的信息具有单调性,故用双指针+二分维护*/
#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e6 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
int st_max[maxn][20], st_min[maxn][20], lg[maxn];
int n, k, a[maxn];
void init() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> st_max[i][0];
		st_min[i][0] = st_max[i][0];
	}
	for (int i = 2; i < maxn; i++) {
		lg[i] = lg[i >> 1] + 1;
	}
	for (int len = 1; (1 << len) <= n; len++) {
		for (int i = 1; i + (1 << len) - 1 <= n; i++) {
			st_min[i][len] = min(st_min[i][len - 1], st_min[i + (1 << (len - 1))][len - 1]);
			st_max[i][len] = max(st_max[i][len - 1], st_max[i + (1 << (len - 1))][len - 1]);
		}//dp处理st表
	}
}
int query1(int l, int r) {
	int x = lg[r - l + 1];
	return max(st_max[l][x], st_max[r - (1 << x) + 1][x]);
}
int query2(int l, int r) {
	int x = lg[r - l + 1];
	return min(st_min[l][x], st_min[r - (1 << x) + 1][x]);
}
signed main() {
	init();
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int l = i, r = n; int L = -1, R = -1;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (query1(i, mid) - query2(i, mid) < k) {
				l = mid + 1;
			} else {
				r = mid - 1;
			}
		}
		L = l;
		l = i; r = n;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (query1(i, mid) - query2(i, mid) > k) {
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		R = r;
		ans += R - L + 1;//这里的双指针需要二分来提高效率
	}
	cout << ans << endl;
}