class Solution:
    def countCompleteDayPairs(self, a: List[int]) -> int:
        ans = 0
        mod = 24
        d = defaultdict(int)
        for x in a:
            ans += d[(mod-x)%mod] 
            d[x%mod] += 1
        return ans