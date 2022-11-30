class Solution:
    def uniqueOccurrences(self, a: List[int]) -> bool:
        c = Counter(a)
        return len(set(c.values())) == len(c)