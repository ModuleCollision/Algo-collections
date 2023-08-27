from sortedcontainers import SortedList
from collections import Counter


class Solution:
    def sumImbalanceNumbers(self, nums: List[int]) -> int:
        n = len(nums);
        ans = 0;
        for i in range(0, n):
            s = SortedList();
            s.add(nums[i]);
            cnt = 0
            for j in range(i + 1, n):
                if (not s.count(nums[j])):
                    f1 = s.count(nums[j] - 1);
                    f2 = s.count(nums[j] + 1);
                    if (f1 and f2):
                        cnt -= 1
                    elif(( not f1) and ( not f2)):
                        cnt += 1
                    s.add(nums[j])
                ans += cnt

        return ans