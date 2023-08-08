class Solution {
public:
    vector<int> dx = {0, 0, -1, 1};
    vector<int> dy = {1, -1, 0, 0};
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int row = grid.size(), col = grid[0].size(), n = queries.size();
        vector<int> res;
        set<vector<int>, less<>> q;
        vector<int> tmp = queries;
        sort(tmp.begin(), tmp.end());
        unordered_map<int, int> ans;

        int cur = 0;
        vector<vector<bool>> vis(row, vector<bool>(col, false));
        q.insert({grid[0][0], 0, 0});
        vis[0][0] = true;

        for (int i = 0; i < n; i ++ ) {
            int t = tmp[i];
            while (q.size() && t > (*q.begin())[0]) {
                auto it = *q.begin();
                q.erase(q.begin());
                cur ++;
                int val = it[0], x = it[1], y = it[2];
                for (int j = 0; j < 4; j ++ ) {
                    int xx = x + dx[j];
                    int yy = y + dy[j];
                    if (xx >= 0 && yy >= 0 && xx < row && yy < col && !vis[xx][yy]) {
                        q.insert({grid[xx][yy], xx, yy});
                        vis[xx][yy] = true;
                    }
                }
            }
            ans[t] = cur;
        }
        for (int i = 0; i < n; i ++ ) {
            res.push_back(ans[queries[i]]);
        }

        return res;
    }
};