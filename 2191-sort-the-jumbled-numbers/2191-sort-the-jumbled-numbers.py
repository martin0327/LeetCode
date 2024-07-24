class Solution:
    def sortJumbled(self, mapping: List[int], nums: List[int]) -> List[int]:
        n = len(nums)
        b = []
        for x in nums:
            y = ""
            for c in list(str(x)):
                y += str(mapping[int(c)])
            b.append(int(y))
        # print(b)
        c = [0] * n
        for i in range(len(nums)):
            c[i] = (b[i],i,nums[i])
        c.sort()
        ans = []
        for x,y,z in c:
            ans.append(z)
        return ans
        