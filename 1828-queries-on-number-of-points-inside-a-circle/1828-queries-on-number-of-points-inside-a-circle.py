class Solution:
    def countPoints(self, pt: List[List[int]], qr: List[List[int]]) -> List[int]:
        def sq(x): return x*x
        ret = []
        for x1,y1,r in qr:
          cnt = 0
          for x2,y2 in pt:
            if sq(x1-x2) + sq(y1-y2) <= r*r: cnt += 1
          ret.append(cnt)
        return ret
          
        