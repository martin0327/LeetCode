class Solution:
    def nthUglyNumber(self, n: int) -> int:
        lst = []
        for i in range(31):
            for j in range(20):
                for k in range(14):
                    lst.append((2**i) * (3**j) * (5**k))
        lst.sort()
        return lst[n-1]