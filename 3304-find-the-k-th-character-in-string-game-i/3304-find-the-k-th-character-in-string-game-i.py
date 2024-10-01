class Solution:
    def kthCharacter(self, k: int) -> str:
        s = "a"
        while len(s) < k:
            n = len(s) 
            for i in range(n):
                x = ord(s[i]) - ord('a')
                x = (x+1) % 26 
                s += chr(x + ord('a'))
        return s[k-1]