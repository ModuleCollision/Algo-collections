#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 5e3 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
void solve() {
	ll n, k;
	std::cin >> n >> k;
	vector<ll>q(n + 5, 0);
	ll h = 1, t = 0;//初始化为空序列
	vector<ll>A(n + 5, 0);
	for (ll i = 1; i <= n; i++)cin >> A[i];

	for (ll i = 1; i < k; i++) {
		while (h <= t and A[q[t]] >= A[i])t--;
		q[++t] = i;
	}
	for (ll i = k; i <= n; i++) {
		while (h <= t and A[q[t]] >= A[i])t--;
		q[++t] = i;//动态维护 i - k + 1 到 k的最小值
		while (q[h] <= i - k)h++;
		cout << A[q[h]] << " ";
	}
	cout << endl;
	h = t = 0;
	for (ll i = 1; i < k; i++) {
		while (h <= t and A[q[t]] <= A[i])t--;
		q[++t] = i;
	}
	for (ll i = k; i <= n; i++) {
		while (h <= t and A[q[t]] <= A[i])t--;//动态维护一定范围内的最大值
		q[++t] = i;
		while (q[h] <= i - k)h++;
		cout << A[q[h]] << " ";
	}
	cout << endl;
}
signed main() {
	solve();
}