class Solution:
    def isItPossible(self, s: str, t: str) -> bool:
        c1 = Counter(s)
        c2 = Counter(t)
        l1 = len(c1)
        l2 = len(c2)
        for x, y in c1.items():
          for z, w in c2.items():
            if x == z:
              if l1 == l2: return True
            else:
              t1 = l1
              t2 = l2
              t1 += (z not in c1) - (y==1)
              t2 += (x not in c2) - (w==1)
              if t1 == t2: return True
        return False