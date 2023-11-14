class Solution {
public:
	typedef long long ll;
	int countDigitOne(int n) {
		string s = to_string(n);
		ll m = s.size();
		ll dp[m + 5][10]; memset(dp, -1, sizeof(dp));
		function<ll(int, int, bool, bool)>dfs = [&](int idx, int cnt, bool islimit, bool isnum) {
			if (idx == m)return isnum ? (ll)cnt : 0;
			if (not islimit and (int)dp[idx][cnt] != -1 and isnum)return dp[idx][cnt];
			ll res = 0;
			if (not isnum)res += dfs(idx + 1, cnt, false, false);
			ll low = isnum ? 0 : 1;
			ll up = islimit ? s[idx] - '0' : 9;
			for (ll d = low; d <= up; d++) {
				res += dfs(idx + 1, cnt + (d == 1), islimit and d == up, true);
			}
			if (not islimit and isnum)dp[idx][cnt] = res;
			return res;
		};
		return (int)dfs(0, 0, true, false);
	}
};


class Solution {
public:
	typedef long long ll;
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