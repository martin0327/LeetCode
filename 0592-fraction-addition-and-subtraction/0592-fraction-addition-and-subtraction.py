from fractions import Fraction
class Solution:
    def fractionAddition(self, s: str) -> str:
        s = sum(Fraction(x) for x in s.replace('-', '+-').split('+') if len(x) > 1)
        return "{}/{}".format(s.numerator,s.denominator)