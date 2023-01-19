class Solution:
    def subarraysDivByK(self, a: List[int], k: int) -> int:
        pr = accumulate([0] + a)
        dd = defaultdict(int)
        ans = 0
        for x in pr:
            ans += dd[x%k]
            dd[x%k] += 1
        return ans