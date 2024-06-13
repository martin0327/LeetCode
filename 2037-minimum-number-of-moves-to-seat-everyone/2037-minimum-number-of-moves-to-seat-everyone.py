class Solution:
    def minMovesToSeat(self, a: List[int], b: List[int]) -> int:
        return sum(abs(x-y) for x,y in zip(sorted(a), sorted(b)))