class Solution {
	const int mod = 1e9 + 7;
public:
	int countWays(vector<vector<int>> &ranges) {
		std::sort(ranges.begin(), ranges.end(), [&](vector<int> a, vector<int>b)->bool{
			return a[0] < b[0];
		});
		int ans = 2;
		int n = ranges.size(); int r = ranges[0][1];
		for (int i = 1; i < n; i++) {
			if (ranges[i][0] > r) {
				ans = ans % mod * 2 % mod;
				r = max(r, ranges[i][1]);
			}
			
		}
		return ans;
	}

};