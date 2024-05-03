class Solution:
    def compareVersion(self, a: str, b: str) -> int:
        a = list(map(int, a.split('.')))
        b = list(map(int, b.split('.')))

        n = max(len(a),len(b))
        while len(a) < n: a.append(0)
        while len(b) < n: b.append(0)
          
        if a < b: return -1
        elif a > b: return 1
        else: return 0
        
        
          
          
        
      