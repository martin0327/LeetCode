class Solution:
  def maxSubArray(self, a: List[int]) -> int:
    n = len(a)
    pre = list(accumulate([0] + a))
    ans, m = pre[1], pre[0]
    for i in range(1,n+1):
      ans = max(ans, pre[i]-m)
      m = min(m, pre[i])
    return ans