#define fi first
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 5e6 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
class Solution {
public:
	vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
		vector<pair<array<int, 3>, char>>st1;
		vector<pair<array<int, 2>, char>>st;
		int n = positions.size();
		for (int i = 0; i < n; i++) {
			st1.push_back({{positions[i], healths[i], i}, directions[i]});
		}
		std::sort(st1.begin(), st1.end(), [&](auto s, auto t)->bool{
			return s.fi[0] < t.fi[0];
		});
		for (auto c : st1) {
			st.push_back({{c.fi[1], c.fi[2]}, c.second});
		}
		vector<pair<array<int, 2>, char>>w;
		for (int i = 0; i < n; i++) {
			if (w.size()) {
				if (w.back().se == 'R' and st[i].se == 'L') {
					while (w.size()) {
						if (not (w.back().se == 'R' and st[i].se == 'L')) {
							break;
						} else {
							if (w.back().fi[0] < st[i].fi[0]) {
								st[i].fi[0] -= 1;
								w.pop_back();
							} else if (w.back().fi[0] == st[i].fi[0]) {
								w.back().fi[0] -= 1; st[i].fi[0] = 0; w.pop_back();
								break;
							} else {
								w.back().fi[0] -= 1; st[i].fi[0] = 0; break;
							}
						}
					}
					if (st[i].fi[0])w.push_back({{st[i].fi[0], st[i].fi[1]}, st[i].se});
				} else {
					w.push_back({{st[i].fi[0], st[i].fi[1]}, st[i].se});
				}
			} else {
				w.push_back({{st[i].fi[0], st[i].fi[1]}, st[i].se});
			}
		}
		vector<pair<int, int>>ans;
		for (auto c : w) {
			if (c.fi[0])ans.push_back({c.fi[0], c.fi[1]});
		}
		sort(ans.begin(), ans.end(), [&](auto s, auto t) {
			return s.se < t.se;
		});
		vector<int>f;
		for (auto c : ans) {
			f.push_back(c.fi);
		}
		return f;
	}
};