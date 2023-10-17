class Solution {
    static long mod = 1000000007;

    private int f(int s) {
        return s;
    }
    public int maxSum(List<Integer> nums, int k) {
        int[] cnt = new int[30];
        for (var x : nums) {
            for (int i = 0; i < 30; i++) {
                cnt[i] += ((x >> i) & 1);
            }
        }
        long ans = 0;
        while (k-- > 0) {
            long x = 0;
            for (int i = 0; i < 30; i++) {
                if (cnt[i] > 0) {
                    cnt[i]--;
                    x |= (1 << i);
                }
            }
            ans = (ans % mod + (long)x % mod * x % mod) % mod;
        }
        return f((int) ans);
    }
};