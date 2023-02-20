class Solution:
    def minimumAbsDifference(self, a: List[int]) -> List[List[int]]:
        a.sort()
        n = len(a)
        min_d = int(1e7)
        ret = []
        for i in range(1,n):
            d = a[i] - a[i-1]
            if min_d > d:
                min_d = d
                ret = [[a[i-1],a[i]]]
            elif min_d == d:
                ret.append([a[i-1],a[i]])
        return ret