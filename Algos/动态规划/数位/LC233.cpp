class Solution {
public:
	typedef double db;
	typedef long long ll;
	typedef long double lb;
	const ll maxn = 1e6 + 5;
	const ll inf = 2147483648;
	const ll mod = 1e9 + 7;
	int countDigitOne(int n) {
		vector<ll>dp(10 + 5, 0), p(15, 0);
		p[0] = 1;
		for (ll i = 1; i <= 10; i++) {
			p[i] = p[i - 1] * 10;
		}
		string s = to_string(n);
		ll len = s.size();
		dp[1] = 1;
		for (ll i = 2; i <= 10; i++) {
			dp[i] = dp[i - 1] * 10 + p[i - 1];
		}
		reverse(s.begin(), s.end());
		s = " " + s; ll ans = 0;
		for (ll i = len; i >= 1; i--) {
			ll c = s[i] - '0';
			n -= p[i - 1] * c;
			ans += c * dp[i - 1];
			if (c > 1) {
				ans += p[i - 1];//最高位对1产生的贡献
			} else if (c == 1) {//最高位为1时产生的贡献
				ans += (n + 1);
			}
		}
		return ans;
	}
};