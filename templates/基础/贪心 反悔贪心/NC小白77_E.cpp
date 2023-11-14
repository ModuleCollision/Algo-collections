#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
typedef unsigned long long ull;
const ll maxn = 1e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
const ll p = 13331;
struct cmp {
	bool operator()(const ll&a, const ll&b)const {
		return a < b;
	}
};
void solve() {
	ll n, k; std::cin >> n >> k;
	ll ps = 0;
	vector<ll>A(n + 1);
	for (ll i = 1; i <= n; i++) {
		cin >> A[i]; if (A[i] >= 0)ps++;
	}
	priority_queue<ll, vector<ll>, cmp>q;
	ll ww = 0, sw = 0; ll ms = 0;
	for (ll i = 1; i <= n; i++) {
		if (A[i] >= 0)ww += A[i];
		else {
			ms++;
			ll cur = -A[i];/*贪心确保每一步操作都在提升负数*/
			/*首先确保有操作次数*/              /*两种情况, 还有多余的正数, 留一个剩余负数*/
			if (sw + cur <= k and (sw + cur <= ww or q.size() + 1 < ms)) {
				q.push(cur); sw += cur;
			} else {
				if (q.size() and q.top() > cur) {
					sw -= q.top(); q.pop(); q.push(cur); sw += cur;
				}
			}
		}
	}
	cout << q.size() + ps << endl;
}
signed main() {
	solve();
}