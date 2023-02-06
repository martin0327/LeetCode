class Solution:
    def shuffle(self, a: List[int], n: int) -> List[int]:
        return list(chain(*[[x,y] for x,y in (zip(a[:n], a[n:]))]))