class Solution:
    def maxCount(self, m: int, n: int, ops: List[List[int]]) -> int:
        if ops:
            x, y = min([a for a,b in ops]), min([b for a,b in ops])
            return x*y
        else:
            return m*n