class Solution:
  def canPlaceFlowers(self, a: List[int], k: int) -> bool:
    cnt = 0
    n = len(a)
    a = [0] + a + [0]


    for i in range(1,n+1):  
      if reduce(lambda x,y : x|y, [a[i+j] for j in range(-1,2)]) == 0:
        a[i] = 1
        cnt += 1
    return cnt >= k
          
                   
          