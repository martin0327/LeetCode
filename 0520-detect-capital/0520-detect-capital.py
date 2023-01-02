class Solution:
    def detectCapitalUse(self, s: str) -> bool:
        return s.isupper() or s==s.lower() or s==s.capitalize()