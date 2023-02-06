class Solution:
  def maxSubArray(self, a: List[int]) -> int:
    cur, ans = a[0], a[0]
    for x in a[1:]:
      cur = max(x, cur + x)
      ans = max(ans, cur)
    return ans