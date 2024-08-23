import re
from fractions import Fraction
class Solution:
    def fractionAddition(self, s: str) -> str:
        s = s.replace('-', '+-')
        s = s.split('+')
        s = [x.split('/') for x in s if len(x) > 1]
        s = [Fraction(int(x),int(y)) for x,y in s]
        # for x in s:
        #     if len(x) > 1:
        #         a.append(Fraction(int(x[0]),int(x[1])))
        s = sum(s)
        return "{}/{}".format(s.numerator,s.denominator)