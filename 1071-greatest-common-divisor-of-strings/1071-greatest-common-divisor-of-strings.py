class Solution:
    def gcdOfStrings(self, s: str, t: str) -> str:
        n = len(s)
        m = len(t)
        ans = ""
        for i in range(1, n+1):
          if n % i == 0 and m % i == 0:
            q1 = n // i
            q2 = m // i
            ss = s[:i]
            tt = s[:i]
            if ss == tt and s == ss * q1 and t == tt * q2:
              ans = ss
        return ans