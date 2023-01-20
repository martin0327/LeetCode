class Solution:
    def maxFrequency(self, a: List[int], k: int) -> int:
        n = len(a)
        a.sort()
        a = [0] + a
        pre = list(accumulate(a))
        ans = 1
        
        for i in range(1, n+1):
            x = a[i]
            lo = 0
            hi = i
            idx = -1
            while lo <= hi:
                mid = (lo+hi)//2
                cnt = i - mid
                s = pre[i] - pre[mid]
                if x*cnt - s <= k:
                    idx = mid
                    hi = mid - 1
                else: lo = mid + 1
            if idx != -1: ans = max(ans, i-idx)
        return ans