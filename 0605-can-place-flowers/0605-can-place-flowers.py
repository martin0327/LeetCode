class Solution:
  def canPlaceFlowers(self, a: List[int], k: int) -> bool:
    a = [0] + a + [0]
    for i in range(1,len(a)-1):  
      if sum(a[i+j] for j in [-1,0,1]) == 0:
        a[i] = 1
        k -= 1
    return k <= 0          