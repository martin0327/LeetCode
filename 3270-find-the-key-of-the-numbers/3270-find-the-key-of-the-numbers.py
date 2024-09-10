class Solution:
    def generateKey(self, x: int, y: int, z: int) -> int:
        a = list(map(str, [x,y,z]))
        n = min(map(len,a)) 
        return int((''.join(min(s[-(i+1)] for s in a) for i in range(n)))[::-1])