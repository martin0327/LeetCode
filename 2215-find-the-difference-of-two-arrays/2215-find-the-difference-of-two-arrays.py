class Solution:
    def findDifference(self, a: List[int], b: List[int]) -> List[List[int]]:
        a, b = set(a), set(b)
        return [list(a.difference(b)), list(b.difference(a))]