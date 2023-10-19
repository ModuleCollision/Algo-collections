/*二分经典问题,由于维护区间的信息具有单调性,故用双指针+二分维护*/
#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e6 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
int st_max[maxn][30], st_min[maxn][30], lg[maxn];
int n, k, a[maxn];
void init() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> st_max[i][0];
		st_min[i][0] = st_max[i][0];
	}
	for (int i = 2; i <= 1e6; i++) {
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
void solve() {
	init();
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int l = i, r = n + 1; int ans1 = 0, ans2 = 0;
		while (l < r) {
			int mid = (l + r) >> 1;
			if (query1(i, mid) - query2(i, mid) >= k) {
				r = mid;
			} else {
				l = mid + 1;
			}
		}

		ans1 = r; l = i, r = n + 1;
		while (l < r) {
			int mid = (l + r) >> 1;
			if (query1(i, mid) - query2(i, mid) > k) {
				r = mid;
			} else {
				l = mid + 1;
			}
		} ans2 = r;
		ans += max(0, ans2 - ans1); //这里的双指针需要二分来提高效率
	}
	cout << ans << endl;
}
signed main() {
	solve();
}


/*等价于如下写法: */
#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e6 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
int st_max[maxn][30], st_min[maxn][30], lg[maxn];
int n, k, a[maxn];
void init() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> st_max[i][0];
		st_min[i][0] = st_max[i][0];
	}
	for (int i = 2; i <= 1e6; i++) {
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
void solve() {
	init();
	int ans = 0;
	vector<int>w(n + 5, 0);
	iota(w.begin() + 1, w.begin() + n + 1, 1); int l = 0;
	auto cmp = [&](int x, int y) {
		return query1(l, x) - query2(l, x) < y;
	};
	auto cmp2 = [&](int x, int y) {
		return query1(l, x) - query2(l, x) <= y;
	};
	for (int i = 1; i <= n; i++) {
		l = i;
		int idx1 = lower_bound(w.begin() + l, w.begin() + 1 + n, k, cmp) - w.begin();
		int idx2 = lower_bound(w.begin() + l, w.begin() + 1 + n, k, cmp2) - w.begin();
		//cout << "#" << idx2 << " " << idx1 << endl;
		ans += max(0, idx2 - idx1); //这里的双指针需要二分来提高效率
	}
	cout << ans << endl;
}
signed main() {
	solve();
}