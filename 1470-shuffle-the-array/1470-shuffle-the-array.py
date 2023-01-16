class Solution:
    def shuffle(self, a: List[int], n: int) -> List[int]:
        ret = []
        for i in range(n):
            ret.append(a[i])
            ret.append(a[i+n])
        return ret