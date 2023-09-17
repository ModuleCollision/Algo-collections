class Solution {
public:
	typedef long long ll;
	int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
		ll ans = 0;
		for (auto c : composition) {
			auto check = [&](ll mid) {
				ll ret = 0;
				for (ll i = 0; i < n; i++) {
					ret += cost[i] * max(0ll, mid * c[i] - stock[i]);
					if (ret > budget)return false;
				}
				return true;
			};
			ll l = 0, r = 1e10;
			while (l < r) {
				ll mid = (l + r + 1) >> 1;
				if (check(mid))l = mid;
				else r = mid - 1;
			}
			ans = max(ans, l);
		}
		return (int)ans;
	}
};