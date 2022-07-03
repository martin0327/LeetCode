class Solution:
    def minPartitions(self, n: str) -> int:
        return max(int(c) for c in n)