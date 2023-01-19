class Solution:
    def isItPossible(self, s: str, t: str) -> bool:
        c1 = Counter(s)
        c2 = Counter(t)
        for x, y in c1.items():
          for z, w in c2.items():
            l1 = len(c1)
            l2 = len(c2)
            l1 += (z not in c1) - (y==1 and x != z)
            l2 += (x not in c2) - (w==1 and x != z)
            if l1 == l2: return True
        return False