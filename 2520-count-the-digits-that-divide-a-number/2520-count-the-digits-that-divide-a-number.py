class Solution:
    def countDigits(self, x: int) -> int:
        ans = 0
        for c in str(x):
          if x % int(c) == 0: ans += 1
        return ans