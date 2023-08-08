#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 5e3 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
ll N, K;
void solve() {
	std::cin >> N >> K;
	vector<ll>A(N + 5, 0);
	std::set<ll>st;
	for (ll i = 1; i <= N; i++) {
		std::cin >> A[i];
	}
	std::sort(A.begin() + 1, A.begin() + 1 + N);
	st.insert(A[1]); ll cur = A[1];
	while (--K) {
		ll nxt = inf;
		for (ll i = 1; i <= N; i++) {
			if (A[i] > cur) {
				nxt = min(nxt, A[i]); continue;
			}
			auto it = st.upper_bound(cur - A[i]);
			if (it == st.end())continue;
			else nxt = min(nxt, (*it) + A[i]);
		}
		st.insert(nxt);
		cur = nxt;
	}
	cout << cur << endl;
}
signed main() {
	solve();
}