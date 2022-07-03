class Solution:
  def reconstructQueue(self, a: List[List[int]]) -> List[List[int]]:
    a.sort(key = lambda x : (-x[0], x[1]))
    ans = []
    for x,y in a:
      ans = ans[:y] + [(x,y)] + ans[y:]
    return ans