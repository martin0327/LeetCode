class Solution:
    def firstPalindrome(self, a: List[str]) -> str:
        for x in a: 
            if x == x[::-1]: return x
        else: return ""
        