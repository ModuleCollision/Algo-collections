/*是一个混合背包求方案数的问题*/
/*注意维护每一维下标为0的状态*/
/*线性dp若未对下标为零的状态做初始化,记得一定要维护0状态!!!!!*/
class Solution {
public:
	typedef double db;
	typedef long long ll;
	typedef long double lb;
	const ll maxn = 2e3 + 5;
	const ll inf = 0x3f3f3f3f3f3f3f3f;
	const ll mod = 1e9 + 7;
	int waysToReachTarget(int target, vector<vector<int>>& types) {
		int dp[maxn][maxn]; memset(dp, 0, sizeof(dp));
		dp[0][0] = 1;
		int n = types.size();
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= target; j++) {
				//dp[i][j] = (dp[i][j] % mod + dp[i - 1][j]) % mod;
				for (int k = 0; k * types[i - 1][1] <= j and k <= types[i - 1][0]; k++) {
					dp[i][j] = (dp[i][j] % mod + dp[i - 1][j - k * types[i - 1][1]]) % mod;
				}
			}
		}
		return dp[n][target] % mod;
	}
};

/*多重背包一维*/
class Solution {
public:
	typedef long long ll;
	const ll mod = 1e9 + 7;
	int waysToReachTarget(int target, vector<vector<int>>& types) {
		int dp[10005]; memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		int n = types.size();
		for (auto p : types) {
			int count = p[0], marks = p[1];
			for (int j = target; j >= 0; j--) {
				for (int k = 1; k <= count and k * marks <= j; k++) {
					dp[j] = (dp[j] % mod + dp[j - k * marks]) % mod;
				}
			}
		}
		return dp[target] % mod;
	}
};