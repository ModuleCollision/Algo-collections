class Solution {
public:
	typedef long long ll;
	int minimumTime(vector<int>& nums1, vector<int>& nums2, int x) {
		int n = nums1.size();
		vector dp(n + 5, vector<ll>(n + 5, 0));
		vector<pair<int, int>>w;
		for (int i = 0; i < n; i++)w.push_back({nums1[i], nums2[i]});
		std::sort(w.begin(), w.end(), [&](pair<int, int>f, pair<int, int>t)->bool{
			return f.second < t.second;
		});
		for (int i = 0; i < n; i++) {
			nums1[i] = w[i].first;
			nums2[i] = w[i].second;
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= n; j++) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j]);
				if (j >= 1)dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + nums1[i - 1] + nums2[i - 1] * j);
			}
		}
		int sum1 = accumulate(nums1.begin(), nums1.end(), 0);
		int sum2 = accumulate(nums2.begin(), nums2.end(), 0);
		for (int j = 0; j <= n; j++) {
			if (sum1 + sum2 * j - dp[n][j] <= x)return j;
		}
		return -1;
	}
};