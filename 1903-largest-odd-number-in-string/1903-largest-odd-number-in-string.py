class Solution:
    def largestOddNumber(self, num: str) -> str:
        for i,c in reversed(list(enumerate(num))):
            if (int(c)&1): return num[:i+1]
        return "" 