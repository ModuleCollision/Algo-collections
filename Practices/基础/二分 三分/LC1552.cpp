class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        std::sort(position.begin(), position.end());
        auto check = [&](int mid) {
            int cnt = 1;
            int pre = position[0];
            for (int i = 1; i < n; i++) {
                if (position[i] - pre >= mid) {
                    pre = position[i];
                    cnt++;
                }
            }
            return cnt >= m;
        };
        int l = 1, ans = 0, r = position.back() - position.front();
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (check(mid)) {
                l = mid + 1;
                ans = mid;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};