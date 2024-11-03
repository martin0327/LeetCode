class Solution:
    def rotateString(self, s: str, t: str) -> bool:
        n = len(s)
        s = s + s
        for i in range(n):
            if t == s[i:(i+n)]: return True
        return False
        