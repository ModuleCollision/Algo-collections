class Solution:
    def minOperations(self, nums: List[int], target: int) -> int:
        cnt = [0 for _ in range(33)]
        sum = 0
        for c in nums:
            sum += c
            w = 0;
            while(c >> w):
                w += 1
            w -= 1;
            cnt[w] += 1
        ans = 0
        if(sum < target):
            return -1;
        for i in range(31):
            if((target >> i) & 1):
                if(not cnt[i]):
                    for j in range(i + 1, 31):
                        if(cnt[j]):
                            cnt[j] -= 1
                            for k in range(i, j):
                                cnt[k] += 1
                            ans += j - i;
                            break;
                cnt[i] -= 1;

            if(i < 30):
                cnt[i + 1] += cnt[i] // 2
        return ans;

            