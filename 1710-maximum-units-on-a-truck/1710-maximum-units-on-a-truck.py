class Solution:
    def maximumUnits(self, a: List[List[int]], k: int) -> int:
        a.sort(key = lambda x : -x[1])
        ans = 0
        for x,y in a:
            cnt = min(k,x)
            k -= cnt
            ans += y * cnt
            if k==0: break
        return ans