class Solution:
    def maxScore(self, s: str) -> int:
        n = len(s)
        pre = [0] * (n+1)
        for i in range(n):
            pre[i+1] = pre[i] + int(s[i])
        tot = pre[n]
        ans = 0
        for i in range(1,n):
            ans = max(ans, i - pre[i] + tot - pre[i])
        return ans