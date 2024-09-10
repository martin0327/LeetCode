class Solution:
    def convertDateToBinary(self, d: str) -> str:
        return '-'.join(bin(int(x))[2:] for x in map(str, d.split('-')))