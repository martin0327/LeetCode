class Solution:
    def addDigits(self, x: int) -> int:
        while True:
          s = str(x)
          if len(s) == 1: return x
          x = sum(map(int, list(s)))