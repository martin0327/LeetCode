class Solution:
    def shiftGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
        n = len(grid)
        m = len(grid[0])
        a = []
        k %= n*m
        for row in grid:
            a = a + row
        a = a[-k:] + a[:-k]
        ret = []
        for i in range(n):
            ret.append(a[(i*m):(i+1)*m])
        return ret
        