class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        a = s.split()
        n = len(pattern)
        m = len(a)
        if n != m: return False
        
        d1 = dict()
        d2 = dict()
        for i in range(n):
          c = pattern[i]
          b = a[i]
          if c in d1:
            if d1[c] != b:
              return False
          else:
            d1[c] = b
          
          if b in d2:
            if d2[b] != c:
              return False
          else:
            d2[b] = c
          
        return True