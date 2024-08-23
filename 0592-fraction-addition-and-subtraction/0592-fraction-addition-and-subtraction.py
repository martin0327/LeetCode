from fractions import Fraction
class Solution:
    def fractionAddition(self, s: str) -> str:
        s = s.replace('-', '+-').split('+')
        s = [map(int,x.split('/')) for x in s if len(x) > 1]
        s = sum(Fraction(x,y) for x,y in s)
        return "{}/{}".format(s.numerator,s.denominator)