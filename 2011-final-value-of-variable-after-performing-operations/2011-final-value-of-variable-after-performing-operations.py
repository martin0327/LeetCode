class Solution:
    def finalValueAfterOperations(self, a: List[str]) -> int:
        return sum(1 if '+' in x else -1 for x in a)