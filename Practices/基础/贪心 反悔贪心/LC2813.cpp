class Solution {
public:
	typedef long long ll;
	long long findMaximumElegance(vector<vector<int>>& items, int k) {
		int n = items.size();
		sort(items.begin(), items.end(), [&](vector<int>x, vector<int>y)->bool{
			return x[0] > y[0];
		});
		vector<int>ws; ll tot = 0; std::set<int>st;
		ll ans = 0;
		auto cal = [&]() {
			return (ll)(st.size() * st.size() + tot);
		};
		for (int i = 0; i < n; i++) {
			int p = items[i][0], c = items[i][1];
			if (i < k) {
				tot += p; if (st.count(c))ws.push_back(p); st.insert(c);
			} else {
				if (ws.size() and not st.count(c)) {
					tot -= ws.back(); tot += p; ws.pop_back();
					st.insert(c);
				}
			}
			ans = max(ans, cal());
		}
		return ans;
	}
};