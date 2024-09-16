class Solution:
    def findMinDifference(self, a: List[str]) -> int:
        c = []
        for x in a:
            b = [int(y) for y in x.split(':')]
            z = 60*b[0] + b[1] 
            c.append(z)
        c.sort()
        d = [x-c[i-1] for i,x in enumerate(c)]
        return min(min(abs(x),abs(x-24*60),abs(x+24*60)) for x in d)