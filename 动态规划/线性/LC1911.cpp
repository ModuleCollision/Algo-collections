class Solution {
public:
	typedef long  long ll;
	const ll inf = 0x3f3f3f3f3f3f3f3f;
	long long maxAlternatingSum(vector<int>& nums) {
		ll n = nums.size();
		vector dp(n + 5, array<ll, 2> { -inf, -inf});
		dp[0][0] = 0;//在负区间
		//0在 负区间, 1在正区间
		for (ll i = 1; i <= n; i++) {
			dp[i][0] = max(dp[i][0], dp[i - 1][0]);
			dp[i][0] = max(dp[i][0], dp[i - 1][1] - nums[i - 1]);
			dp[i][1] = max(dp[i][1], dp[i - 1][0] + nums[i - 1]);
			dp[i][1] = max(dp[i][1], dp[i - 1][1]);
		}
		return max(dp[n][0], dp[n][1]);
	}
};