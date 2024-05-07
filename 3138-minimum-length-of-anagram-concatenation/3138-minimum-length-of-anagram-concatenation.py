class Solution:
    def minAnagramLength(self, s: str) -> int:
        n = len(s)
        i = 1
        ans = n
        while i*i <= n:
            if n % i == 0:
                m1 = i 
                m2 = n // i 
                def f(m): return len(set([''.join(sorted(s[j:j+m])) for j in range(0,n,m)])) == 1 
                if f(m1): ans = min(ans, m1) 
                if f(m2): ans = min(ans, m2) 
            i += 1
        return ans