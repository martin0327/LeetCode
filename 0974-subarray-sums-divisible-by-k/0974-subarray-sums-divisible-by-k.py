class Solution:
    def subarraysDivByK(self, a: List[int], k: int) -> int:
        return sum(y*(y-1)//2 for y in Counter(x%k for x in accumulate([0] + a)).values())