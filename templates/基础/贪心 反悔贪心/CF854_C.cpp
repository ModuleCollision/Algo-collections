#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
typedef unsigned long long ull;
const ll maxn = 1e6 + 10;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
char A[maxn];
void solve() {
	string s; cin >> s; ll n = s.size();
	s = " " + s; ll l = 1, r = n;
	for (ll i = 1; i <= n; i += 2) {
		if (i == n)A[l] = s[i];
		else if (i == n - 1 or s[i] == s[i + 1]) {
			A[l++] = s[i + 1], A[r--] = s[i];
		} else if (s[i + 1] == s[n]) {
			swap(s[i], s[i + 2]); i -= 2;
		} else {
			A[r--] = s[i];
			for (ll j = i + 1; j <= n; j++)A[l++] = s[j];
			i = n;
		}
	}
	for (ll i = 1; i <= n; i++) {
		putchar(A[i]);
	}
	cout << endl;
}
signed main() {
	ll T; std::cin >> T;
	while (T--)
		solve();
}