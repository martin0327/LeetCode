class Solution:
    def champagneTower(self, x: int, qi: int, qj: int) -> float:
        n = qi+1
        dp = [[0]*n for _ in range(n)]
        if n==1:
            if x>=1: return 1
            else: return 0
        
        dp[0][0] = x
        for i in range(1,n):
            for j in range(n):
                if j>=1 and dp[i-1][j-1] > 1:
                    dp[i][j] += (dp[i-1][j-1] -1 ) / 2
                if j<=i and dp[i-1][j] > 1:
                    dp[i][j] += (dp[i-1][j]-1) / 2
        
        ans = dp[qi][qj]
        if ans >= 1: ans = 1
        return ans