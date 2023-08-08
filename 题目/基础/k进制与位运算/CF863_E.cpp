#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
ll dp[30], f[30];
void solve() {
	ll n; std::cin >> n; vector<ll>k;
	while (n) {
		k.push_back(n % 9); n /= 9;
	}
	reverse(k.begin(), k.end());
	for (auto c : k) {
		if (c < 4) {
			cout << c;
		} else {
			cout << c + 1;
		}
	}
	cout << endl;
}
signed main() {

	ll T; std::cin >> T;
	while (T--)solve();
}