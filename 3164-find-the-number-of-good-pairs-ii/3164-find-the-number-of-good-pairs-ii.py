class Solution:
    def numberOfPairs(self, a: List[int], b: List[int], k: int) -> int:
        cnt = [0] * int(1e6+1) 
        for x in b: cnt[x] += 1 
            
        ans = 0 
        for x, c in Counter(a).items():
            for d in range(1,x+1):
                if d * d > x : break 
                
                if x % d == 0:
                    y, z = d, x // d
                    if y % k == 0: ans += cnt[y//k]*c 
                    if z % k == 0 and z != y: ans += cnt[z//k]*c
        return ans