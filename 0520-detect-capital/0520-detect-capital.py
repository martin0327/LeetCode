class Solution:
    def detectCapitalUse(self, s: str) -> bool:
        return s.isupper() or s.islower() or s==s.capitalize()