class Solution:
    def maximumTastiness(self, price: List[int], k: int) -> int:
        lo, hi = 0, 1e9
        n = len(price)
        ans = -1
        price.sort()
        while lo <= hi:
            mid = (lo + hi) // 2
            curr = price[0]
            cnt = 1
            for i in range(1, n):
                if (price[i] - curr) >= mid:
                    curr = price[i]
                    cnt += 1
            if cnt >= k:
                ans = mid
                lo = mid + 1
            else:
                hi = mid - 1
        return int(ans)