class Solution:
    def numDupDigitsAtMostN(self, n: int) -> int:
        def cal(n: int):
            s = str(n)
            @cache
            def dfs(i: int, sta: int, islimit: bool, isnum: bool) -> int:
                # isnum: 前边是否填了数 islimit: 是否受到n 的限制
                if (i == len(s)):
                    return int(isnum)
                res = 0
                if (not isnum):
                    res += dfs(i + 1, sta, False, False)
                low = 0 if (isnum) else 1
                up = int(s[i]) if islimit else 9
                for d in range(low, up + 1):
                    if (((sta >> d) & 1) == 0):
                        f = dfs(i + 1, sta | (1 << d), islimit and d == up, True)
                        res += f
                return res

            return dfs(0, 0, True, False)

        return n - cal(n)