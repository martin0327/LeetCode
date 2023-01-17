class Solution:
    def takeCharacters(self, s: str, k: int) -> int:
        n = len(s)
        pre = [[0] * 3 for _ in range(n + 1)]

        for i, c in enumerate(s):
            pre[i + 1][0], pre[i + 1][1], pre[i + 1][2] = pre[i][0], pre[i][1], pre[i][2]
            pre[i + 1][ord(c) - ord('a')] += 1

        ans = -1
        lo, hi = 0, n

        while lo <= hi:
            mid = (lo+hi) // 2
            ok = False
            for i in range(mid+1):
                flag = True
                for j in range(3):
                    flag &= pre[i][j] + pre[n][j] - pre[n-mid+i][j] >= k
                if flag:
                    ok = True
                    break
            if ok:
                ans = mid
                hi = mid - 1
            else:
                lo = mid + 1
        
        return ans