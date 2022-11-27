class Solution:
  def numberOfArithmeticSlices(self, a: List[int]) -> int:
    n = len(a)
    mp = defaultdict(list)
    for i in range(n):
      for j in range(i+1,n):
        d = a[j] - a[i]
        mp[d].append((i,j))
    ans = 0
    for d, b in mp.items():
      dp = dict()
      for u,v in b:
        if u not in dp:
          dp[u] = [1,0,0]
        if v not in dp:
          dp[v] = [1,0,0]
        for j in range(3):
          dp[v][min(j+1,2)] += dp[u][j]
      for val in dp.values():
        ans += val[2]
    return ans