typedef long long ll;
const ll maxn = 1e4 + 5;
bool vis[maxn]; ll p[maxn];
class Solution {
public:
	long long maximumSum(vector<int>& nums) {
		int n = nums.size(); p[1] = 1;
		for (ll i = 1; i <= 1e4; i++)p[i] = 1;
		for (ll i = 2; i <= 1e4; i++) {
			if (not vis[i]) {
				for (ll j = i + i; j <= 1e4; j += i)vis[j] = true;
				for (ll j = i; j <= 1e4; j += i) {
					ll tmp = j, cnt = 0;
					while (tmp % i == 0)tmp /= i, cnt++;
					if (cnt & 1)p[j] *= i;
				}
			}
		}
		std::unordered_map<ll, ll>mp;
		for (ll i = 0; i < n; i++)mp[p[i + 1]] += nums[i];
		ll ans = 0;
		for (auto [x, y] : mp)ans = max(ans, y);
		return ans;
	}
};