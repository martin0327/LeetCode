class Solution:
  def sequentialDigits(self, low: int, high: int) -> List[int]:
    a = []
    for i in range(1,10):
      s = str(i)
      a.append(s)
      while True:
        x = int(s[-1])
        if x == 9: break
        s += str(x+1)
        a.append(s)
    ret = []
    for x in a:
      x = int(x)
      if low <= x and x <= high:
        ret.append(x)
    return sorted(ret)
    
        