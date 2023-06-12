class Solution:
    def summaryRanges(self, a: List[int]) -> List[str]:
        if not a:
          return []
        b = []
        c = []
        for x in a:
          if not b:
            b.append(x)
          else:
            if b[-1] == x-1:
              b.append(x)
            else:
              c.append(b)
              b = [x]
        c.append(b)
        ans = []
        for b in c:
          if len(b)==1:
            ans.append(str(b[0]))
          else:
            ans.append("{}->{}".format(b[0],b[-1]))
        return ans