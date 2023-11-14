import java.util.*;

class Solution {
    public long maxArrayValue(int[] nums) {
        int len = nums.length;
        TreeSet<Long> st = new TreeSet<>();
        var now = (long) nums[len - 1];
        for (int i = len - 2; i >= 0; i--) {
            if (now >= nums[i]) now += nums[i];
            else {
                st.add(now);
                now = (long) nums[i];
            }
        }
        st.add(now);
        return st.last();
    }
};