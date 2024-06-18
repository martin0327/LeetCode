class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        return any(i**2+isqrt(c-i*i)**2==c for i in range(isqrt(c)+1))