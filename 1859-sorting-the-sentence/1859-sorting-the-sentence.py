class Solution:
    def sortSentence(self, s: str) -> str:
        return ' '.join([y for x,y in sorted([(x[-1], x[:-1]) for x in s.split()])])