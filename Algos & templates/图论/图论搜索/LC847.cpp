/*小技巧*/
/*我们在处理需要时刻记录全图状态的图论问题时,
不妨利用状态压缩,并进行bfs/dfs过程中的转移*/
struct sq {
	int u; int msk; int dis;
};
class Solution {
public:
	int shortestPathLength(vector<vector<int>>& graph) {
		int n = graph.size();
		queue<sq>q;
		bool vis[100][100005];
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < n; i++) {
			q.push({i, (1 << i), 0});
			vis[i][1 << i] = true;//访问过只有点i被访问的图的状态
		}
		//vis记录两个状态,在图中某个状态访问至某点的状态
		int ans = 0;
		while (not q.empty()) {
			auto [u, msk, dis] = q.front();
			q.pop();
			if (msk == (1 << n) - 1) {//当全图中的点都被访问过时
				ans = dis; break;
			}
			for (auto v : graph[u]) {
				int cur = msk | (1 << v);
				if (not vis[v][cur]) {
					q.push({v, cur, dis + 1});
					vis[v][cur] = 1;
				}
			}
		}
		return ans;
	}
};