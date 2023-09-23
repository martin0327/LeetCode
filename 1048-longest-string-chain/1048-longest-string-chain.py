class Solution:
    def longestStrChain(self, a: List[str]) -> int:
        dp = dict()
        for x in sorted(a, key = len):
            dp[x] = max(dp.get(x[:i] + x[(i+1):],0) + 1 for i in range(len(x)))
        return max(dp.values())
            