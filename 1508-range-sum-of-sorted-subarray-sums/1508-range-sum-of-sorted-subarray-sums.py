class Solution:
    def rangeSum(self, nums: List[int], n: int, left: int, right: int) -> int:
        mod = int(1e9+7)
        n = len(nums)
        pre = [0] * (n+1)
        for i in range(1,n+1):
            pre[i] = pre[i-1] + nums[i-1]
        all_sums = [pre[j] - pre[i] for i in range(n) for j in range(i+1,n+1)]
        all_sums.sort()
        return sum(all_sums[left-1:right])%mod