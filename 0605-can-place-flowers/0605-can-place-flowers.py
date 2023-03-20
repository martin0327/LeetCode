class Solution:
  def canPlaceFlowers(self, a: List[int], k: int) -> bool:
    n = len(a)
    a = [0] + a + [0]
    for i in range(1,n+1):  
      if sum(a[i+j] for j in range(-1,2)) == 0:
        a[i] = 1
        k -= 1
    return k <= 0
          
                   
          