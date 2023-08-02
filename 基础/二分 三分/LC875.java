class Solution {
    public static boolean check(int[] piles, int h, int mid) {
        int n = piles.length;
        int ret = 0;
        for (int i = 0; i < n; i++) {
            ret += (piles[i] + mid - 1) / mid;
        }
        return ret <= h;
    }

    public int minEatingSpeed(int[] piles, int h) {
        int n = piles.length;
        int l = 0, r = 0x3f3f3f3f;
        while (l < r) {
            int mid = (l + r) >>> 1;
            if (check(piles, h, mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return r;
    }
}