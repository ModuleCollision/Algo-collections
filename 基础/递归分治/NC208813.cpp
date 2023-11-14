/*归并排序维护逆序数*/
#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 3e2 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
int cnt[maxn];
int res = 0;
pair<int, int>a[maxn], b[maxn];
void qss(int l, int r) {
	if (l >= r) {
		return;
	}
	int mid = (l + r) >> 1;
	qss(l, mid);
	qss(mid + 1, r);
	int i = l, j = mid + 1, tp = l;
	while (i <= mid and j <= r) {
		if (a[i].second >= a[j].second) {
			b[tp++] = a[j++];

		} else {
			b[tp++] = a[i++];
			cnt[a[i - 1].first] += (j - mid - 1);
		}
	}
	for (int t = i; t <= mid; t++) {
		b[tp++] = a[t];
		cnt[a[t].first] += (j - mid - 1);
	}
	for (int t = j; t <= r; t++) {
		b[tp++] = a[t];
	}
	for (int t = l; t <= r; t++) {
		a[t] = b[t];
	}
}
int main() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].second;
		a[i].first = i;
	}
	qss(1, n);
	for (int i = 1; i <= n; i++) {
		cout << cnt[i] << " ";
	}
}