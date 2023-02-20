class Solution:
    def maxProduct(self, a: List[int]) -> int:
        # a.sort(reverse=True) # O(nlogn) 
        # # python sort is called Tim-sort (combination of merge sort and quicksort)
        # return (a[0]-1)*(a[1]-1)
        # # mx,mx2 = 0,0
        # # for x in a: # O(n)
        # #     if x > mx:
        # #         mx2 = mx
        # #         mx = x
        # #     elif x > mx2:
        # #         mx2 = x
        # return (mx-1) * (mx2-1) 
        n = len(a)
        ans = 0
        for i in range(n): # 0 ~ n-1
            for j in range(i+1,n): # i+1 ~ n-1
                ans = max(ans, (a[i]-1) * (a[j]-1))
        return ans
    
    
#     suppose n = 2e5 will (O(nlogn) will pass?)
    