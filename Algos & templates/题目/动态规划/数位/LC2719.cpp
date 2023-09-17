typedef long long ll;
const ll mod = 1e9 + 7;
class Solution {
public:

	int count(string num1, string num2, int min_sum, int max_sum) {
		auto cal = [&](string s) {
			int m = s.size(); ll dp[m + 5][10000];
			memset(dp, -1, sizeof(dp));
			function<ll(int, int, bool, bool)>dfs = [&](int idx, int sum, bool isnum, bool islimit) {
				if (idx == m) {
					return (ll)(isnum and sum >= min_sum and sum <= max_sum) ;
				}
				if (not islimit and isnum and dp[idx][sum] != -1)return dp[idx][sum];
				ll res = 0;
				if (not isnum)res = (res % mod + dfs(idx + 1, sum, false, false)) % mod;
				ll low = isnum ? 0 : 1;
				ll up = islimit ? s[idx] - '0' : 9;
				for (ll d = low; d <= up; d++) {
					if (sum + d <= max_sum)res = (res % mod + dfs(idx + 1, sum + d, true, islimit and d == up)) % mod;
				}
				if (not islimit and isnum)dp[idx][sum] = res;
				return res % mod;
			};
			return dfs(0, 0, false, true);
		};
		auto check = [&](string s) {
			ll ret = 0; for (ll i = 0; i < s.size(); i++)ret += s[i] - '0';
			return ret >= min_sum and ret <= max_sum;
		};
		return (cal(num2) - cal(num1) + mod + check(num1)) % mod;
	}
};