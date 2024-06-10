class Solution:
    def heightChecker(self, a: List[int]) -> int:
        return sum(x!=y for x,y in zip(a,sorted(a)))