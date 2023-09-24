typedef long long ll;
const ll mod = 1e9 + 7;
class Solution {
public:
	int numberOfWays(int startPos, int endPos, int k) {
		std::map<pair<ll, ll>, ll>dp;
		function<ll(ll, ll)>dfs = [&](ll idx, ll p) {
			if (idx == endPos) {
				if (p == k)return dp[ {idx, p}] = 1;
			}
			if (abs(idx - endPos) > k - p)return dp[ {idx, p }] = 0;
			if (p == k) {
				return dp[ {idx, p}] = 0;
			}
			if (dp.count({idx, p}))return dp[ {idx, p}] % mod;
			ll res = 0;
			res = (res % mod + dfs(idx + 1, p + 1)) % mod;
			res = (res % mod + dfs(idx - 1, p + 1)) % mod;
			dp[ {idx, p}] = res; return res % mod;
		};
		return dfs(startPos, 0) % mod;
	}
};