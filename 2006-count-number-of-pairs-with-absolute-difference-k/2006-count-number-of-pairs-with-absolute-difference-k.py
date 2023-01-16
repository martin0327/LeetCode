class Solution:
    def countKDifference(self, a: List[int], k: int) -> int:
        cnt = [0 for i in range(101)] 
        ans = 0 
        for x in a:
          if x+k <= 100: ans += cnt[k+x]
          if x-k > 0: ans += cnt[x-k]
          cnt[x] += 1
        return ans
      