class Solution {
public:
    typedef long long ll;
	long long repairCars(vector<int>& ranks, int cars) {
		std::sort(ranks.begin(), ranks.end(), [&](ll a, ll b)->bool{
			return a < b;
		});
		auto check = [&](ll mid) {
            ll tmp = cars;
			for (auto r : ranks) {
				ll n = 0;
				while (r * n * n <= mid)n++;
				if (r * n * n > mid)n--;
				tmp -= n;
			}
			if (tmp > 0)return false;
			return true;
		};
		ll l = 0, r = 0x3f3f3f3f;
		while (l < r) {
			ll mid = (l + r) >> 1;
			if (check(mid))r = mid;
			else l = mid + 1;
		}
		return r;
	}
};