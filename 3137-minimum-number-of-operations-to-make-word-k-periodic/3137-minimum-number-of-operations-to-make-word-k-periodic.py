class Solution:
    def minimumOperationsToMakeKPeriodic(self, s: str, k: int) -> int:
        return len(s)//k - max(Counter(s[i:i+k] for i in range(0,len(s),k)).values())
        