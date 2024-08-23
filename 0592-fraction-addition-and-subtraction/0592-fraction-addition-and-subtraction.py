from fractions import Fraction
class Solution:
    def fractionAddition(self, s: str) -> str:
        s = sum(Fraction(x) for x in s.replace('-', '+-').split('+') if x)
        return f"{s.numerator}/{s.denominator}"