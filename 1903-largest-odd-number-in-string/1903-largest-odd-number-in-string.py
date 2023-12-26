class Solution:
    def largestOddNumber(self, num: str) -> str:
        # for i,c in reversed(list(enumerate(num))):
        for i in range(len(num)-1,-1,-1):
            if (int(num[i])&1): return num[:i+1]
        return "" 