class Solution {
    public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        auto check = [&](int mid) {
            int ret = 0;
            for (int i = 0; i < n; i++) {
                ret += (nums[i] + mid - 1) / mid;
            }
            return ret <= threshold;
        };
        int l = 1, r = 0x3f3f3f3f;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (check(mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return r;
    }
};