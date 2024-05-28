class Solution:
    def numberOfPairs(self, a: List[int], b: List[int], k: int) -> int:
        return sum((x % (y*k) == 0) for x in a for y in b)