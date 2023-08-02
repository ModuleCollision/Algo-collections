#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 5e3 + 5;
const ll inf = 0x3f3f3f3f;
const ll mod = 998244353;
bool solve() {
	int k;
	vector<int>nums = {4, 3, 2, 3, 5, 2, 1};
	int all = accumulate(nums.begin(), nums.end(), 0);
	if (all % k > 0) {
		return false;
	}
	int per = all / k;
	sort(nums.begin(), nums.end());
	if (nums.back() > per) {
		return false;
	}
	int n = nums.size();
	vector<bool> dp(1 << n, false);
	vector<int> curSum(1 << n, 0);
	dp[0] = true;
	for (int i = 0; i < 1 << n; i++) {
		if (!dp[i]) {
			continue;
		}
		for (int j = 0; j < n; j++) {
			if (curSum[i] + nums[j] > per) {
				break;
			}
			if (((i >> j) & 1) == 0) {
				int next = i | (1 << j);
				if (!dp[next]) {
					curSum[next] = (curSum[i] + nums[j]) % per;
					dp[next] = true;
				}
			}
		}
	}
	return dp[(1 << n) - 1];
}

signed main() {
	solve();
}