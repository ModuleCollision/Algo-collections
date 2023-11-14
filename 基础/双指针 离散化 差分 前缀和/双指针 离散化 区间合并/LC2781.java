import java.util.*;

class Solution {
    public int longestValidSubstring(String word, List<String> forbidden) {
        var fb = new HashSet<Integer>();
        for (var f :
                forbidden) {
            fb.add(f.hashCode());
        }
        int n = word.length();
        int ans = 0, left = 0;
        for (int right = 0; right < n; right++) {
            for (int i = right; i >= left && i >= right - 9; i--) {
                if (fb.contains(word.substring(i, right + 1).hashCode())) {
                    left = i + 1;
                    break;
                }
            }
            ans = Math.max(ans, right - left + 1);
        }
        return ans;
    }
};