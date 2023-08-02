typedef long long ll;
const ll inf = 0x3f3f3f3f3f3f3f3f;
struct cmp {
	bool operator()(pair<ll, int>a, pair<ll, int>b) {
		return a.first > b.first;
	}
};
class Solution {

public:

	int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {
		std::map<pair<int, int>, int>mp;
		auto add = [&](int x, int y) {
			if (mp.count({x, y}))return;
			int idx = mp.size();
			mp[ {x, y}] = idx;
		};
		add(start[0], start[1]);
		add(target[0], target[1]);
		for (auto r : specialRoads) {
			add(r[0], r[1]); add(r[2], r[3]);
		}
		int n = mp.size();
		vector<int>X(n + 5), Y(n + 5);
		for (auto [x, y] : mp) {
			X[y] = x.first;
			Y[y] = x.second;
		}
		vector<vector<pair<ll, int>>>tr(n + 5);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i != j) {
					tr[i].push_back({abs(X[i] - X[j]) + abs(Y[i] - Y[j]), j});
				}
			}
		}
		for (auto r : specialRoads) {
			int sn = mp[ {r[0], r[1]}];
			int fn = mp[ {r[2], r[3]}];
			tr[sn].push_back({r[4], fn});
		}
		int s = mp[ {start[0], start[1]}];
		int t = mp[ {target[0], target[1]}];
		vector<ll>dis(n + 5, inf); vector<bool>vis(n + 5, false);
		dis[s] = 0;
		priority_queue<pair<ll, int>, vector<pair<ll, int>>, cmp>q;
		q.push({0, s});
		while (q.size()) {
			auto [d, u] = q.top(); q.pop();
			vis[u] = 1;
			for (auto [d, v] : tr[u]) {
				if (dis[u] + d < dis[v]) {
					dis[v] = min(dis[v], dis[u] + d);
					if (not vis[v]) {
						q.push({dis[v], v});
					}
				}
			}
		}
		return dis[t];
	}

};