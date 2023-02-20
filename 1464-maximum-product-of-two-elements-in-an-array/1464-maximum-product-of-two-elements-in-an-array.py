class Solution:
    def maxProduct(self, a: List[int]) -> int:
        a.sort(reverse=True)
        return (a[0]-1)*(a[1]-1)