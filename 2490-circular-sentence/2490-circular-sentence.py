class Solution:
    def isCircularSentence(self, s: str) -> bool:
        a = s.split()
        n = len(a)
        for i in range(n):
            x, y = a[i], a[(i+1)%n]
            if x[-1] != y[0]: return False
        return True