class Solution:
    def maxIncreasingGroups(self, usageLimits: List[int]) -> int:
        n = len(usageLimits)
        sorted(usageLimits, key = lambda x: x, reverse = True)

        def check(x: int) -> bool:
            d = 0
            for i in range(n):

                if (usageLimits[i] >= max(0, x - i)):
                    if (d < 0):
                        d += usageLimits[i] - max(x - i, 0)
                else:
                    d -= x - i - usageLimits[i]
            return d >= 0

        l = 1;
        r = n
        while (l < r):
            mid = (l + r + 1) // 2
            if (check(mid)):
                l = mid
            else:
                r = mid - 1
        return l
