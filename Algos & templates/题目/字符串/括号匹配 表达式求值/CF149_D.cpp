#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 5e3 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
void solve() {
	ll n; std::cin >> n;
	string s; std::cin >> s; s = " " + s;
	bool f1 = 1, f2 = 1;
	ll cnt1 = 0, cnt2 = 0;
	for (ll i = 1; i <= n; i++) {
		if (s[i] == '(')cnt1++;
		else {
			if (cnt1) {
				cnt1--;
			} else {
				f1 = 0; break;
			}
		}
	}
	for (ll i = 1; i <= n; i++) {
		if (s[i] == ')') {
			cnt2++;
		}
		else {
			if (cnt2) {
				cnt2--;
			} else {
				f2 = 0; break;
			}
		}
	}
	if ((cnt1 == 0 and f1) or (cnt2 == 0 and f2)) {
		cout << 1 << endl;
		for (ll i = 1; i <= n; i++) {
			cout << 1 << " ";
		}
		cout << endl; return;
	}
	vector<ll>co(n + 5, 0), stk1(n + 5, 0), stk2(n + 5, 0);
	ll top1 = 0, top2 = 0;
	for (ll i = 1; i <= n; i++) {
		if (s[i] == '(') {
			if (top2) {
				co[i] = co[stk2[top2]] = 2; top2--;
			} else
				stk1[++top1] = i;
		} else {
			if (top1) {
				co[i] = co[stk1[top1]] = 1; top1--;
			} else {
				stk2[++top2] = i;
			}
		}
	}
	/*for (ll i = 1; i <= n; i++) {
		if (co[i])continue;
		if (s[i] == ')') {
			stk2[++top2] = i;
		} else {
			if (top2) {
				co[i] = co[stk2[top2]] = 2; top2--;
			}
		}
	}*/
	for (ll i = 1; i <= n; i++) {
		if (not co[i]) {
			puts("-1"); return;
		}
	}
	cout << 2 << endl;
	for (ll i = 1; i <= n; i++) {
		cout << co[i] << " ";
	}
	cout << endl;
}
signed main() {
	ll T; std::cin >> T;
	while (T--)solve();
}