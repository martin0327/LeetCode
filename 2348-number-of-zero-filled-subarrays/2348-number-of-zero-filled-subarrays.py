class Solution:
    def zeroFilledSubarray(self, a: List[int]) -> int:
        n = len(a)
        for i in range(n):
            a[i] = abs(a[i])
        pre = [0]
        for i in range(n):
            pre.append(pre[-1] + a[i])
        d = defaultdict(int)
        ans = 0
        for x in pre:
            ans += d[x]
            d[x] += 1
            
        return ans