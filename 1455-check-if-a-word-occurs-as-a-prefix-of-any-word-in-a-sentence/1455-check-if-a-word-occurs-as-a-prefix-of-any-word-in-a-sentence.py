class Solution:
    def isPrefixOfWord(self, a: str, x: str) -> int:
        m = len(x)
        for i,y in enumerate(a.split()):
            if len(y) >= m and y[:m] == x:
                return i+1
        return -1