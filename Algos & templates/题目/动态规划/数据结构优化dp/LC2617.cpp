/*单调栈 + 二分优化dp*/
/*滑窗范围不确定, 故用单调栈维护dp值的单调性, 二分出合法的下标来更新答案*/
class Solution {
public:
	int minimumVisitedCells(vector<vector<int>>& grid) {
		int n = grid.size(); int m = grid[0].size();
		vector<vector<pair<int, int>>>col(m + 5);//列单调栈
		vector g(n + 5, vector<int>(m + 5, 0));
		for (int i = 1; i <= n; i++)for (int j = 1; j <= m; j++)g[i][j] = grid[i - 1][j - 1];
		vector dp(n + 5, vector<int>(m + 5, 0x3f3f3f3f));
		dp[n][m] = 1;
		for (int i = n; i >= 1; i--) {
			std::vector<pair<int, int>>q;//本行的单调栈
			for (int j = m; j >= 1; j--) {
				auto &st = col[j];
				if (i == n and j == m)continue;
				int v = g[i][j];
				while (q.size() and q.back().second >= dp[i][j + 1])q.pop_back();
				q.push_back({j + 1, dp[i][j + 1]});
				while (st.size() and st.back().second >= dp[i + 1][j])st.pop_back();
				st.push_back({i + 1, dp[i + 1][j]});
				/*下标单调递减, 值单调递增, 选择第一个, 即满足条件的值最小的*/
				auto idx = lower_bound(q.begin(), q.end(), j + v, [&](pair<int, int>s, int t)->bool{
					return s.first > t;
				}) - q.begin();
				if (idx < q.size())
					dp[i][j] = min(dp[i][j], q[idx].second + 1);
				idx = lower_bound(st.begin(), st.end(), i + v, [&](pair<int, int>s, int t)->bool{
					return s.first > t;
				}) - st.begin();
				if (idx < st.size())dp[i][j] = min(dp[i][j], st[idx].second + 1);
			}
		}
		/*
		for (int i = n; i >= 1; i--) {
			std::vector<pair<int, int>>q;//本行的单调栈
			for (int j = m; j >= 1; j--) {
				auto &st = col[j];
				int v = g[i][j];
				auto idx = lower_bound(q.begin(), q.end(), j + v, [&](pair<int, int>s, int t)->bool{
					return s.first > t;
				}) - q.begin();
				if (idx < q.size())
					dp[i][j] = min(dp[i][j], q[idx].second + 1);
				idx = lower_bound(st.begin(), st.end(), i + v, [&](pair<int, int>s, int t)->bool{
					return s.first > t;
				}) - st.begin();
				if (idx < st.size())dp[i][j] = min(dp[i][j], st[idx].second + 1);
				while (q.size() and q.back().second >= dp[i][j])q.pop_back();
				q.push_back({j, dp[i][j]});
				while (st.size() and st.back().second >= dp[i][j])st.pop_back();
				st.push_back({i, dp[i][j]});
			}
		}
		*/
		//也可以先维护值, 再加入栈, 避免越界
		if (dp[1][1] == 0x3f3f3f3f)return -1;
		return dp[1][1];
	}
};



/*线段树优化dp*/
const int inf = 0x3f3f3f3f;
const int maxn = 1e6 + 5;

class Solution {
public:
	/*void pushup(int p, sq tr[]） {

	}*/
	int n; int  m;
	struct sq {
		int l; int r; int mn; int laz;
	} tr1[maxn], tr2[maxn];

