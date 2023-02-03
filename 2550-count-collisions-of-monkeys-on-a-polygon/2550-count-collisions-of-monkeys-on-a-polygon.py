class Solution:
    def monkeyMove(self, n: int) -> int:
        m = int(1e9+7)
        return (pow(2,n,m) - 2) % m