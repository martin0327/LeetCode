class Solution:
  def maxSubArray(self, a: List[int]) -> int:
    n = len(a)
    pre = list(accumulate([0] + a))
    premin = pre[:] 
    for i in range(1, n+1): premin[i] = min(premin[i], premin[i-1])
    # print(pre)
    # print(premin)
    ans = max(pre[i]-premin[i-1] for i in range(1,n+1))
    return ans