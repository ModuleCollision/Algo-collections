class Solution {
	int beautifulPartitions(string s, int k, int minLength) {
		vector<int>check = {0, 0, 1, 1, 0, 1, 0, 1, 0, 0};
		s = "0" + s; int n = s.length() - 1;
		int dp[n + 5][k + 5];
		memset(dp, 0, sizeof(dp)); dp[0][0] = 1;
		auto is_split = [&](int i)->bool {
			return not check[s[i] - '0'] and check[s[i + 1] - '0'];
		};
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= k; j++) {
				if (i - minLength >= 0 and not check[s[i] - '0']) {
					for (int t = i - minLength; t <= i - 1; t++) {
						if (is_split(t)) {
							dp[i][j] += dp[t][j - 1];
						}
					}
				}
			}
		}
		return dp[n][k];
	}

};