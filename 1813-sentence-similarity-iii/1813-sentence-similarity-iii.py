class Solution:
    def areSentencesSimilar(self, s: str, t: str) -> bool:
        a = s.split()
        b = t.split()
        if len(a) < len(b):
            a, b = b, a
        n, m = len(a), len(b)
        # print(a,b)
        for i in range(n+1):
            if i >= m: break
            c = a[:i] + a[-(m-i):]
            if c == b: return True
            d = a[:(m-(i))] + (a[-(m-i):] if i > 0 else [])
            # print(c,d)
            if d == b: return True
            
        return False