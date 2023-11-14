class Solution {
public:
    vector<pair<int, int>>dir = {{1, 0}, {0, 1}};
    bool hasValidPath(vector<vector<char>> &grid) {
        int n = grid.size(), m = grid[0].size();
        if ((m + n) % 2 == 0 or grid[0][0] == ')' or grid[n - 1][m - 1] == '(')return false;
        auto check = [&](int x, int y) {
            return x >= 0 and x <= n - 1 and y >= 0 and y <= m - 1;
        };
        bool vis[n][m][(m + n + 1) / 2]; memset(vis, 0, sizeof(vis));
        function<bool(int, int, int)> dfs = [&](int x, int y, int v) -> bool {
            if (v > m - x + n - y - 1) return false;
            if (x == n - 1 and y == m - 1) return v == 1;
            if (vis[x][y][v]) return false;
            vis[x][y][v] = true;
            v += grid[x][y] == '(' ? 1 : -1;
            if (v < 0 )return false;
            for (auto [dx, dy] : dir) {
                int xx = x + dx, yy = y + dy;
                if (check(xx, yy)) {
                    bool f = dfs(xx, yy, v);
                    if (f)return true;
                }
            }
            return false;
        };
        return dfs(0, 0, 0);
    }
};