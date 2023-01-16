class Solution:
    def countKDifference(self, a: List[int], k: int) -> int:
        d = dict()
        ans = 0
        for x in a:
          if k + x in d:
            ans += d[k+x]
          if x - k in d:
            ans += d[x-k]
          if x in d:
            d[x] += 1
          else:
            d[x] = 1
        return ans