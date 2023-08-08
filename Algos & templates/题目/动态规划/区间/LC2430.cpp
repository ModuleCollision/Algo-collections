class Solution {
public:
	typedef long long ll;
	int deleteString(string s) {
		ll n = s.size();
		if (*max_element(s.begin(), s.end()) == *min_element(s.begin(), s.end())) {
			return n;
		}
		vector<ll>dp(n + 5, 0);
		dp[0] = 0;
		const ll mod = 1e9 + 7, b = 23;
		auto ksm = [&](ll a, ll b) {
			int ret = 1;
			while (b) {
				if (b & 1)ret = ret * a % mod;
				a = a * a % mod;
				b >>= 1;
			}
			return ret;
		};
		vector<ll>Hash(n + 5, 0);
		for (ll i = 1; i <= n; i++) {
			Hash[i] = (Hash[i - 1] % mod * b % mod + s[i - 1] - 'a') % mod;
		}
		auto get = [&](ll l, ll r)  {
			return ((Hash[r] - Hash[l - 1] % mod * ksm(b, r - l + 1) % mod) % mod + mod) % mod;
		};
		for (int i = n; i >= 1; i--) {
			for (int len = 2; i + len - 1 <= n; len += 2) {
				int j = i + len - 1;
				if (get(i, i + len / 2 - 1) == get(i + len / 2, j)) {
					dp[i] = max(dp[i], dp[i + len / 2]);
				}

			}
			dp[i]++;
		}
		return dp[1];
	}
};