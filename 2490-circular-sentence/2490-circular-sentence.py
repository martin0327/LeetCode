class Solution:
    def isCircularSentence(self, s: str) -> bool:
        a = s.split()
        n = len(a)
        ok = True
        for i in range(n):
            x = a[i]
            y = a[(i+1)%n]
            if x[-1] != y[0]: ok = False
        return ok