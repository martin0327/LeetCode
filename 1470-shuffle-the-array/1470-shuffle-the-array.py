class Solution:
    def shuffle(self, a: List[int], n: int) -> List[int]:
        return list(chain(*zip(a[:n], a[n:])))    