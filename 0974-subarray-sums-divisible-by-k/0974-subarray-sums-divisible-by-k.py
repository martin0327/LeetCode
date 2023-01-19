class Solution:
    def subarraysDivByK(self, a: List[int], k: int) -> int:
        pr = accumulate([0] + a)
        dd = defaultdict(int)
        ans = 0
        for x in pr:
            y = ((x%k)+k)%k
            ans += dd[y]
            dd[y] += 1
        return ans