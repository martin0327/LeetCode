class Solution:
    def finalPrices(self, a: List[int]) -> List[int]:
        n = len(a)
        ret = [-1] * n
        b = []
        for i in range(n):
            while b and a[i] <= a[b[-1]]:
                ret[b[-1]] = a[b[-1]] - a[i]
                b.pop()
            b.append(i)
        for i in range(n):
            if ret[i] == -1:
                ret[i] = a[i]
        return ret