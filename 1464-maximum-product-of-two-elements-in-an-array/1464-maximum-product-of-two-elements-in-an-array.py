class Solution:
    def maxProduct(self, a: List[int]) -> int:
        # a.sort(reverse=True)
        # return (a[0]-1)*(a[1]-1)
        mx,mx2 = 0,0
        for x in a:
            if x > mx:
                mx2 = mx
                mx = x
            elif x > mx2:
                mx2 = x
        return (mx-1) * (mx2-1)
        