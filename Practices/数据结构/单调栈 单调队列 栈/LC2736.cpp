class Solution {
public:
	vector<int> maximumSumQueries(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
		int qq = queries.size();
		vector<int>ans(qq, -1);
		int head = 1, tail = 0; int n = nums1.size();
		vector<int>q(4 * n + 5);
		vector<pair<int, int>>sq;
		for (int i = 0; i < n; i++) {
			sq.push_back({nums1[i], nums2[i]});
		}
		int p = n - 1;
		for (int i = 0; i < qq; i++) {
			queries[i].push_back(i);
		}
		std::sort(queries.begin(), queries.end(), [&](auto x, auto y)->bool{
			return x[0] > y[0];
		});
		std::sort(sq.begin(), sq.end());
		for (int i = 0; i < qq; i++) {
			int idx = queries[i][2];
			while (p >= 0 and sq[p].first >= queries[i][0]) {
				auto [ax, ay] = sq[p];
				while (head <= tail and sq[q[tail]].first + sq[q[tail]].second <= ax + ay)tail--;
				if (head > tail or sq[q[tail]].second < ay)q[++tail] = p;
				p--;
			}
			int l = head, r = tail; int ps = 0;
			/*三种单调队列二分写法*/
			while (l <= r) {
				int mid = (l + r) >> 1;
				if (sq[q[mid]].second >= queries[i][1]) {
					r = mid - 1; ps = mid;
				} else l = mid + 1;
			}
			if (ps)ans[idx] = sq[q[ps]].first + sq[q[ps]].second;


			/*
			2. int l = head, r = tail + 1;
			while (l < r) {
				int mid = (l + r) >> 1;
				if (sq[q[mid]].second >= queries[i][1]) {
					r = mid;
				} else l = mid + 1;
			}
			if (r <= tail)ans[idx] = sq[q[r]].first + sq[q[r]].second;*/


			/*
			3. int f = lower_bound(q.begin() + head, q.begin() + tail + 1, queries[i][1], [&](int s, int y)->bool{
				return sq[s].second < y;  不满足某条件的第一个下标
			}) - q.begin();
			if (f != tail + 1)ans[idx] = sq[q[f]].first + sq[q[f]].second;*/
		}
		return ans;
	}
};
/*单调队列 or 单调栈可以维护下标, 也可以维护值*/
/*两者唯一的区别在于栈是单向的, 队列是双向的*/

/*单调栈二分写法 , 同时满足nums2[j]递增与nums1[j] + nums2[j] 递减的状态*/
class Solution {
public:
	vector<int> maximumSumQueries(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
		int qq = queries.size();
		vector<int>ans(qq, -1);
		int head = 1, tail = 0; int n = nums1.size();
		vector<pair<int, int>>q;
		vector<pair<int, int>>sq;
		for (int i = 0; i < n; i++) {
			sq.push_back({nums1[i], nums2[i]});
		}
		int p = n - 1;
		for (int i = 0; i < qq; i++) {
			queries[i].push_back(i);
		}
		std::sort(queries.begin(), queries.end(), [&](auto x, auto y)->bool{
			return x[0] > y[0];
		});
		std::sort(sq.begin(), sq.end());
		for (int i = 0; i < qq; i++) {
			int idx = queries[i][2];
			while (p >= 0 and sq[p].first >= queries[i][0]) {
				auto [ax, ay] = sq[p];
				while (q.size() and q.back().second <= ax + ay)q.pop_back();
				//维护nums1 + nums2的单调递减性
				if (not q.size() or q.back().first < ay)q.push_back({ay, ax + ay});
				p--;
			}
			if (not q.size())continue;
			int id = lower_bound(q.begin(), q.end(), pair<int, int>(queries[i][1], 0), [&](pair<int, int>x, pair<int, int>y)->bool{
				return x.first < y.first;
			}) - q.begin();
			//二分出num2 >= y的最小下标
			if (id < q.size())ans[idx] = q[id].second;
		}
		return ans;
	}
};