	void build(int p, int l, int r, sq tr[]) {
		tr[p].l = l; tr[p].r = r;
		tr[p].mn = tr[p].laz = inf;
		if (l == r) {
			return;
		}
		int mid = (l + r) >> 1;
		build(p << 1, l, mid, tr);
		build(p << 1 | 1, mid + 1, r, tr);
		tr[p].mn = std::min(tr[p << 1].mn, tr[p << 1 | 1].mn);
	}
	void pushdown(int p, sq tr[]) {
		if (tr[p].laz != inf) {
			int lz = tr[p].laz;
			tr[p].laz = inf;
			tr[p << 1].mn = min(tr[p << 1].mn, lz);
			tr[p << 1 | 1].mn = min(tr[p << 1 | 1].mn, lz);
			tr[p << 1].laz = min(tr[p << 1].laz, lz);
			tr[p << 1 | 1].laz = min(tr[p << 1 | 1].laz, lz);
		}
	}
	int query(int p, int l, int r, sq tr[]) {
		if (l > r)return inf;
		if (tr[p].l >= l and tr[p].r <= r)return tr[p].mn;
		pushdown(p, tr);
		int mid = (tr[p].l + tr[p].r) >> 1;
		int ret = inf;
		if (r > mid)ret = min(ret, query(p << 1 | 1, l, r, tr));
		if (l <= mid)ret = min(ret, query(p << 1, l, r, tr));
		return ret;
	}

	void modify(int p, int l, int r, int v, sq tr[]) {
		if (l > r)return;
		if (tr[p].l >= l and tr[p].r <= r) {
			tr[p].mn = min(tr[p].mn, v);
			tr[p].laz = min(tr[p].laz, v);
			return;
		}
		pushdown(p, tr);
		int mid = (tr[p].l + tr[p].r) >> 1;
		if (r > mid)modify(p << 1 | 1, l, r, v, tr);
		if (l <= mid)modify(p << 1, l, r, v, tr);
		tr[p].mn = std::min(tr[p << 1].mn, tr[p << 1 | 1].mn);
	}
	int minimumVisitedCells(vector<vector<int>>& grid) {
		n = grid.size(); m = grid[0].size();
		build(1, 1, m * n, tr1);
		build(1, 1, m * n, tr2);
		modify(1, 1, 1, 1, tr1);
		modify(1, 1, 1, 1, tr2);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (not grid[i][j])continue;
				int v = grid[i][j];
				int s1 = i + 1, s2 = min(i + v, n - 1);
				int w = min(query(1, i + j * n + 1, i + j * n + 1, tr1), query(1, j + i * m + 1, j + i * m + 1, tr2));
				modify(1, s1 + j * n + 1, s2 + j * n + 1, w + 1, tr1);
				s1 = j + 1, s2 = min(j + v, m - 1);
				modify(1, i * m + s1 + 1, s2 + i * m + 1, w + 1, tr2);
			}
		}
		int ans = min(query(1, n * m, n * m, tr1), query(1, n * m, n * m, tr2));
		if (ans == inf)return -1;
		return ans;
	}
};



/*单调队列优化dp*/


/*很显然, 本题格子之间的可达性不单调, 故单调队列优化是错解*/
class Solution {
public:
	int minimumVisitedCells(vector<vector<int>>& grid) {
		int n = grid.size(), m = grid[0].size();
		vector g(n + 1, vector<int>(m + 1, 0));
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++)g[i][j] = grid[i - 1][j - 1];
		}
		vector qq(m + 1, vector<int>(4 * n + 1, 0));
		vector<int>h(m + 1, 1), t(m + 1, 0);
		vector<int>q(4 * m + 1); int head, tail;
		vector dp(n + 1, vector<int>(m + 1, 0x3f3f3f3f));
		dp[1][1] = 1;
		for (int i = 1; i <= n; i++) {
			head = 1, tail = 0;
			for (int j = 1; j <= m; j++) {
				if (i == 1 and j == 1)continue;
				while (head <= tail and dp[i][q[tail]] > dp[i][j - 1])tail--;
				q[++tail] = j - 1;
				while (g[i][q[head]] + q[head] < j and head <= tail)head++;
				if (head <= tail)
					dp[i][j] = min(dp[i][j], dp[i][q[head]] + 1);
				while (h[j] <= t[j] and dp[qq[j][t[j]]][j] > dp[i - 1][j])t[j]--;
				qq[j][++t[j]] = i - 1;
				while (g[qq[j][h[j]]][j] + qq[j][h[j]] < i and h[j] <= t[j])h[j]++;
				if (h[j] <= t[j])
					dp[i][j] = min(dp[i][j], dp[qq[j][h[j]]][j] + 1);
			}
		}
		if (dp[n][m] == 0x3f3f3f3f)return -1;
		return dp[n][m];
	}
};