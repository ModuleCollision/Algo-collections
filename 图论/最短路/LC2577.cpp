
class Solution {
public:
    struct sq {
        int u; int v; int dis;
        bool operator<(const sq &b)const {
            return dis > b.dis;
        }
    };
    int minimumTime(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        priority_queue<sq>q;
        vector<vector<int>>dis(n + 5, vector<int>(m + 5, 0x3f3f3f3f));
        vector<vector<bool>>vis(n + 5, vector<bool>(m + 5, 0));
        if (grid[1][0] > 1 and grid[0][1] > 1)return -1;
        dis[0][0] = 0;
        q.push({0, 0, 0});
        auto check = [&](int x, int y) {
            return x >= 0 and x < n and y >= 0 and y < m;
        };
        vector<pair<int, int>>dir = {{1, 0}, { -1, 0}, {0, 1}, {0, -1}};
        while (q.size()) {
            auto [x, y, d] = q.top();
            q.pop(); vis[x][y] = 1;
            for (auto [dx, dy] : dir) {
                int xx = x + dx, yy = y + dy;
                if (not check(xx, yy))continue;
                int tmp;
                if (dis[x][y] + 1 >= grid[xx][yy]) {
                    tmp = dis[x][y] + 1;
                } else {
                    tmp = (grid[xx][yy] - dis[x][y]) / 2 * 2 + 1 + dis[x][y];
                }
                if (tmp < dis[xx][yy]) {
                    dis[xx][yy] = tmp;
                    if (not vis[xx][yy]) {
                        q.push({xx, yy, tmp});
                    }
                }
            }
        }
        return dis[n - 1][m - 1];
    }
};