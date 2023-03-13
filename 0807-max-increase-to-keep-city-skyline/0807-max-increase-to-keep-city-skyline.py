class Solution:
    def maxIncreaseKeepingSkyline(self, a: List[List[int]]) -> int:
        n = len(a)
        r = [max(a[i][j] for j in range(n)) for i in range(n)]
        c = [max(a[i][j] for i in range(n)) for j in range(n)]
        return sum(min(r[i],c[j])-a[i][j] for i in range(n) for j in range(n))