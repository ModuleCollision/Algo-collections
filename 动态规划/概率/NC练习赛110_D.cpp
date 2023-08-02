#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1500;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
ll dp[maxn], n, K;
char s[maxn];
void solve() {
	std::cin >> n >> K;
	auto inv = [&](ll x) {
		ll ret = 1, a = x, b = mod - 2;
		while (b) {
			if (b & 1) {
				ret = ret % mod * a % mod;
			}
			a = a * a % mod;
			b >>= 1;
		}
		return ret;
	};
	std::cin >> (s + 1);
	std::set<char>st;
	//st.insert('y'); st.insert('k'); st.insert('a'); st.insert('w'); st.insert('i');
	for (ll i = 1; i <= n; i++) {
		if (s[i] == 'y' or s[i] == 'k' or s[i] == 'a' or s[i] == 'w' or s[i] == 'i') {
			dp[0] = (dp[0] % mod + 1) % mod;
		}
	}
	ll d = inv(n % mod * 26 % mod);
	for (ll i = 1; i <= K; i++) {
		ll k = (dp[i - 1] % mod * 5 % mod + ((n - dp[i - 1]) % mod + mod) % mod * 21 % mod) % mod * d % mod;
		dp[i] = (dp[i] % mod + k % mod * dp[i - 1]) % mod;
		k = (dp[i - 1] % mod * 21 % mod) * d % mod;
		dp[i] = (dp[i] % mod + k % mod * ((dp[i - 1] - 1 + mod) % mod + mod) % mod) % mod;
		k = ((n - dp[i - 1]) % mod + mod) % mod * 5 % mod * d % mod;
		dp[i] = (dp[i] % mod + (dp[i - 1] % mod + 1) % mod * k % mod) % mod;
	}
	cout << (dp[K] % mod) << endl;
}
signed main() {
	solve();
}
